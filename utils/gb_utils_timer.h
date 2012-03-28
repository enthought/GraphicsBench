#ifndef _gb_utils_timer_h_
#define _gb_utils_timer_h_

#include <sys/time.h>

#ifdef __MACH__
#include <mach/clock.h>
#include <mach/mach.h>
#endif

#include <iostream>
using namespace std;


void get_time(timespec *ts);
	


class GBTime {
	/*
		struct timespec {
        time_t   tv_sec;        // seconds
        long     tv_nsec;       // nanoseconds
		};

		supported clocks:

		CLOCK_REALTIME
	    	System-wide realtime clock. Setting this clock requires appropriate privileges. 
		CLOCK_MONOTONIC
		    Clock that cannot be set and represents monotonic time since some unspecified starting point. 
		CLOCK_PROCESS_CPUTIME_ID
		    High-resolution per-process timer from the CPU. 
		CLOCK_THREAD_CPUTIME_ID
		    Thread-specific CPU-time clock. 
	*/
public:
	timespec ts;
	GBTime()
	{
		get_time(&ts);
	}

	double millis() const;
	double seconds() const;

	friend GBTime operator+ (GBTime const& t1, GBTime const& t2);
	friend GBTime operator- (GBTime const& t1, GBTime const& t2);

	// Output operator
	friend ostream& operator<<(ostream& os, const GBTime& dst);  
};


class GBTimer {
private:
	GBTime ts1, ts2, timedelta;
	bool in_progress;
	bool has_run;
public:
	GBTimer()
	{
		in_progress = false;
		has_run = false;
	}
	void start();
	void stop(); 
	GBTime elapsed() const;
	double millis() const;
	double seconds() const;

	// Output operator
	friend ostream& operator<<(ostream& os, const GBTimer& dst);  
};

#endif