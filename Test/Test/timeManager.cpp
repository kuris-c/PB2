#include "prepro.h"

/*ACTIVE TIME INTS*/int day, hour, min;
/*STRING TIME FOR COUT*/std::string sday, shour, smin;
/*CUMULATIVE INTS FOR END SCREEN*/int cday, chour, cmin;

//Player Setting For 12 or 24 Hour Clock
bool tfhourclock;

void checkTime()
{
	tfhourclock = true;

	switch (day)
	{
	case 1:
		sday = "Monday";
		break;
	case 2:
		sday = "Tuesday";
		break;
	case 3:
		sday = "Wednesday";
		break;
	case 4:
		sday = "Thursday";
		break;
	case 5:
		sday = "Friday";
		break;
	case 6:
		sday = "Saturday";
		break;
	case 7:
		sday = "Sunday";
		break;
	}

	if (tfhourclock)
	{
		shour = std::to_string(hour);
		smin = std::to_string(min);

		if (min < 10)
		{
			smin = "0" + smin;
		}

		if (hour < 12)
		{
			shour = "0" + std::to_string(hour);
		}
	}

	if (!tfhourclock)
	{

	}
}

void addDay(int days)
{
	cday += days;
	day += days;

	if (tfhourclock)
	{
		while (day > 7)
		{
			day -= 7;
		}
	}
}

void addHour(int hours)
{
	chour += hours;
	hour += hours;

	if (tfhourclock)
	{
		while (hour > 24)
		{
			hour -= 24;
			addDay(1);
		}
	}
}

void addMin(int mins)
{
	cmin += mins;
	min += mins;

	if (tfhourclock)
	{
		while (min > 60)
		{
			min -= 60;
			addHour(1);
		}
	}
}

void displayTime()
{
	checkTime();

	if (tfhourclock)
	{
		std::cout << sday << " " << shour << ":" << smin << "\n\n";
	}

	else if (!tfhourclock)
	{

	}
}