#include <vector>
#include "Soil.h"



Time::Time(const int day, const int hour, const int minutes) : day{day}, hour{hour}, minutes{minutes} {}

// assumes that pastTime is actually past!
Time Time::timeSince(const Time &pastTime) const {

    int daysPassed = this->day - pastTime.day;
    int hoursPassed = this->hour - pastTime.hour;
    int minutesPassed = this->minutes - pastTime.minutes;

    if(hoursPassed < 0) {
        daysPassed--;
        hoursPassed = 24 + hoursPassed;
    }

    if(minutesPassed < 0) {
        hoursPassed--;
        minutesPassed = 60 + minutesPassed;
    }

    return Time{daysPassed, hoursPassed, minutesPassed};

}

void Time::tick() {

    minutes += 10;

    if(minutes == 60) {
        hour++;
        minutes = 0;
    }

    if(hour == 24) {
        day++;
        hour = 0;
    }

}



GameClock::GameClock() : currentTime{0, 0, 0} {}

GameClock::GameClock(const Time &time) : currentTime{time} {}

GameClock::GameClock(const int day, const int hour, const int minutes) : currentTime{day, hour, minutes} {}

void GameClock::tick() { currentTime.tick(); }

Time GameClock::getTime() const { return currentTime; }



Time State::timeSince(const State &pastState) const {
    return this->time.timeSince(pastState);
}