//
// Created by Niccolò Caselli on 22/06/23.
//

#include "../Activity.h"
#include "../Utils.h"
#include "gtest/gtest.h"


#include "gtest/gtest.h"
#include "../ActivityManager.h"
#include "../Utils.h"


class ActivitySuite : public ::testing::Test {

protected:
    virtual void SetUp() {
        now =  Utils::getCurrentDate();
        description = "test";
        activity = new Activity(description, now, now);
    }

    Activity* activity;
    std::tm now;
    std::string description;

};

TEST_F(ActivitySuite, CreateActivity) {
    ASSERT_EQ(activity->getDescription(), description);

    EXPECT_EQ(now.tm_year, activity->getStartTime().tm_year);
    EXPECT_EQ(now.tm_mon, activity->getStartTime().tm_mon);
    EXPECT_EQ(now.tm_mday, activity->getStartTime().tm_mday);

    EXPECT_EQ(now.tm_year, activity->getEndTime().tm_year);
    EXPECT_EQ(now.tm_mon, activity->getEndTime().tm_mon);
    EXPECT_EQ(now.tm_mday,activity->getEndTime().tm_mday);
}

TEST_F(ActivitySuite, SetDescription) {
    std::string newDescription = "test2";
    activity->setDescription(newDescription);
    ASSERT_EQ(activity->getDescription(), newDescription);
}

TEST_F(ActivitySuite, SetStartTime) {
    std::tm tomorrow = Utils::getTomorrowDate(now);
    activity->setStartTime(tomorrow);

    EXPECT_EQ(tomorrow.tm_year, activity->getStartTime().tm_year);
    EXPECT_EQ(tomorrow.tm_mon, activity->getStartTime().tm_mon);
    EXPECT_EQ(tomorrow.tm_mday, activity->getStartTime().tm_mday);
}

TEST_F(ActivitySuite, SetEndTime) {
    std::tm tomorrow = Utils::getTomorrowDate(now);
    activity->setEndTime(tomorrow);

    EXPECT_EQ(tomorrow.tm_year, activity->getEndTime().tm_year);
    EXPECT_EQ(tomorrow.tm_mon, activity->getEndTime().tm_mon);
    EXPECT_EQ(tomorrow.tm_mday, activity->getEndTime().tm_mday);
}





