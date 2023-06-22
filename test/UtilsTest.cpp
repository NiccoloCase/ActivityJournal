//
// Created by Niccolò Caselli on 22/06/23.
//
#include "../Utils.h"
#include "gtest/gtest.h"
#include "wx/time.h"


TEST(UtilsTest, GetCurrentDate) {
    std::tm currentDate = Utils::getCurrentDate();
    std::time_t currentTime = std::time(nullptr);
    std::tm* currentTimeInfo = std::localtime(&currentTime);

    EXPECT_EQ(currentTimeInfo->tm_year, currentDate.tm_year);
    EXPECT_EQ(currentTimeInfo->tm_mon, currentDate.tm_mon);
    EXPECT_EQ(currentTimeInfo->tm_mday, currentDate.tm_mday);
}

TEST(UtilsTest, IsSameDay) {
    std::tm date1{}, date2{};
    bool result = Utils::isSameDay(date1, date2);
    EXPECT_EQ(true, result);
}

TEST(UtilsTest, FormatTime) {
    std::tm time{};
    std::string result = Utils::formatTime(time);
    std::string expectedTimeString = "00:00";
    EXPECT_EQ(expectedTimeString, result);
}

TEST(UtilsTest, GetTomorrowDate) {
    std::tm tomorrowDate = Utils::getTomorrowDate(Utils::getCurrentDate());
    std::time_t tomorrowTime = std::time(nullptr) + 86400;
    std::tm *tomorrowTimeInfo = std::localtime(&tomorrowTime);

    EXPECT_EQ(tomorrowTimeInfo->tm_year, tomorrowDate.tm_year);
    EXPECT_EQ(tomorrowTimeInfo->tm_mon, tomorrowDate.tm_mon);
    EXPECT_EQ(tomorrowTimeInfo->tm_mday, tomorrowDate.tm_mday);
}