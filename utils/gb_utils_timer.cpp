
#include "gb_utils_timer.h"
#include <cmath>


void get_time(timespec *ts)
{
#ifdef __MACH__ // OS X does not have clock_gettime, use clock_get_time
	clock_serv_t cclock;
	mach_timespec_t mts;
	host_get_clock_service(mach_host_self(), CALENDAR_CLOCK, &cclock);
	clock_get_time(cclock, &mts);
	mach_port_deallocate(mach_task_self(), cclock);
	ts->tv_sec = mts.tv_sec;
	ts->tv_nsec = mts.tv_nsec;

#else
	clock_gettime(CLOCK_MONOTONIC, ts);
#endif
}


/* GBTime implementation */
double GBTime::millis() const
{
	double t = pow(10.0, 3) * ts.tv_sec + pow(10.0, -6) * ts.tv_nsec;
	return t;
}

double GBTime::seconds() const
{
	double t = ts.tv_sec + pow(10.0, -9) * ts.tv_nsec;
	return t;
}

GBTime operator+ (GBTime const& t1, GBTime const& t2)
{
	GBTime dst;

	dst.ts.tv_sec = t1.ts.tv_sec + t2.ts.tv_sec;
	dst.ts.tv_nsec = t1.ts.tv_nsec + t2.ts.tv_nsec;
	return dst;
}

GBTime operator- (GBTime const& t1, GBTime const& t2)
{
	GBTime dst;

	dst.ts.tv_sec = t1.ts.tv_sec - t2.ts.tv_sec;
	dst.ts.tv_nsec = t1.ts.tv_nsec - t2.ts.tv_nsec;
	return dst;

}  

// Output operator
ostream& operator<<(ostream& os, const GBTime& dst)
{
	os << "<GBTime milliseconds: " << dst.millis() << ">";
	return os;
}


/* GBTimer implementation */

void GBTimer::start()
{
	if (in_progress)
	{
		throw string("Timer is already in progress");
	}

	in_progress = true;
	has_run = true;
	GBTime dst;
	ts1 = dst;
	return;
}

void GBTimer::stop()
{
	if (!in_progress)
	{
		throw string("Stopping a stopped timer");
	}

	in_progress = false;
	GBTime dst;
	ts2 = dst;
	return;
}

GBTime GBTimer::elapsed() const
{
	GBTime elapsed;

	if (!has_run)
	{
		throw string("Timer has never been run");
	}

	if (in_progress)
	{
		GBTime dst;
		elapsed = dst - ts1;
	}
	else
	{
		elapsed = ts2 - ts1;

	}
	return elapsed;
}

double GBTimer::millis() const
{
	return elapsed().millis();
}

double GBTimer::seconds() const
{
	return elapsed().seconds();
}

// Output operator
ostream& operator<<(ostream& os, const GBTimer& dst)
{
	if (dst.has_run)
	{
		os << "<GBTimer: " << dst.elapsed() << " >"; 
	}
	else
	{
		os << "<GBTimer: Never been run>";
	}
	
	return os;
}