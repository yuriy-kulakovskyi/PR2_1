#include "gtest/gtest.h"
#include "../classes/IntRange.h"

TEST(Main_Functions, RangeCheck) {
  IntRange range;
  range.SetFirst(100);
  range.SetSecond(200);
  EXPECT_EQ(range.rangeCheck(150), true);
}