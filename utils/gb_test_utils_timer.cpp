#include "gb_utils_timer.h"
#include "sys/time.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char**argv)
{
	GBTime dst;
	GBTimer gbt;
	try{
		gbt.start();
		sleep(2);
		std::cout << gbt.millis() << "\n";
	}
	catch (std::string s)
	{
		cout << s << "\n";
	}
	return 54;
}