#include "Clock.h"

Clock::Clock(int startyear, int startmonth, int startday, int starthour, int startminute, int startweekday)
    : year{startyear}, month{startmonth}, day{startday}, hour{starthour}, minute{startminute}, weekday{startweekday} {}

int Clock::update()
{

    minute++;
    if (minute >= 60)
    {
        minute = 0;
        hour++;

        if (hour >= 24)
        {
            hour = 0;
            day++;

            advanceWeekday();

            if (day >= 31)
            {
                day = 0;
                month++;

                if (month >= 13)
                {
                    month = 0;
                    year++;
                }
            }
        }
    }
}

int Clock::getYear() const
{
    return year;
}

int Clock::getMonth() const
{
    return month;
}

int Clock::getDay() const
{
    return day;
}

int Clock::getHour() const
{
    return hour;
}

int Clock::getMinute() const
{
    return minute;
}

Weekday Clock::getWeekday() const
{
    return weekday;
}

void Clock::advanceWeekday()
{

    switch (weekday)
    {

    case Weekday::MON:
        weekday = Weekday::TUE;
        break;

    case Weekday::TUE:
        weekday = Weekday::WED;
        break;

    case Weekday::WED:
        weekday = Weekday::THU;
        break;

    case Weekday::THU:
        weekday = Weekday::FRI;
        break;

    case Weekday::FRI:
        weekday = Weekday::SAT;
        break;

    case Weekday::SAT:
        weekday = Weekday::SUN;
        break;

    case Weekday::SUN:
        weekday = Weekday::MON;
        break;
    }
