#ifndef HEADER_H_STATE
#define HEADER_H_STATE

#include <vector>

#include "../farm/Soil.h"

class Time {

    public:

        Time(const int day, const int hour, const int minutes);
        Time timeSince(const Time &pastTime) const;
        void tick();

    private:

        int day;
        int hour;
        int minutes;

};

class GameClock {

    public:
        GameClock();
        GameClock(const Time &time);
        GameClock(const int day, const int hour, const int minutes);
        void tick();
        Time getTime() const;

    private:
        Time currentTime;

};

struct State {

    //int chaosChange;
    //int chaosLevel;

    //int growthChange;
    //int growthLevel;

    //int progressChange;
    //int progressLevel;

    //int orderChange;
    //int orderLevel;

    Time time;
    std::vector<std::vector<Soil>> field;

    Time timeSince(const State &pastState) const;

};

#endif