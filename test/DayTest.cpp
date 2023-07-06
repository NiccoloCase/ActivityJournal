//
// Created by Niccolò Caselli on 22/06/23.
//

#include "../Day.h"
#include "gtest/gtest.h"
#include "../Utils.h"

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
    // Crea una nuova giornata
    auto day = new Day(date);

    // Aggiunge un'attività
    day->addActivity(new Activity("Test activity 1", date, date));
    EXPECT_EQ(1, day->getActivitiesSize());

    // Aggiunge una seconda attività
    day->addActivity(new Activity("Test activity 2", Utils::getTomorrowDate(date), date));
    EXPECT_EQ(2, day->getActivitiesSize());

    // Aggiunge una terza attività
    day->addActivity(new Activity("Test activity 3", Utils::getTomorrowDate(date), date));
    EXPECT_EQ(3, day->getActivitiesSize());
}