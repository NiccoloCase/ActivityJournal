//
// Created by Niccolò Caselli on 22/06/23.
//

#include "../Day.h"
#include "gtest/gtest.h"

TEST(DayTest, DayCostructor) {
    auto now = std::time(nullptr);
    auto date = *std::localtime(&now);
    auto day = new Day(date);
    EXPECT_EQ(date.tm_year, day->getDate().tm_year);
    EXPECT_EQ(date.tm_mon, day->getDate().tm_mon);
    EXPECT_EQ(date.tm_mday, day->getDate().tm_mday);
}

TEST(DayTest, DayAddActivity) {
    auto now = std::time(nullptr);
    auto date = *std::localtime(&now);
    auto day = new Day(date);
    day->addActivity(new Activity("Test activity", date, date));
    auto activities = day->getActivities();
    EXPECT_EQ(1, activities.size());
    EXPECT_EQ("Test activity", activities.front()->getDescription());
}