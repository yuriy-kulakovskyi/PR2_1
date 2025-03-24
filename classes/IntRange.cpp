#include "IntRange.h"
#include <iostream>
#include <sstream>

using namespace std;

IntRange::IntRange() {
    first = 0;
    second = 1;
}

IntRange::IntRange(int f, int s) {
    SetSecond(s);
    SetFirst(f);
}

IntRange::IntRange(const IntRange& r) {
    first = r.first;
    second = r.second;
}

void IntRange::SetFirst(int value) {
    if (second == 0 || value < second) {
        first = value;
    }
    else {
        cout << "Error: First must be less than second (" << second << ")." << endl;
        first = 0;
    }
}

void IntRange::SetSecond(int value) {
    if (value > first) {
        second = value;
    }
    else {
        cout << "Error: Second must be greater than first (" << first << ")." << endl;
        second = first + 1;
    }
}

bool IntRange::rangeCheck(int value) const {
    return (value >= first && value < second);
}

IntRange::operator std::string() const {
    stringstream ss;
    ss << "[" << first << ", " << second << ")";
    return ss.str();
}

IntRange& IntRange::operator=(const IntRange& r) {
    if (this != &r) {
        first = r.first;
        second = r.second;
    }
    return *this;
}

IntRange& operator++(IntRange& r) {
    r.first++;
    return r;
}

IntRange operator++(IntRange& r, int) {
    IntRange temp(r);
    r.second++;
    return temp;
}

IntRange& operator--(IntRange& r) {
    r.first--;
    return r;
}

IntRange operator--(IntRange& r, int) {
    IntRange temp(r);
    r.second--;
    return temp;
}

ostream& operator<<(ostream& out, const IntRange& r) {
    out << string(r);
    return out;
}

istream& operator>>(istream& in, IntRange& r) {
    int f, s;
    cout << "Enter range limits (first < second):\n";
    cout << "  first = "; in >> f;
    cout << "  second = "; in >> s;

    if (f < s) {
        r.SetSecond(s);
        r.SetFirst(f);
    }
    else {
        cout << "Error: First must be less than second. Using default values [0,1).\n";
        r.SetFirst(0);
        r.SetSecond(1);
    }

    return in;
}

IntRange makeIntRange(int f, int s) {
    IntRange obj;
    if (f < s) {
        obj.SetSecond(s);
        obj.SetFirst(f);
    }
    else {
        cout << "Error: Invalid range values.\n";
    }
    return obj;
}