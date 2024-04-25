#ifndef HEADER_H_CLOCK
#define HEADER_H_CLOCK

enum class Weekday {

    MON,
    TUE,
    WED,
    THU,
    FRI,
    SAT,
    SUN
};

class Clock {

    int year;
    int month;
    int day;
    int hour;
    int minute;
    Weekday weekday;

    public: 
    
    Clock(int startyear, int startmonth, int startday, int starthour, int startminute, int startweekday);

    int update();

    int getYear() const;

    int getMonth() const;

    int getDay() const;

    int getHour() const;

    int getMinute() const;

    Weekday getWeekday() const;

    private:

    void advanceWeekday();

};

#endif