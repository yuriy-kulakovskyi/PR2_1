#pragma once
#include <iostream>
#include <string>

class IntRange {
private:
  int first;
  int second;

public:
  IntRange();
  IntRange(int f, int s);
  IntRange(const IntRange& r);

  ~IntRange() {}

  int GetFirst() const { return first; }
  int GetSecond() const { return second; }
  void SetFirst(int value);
  void SetSecond(int value);

  bool rangeCheck(int value) const;

  operator std::string() const;

  IntRange& operator=(const IntRange& r);

  friend IntRange& operator++(IntRange& r);
  friend IntRange operator++(IntRange& r, int);
  friend IntRange& operator--(IntRange& r);
  friend IntRange operator--(IntRange& r, int);

  friend std::ostream& operator<<(std::ostream& out, const IntRange& r);
  friend std::istream& operator>>(std::istream& in, IntRange& r);
};

IntRange makeIntRange(int f, int s);