// mytime3.cpp  -- implementing Time methods
#include "mytime3.h"

Time::Time() {
    hours = minutes = 0;
}

Time::Time(int h, int m) {
    hours = h;
    minutes = m;
}

void Time::AddMin(int m) {
    minutes += m;
    hours += minutes / 60;
    minutes %= 60;
}

void Time::AddHr(int h) {
    hours += h;
}

void Time::Reset(int h, int m) {
    hours = h;
    minutes = m;
}

Time operator+(const Time &t1, const Time &t) {
    Time sum;
    sum.minutes = t1.minutes + t.minutes;
    sum.hours = t1.hours + t.hours + sum.minutes / 60;
    sum.minutes %= 60;
    return sum;
}

Time operator-(const Time &t1, const Time &t) {
    Time diff;
    int tot1, tot2;
    tot1 = t.minutes + 60 * t.hours;
    tot2 = t1.minutes + 60 * t1.hours;
    diff.minutes = (tot1 - tot2) % 60;
    diff.hours = (tot1 - tot2) / 60;
    return diff;
}

std::ostream &operator<<(std::ostream &os, const Time &t) {
    os << t.hours << " hours, " << t.minutes << " minutes";
    return os;
}

Time operator*(const Time &t, double mult) {
    Time result;
    long totalminutes = t.hours * mult * 60 + t.minutes * mult;
    result.hours = totalminutes / 60;
    result.minutes = totalminutes % 60;
    return result;
}

Time operator*(double mult, const Time &t) {
    return t * mult;
}
