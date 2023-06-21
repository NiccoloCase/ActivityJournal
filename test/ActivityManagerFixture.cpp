#include "gtest/gtest.h"
#include "../ActivityManager.h"
#include "../Utils.h"


class ActivityManagerSuite : public ::testing::Test {

protected:
    virtual void SetUp() {
        now =  Utils::getCurrentDate();
    }

    ActivityManager activityManager;
    std::tm now;
};

// Testa l'aggiunta di attività
TEST_F(ActivityManagerSuite, TestAddActivity) {
    activityManager.addActivity(new Activity("test1", now, now), now);
    auto activities = activityManager.getActivitiesByDate(now);
    ASSERT_EQ(1, activities.size());
}

// Testa la ricerca di attività per data
TEST_F(ActivityManagerSuite, TestGetActivitiesByDate) {
    std::tm tomorrow = Utils::getTomorrowDate(now);
    activityManager.addActivity(new Activity("test1", now, now), now);
    activityManager.addActivity(new Activity("test2", now, now), now);
    activityManager.addActivity(new Activity("test3", tomorrow, tomorrow), tomorrow);

    auto activitiesToday = activityManager.getActivitiesByDate(now);

    ASSERT_EQ(2, activitiesToday.size());
    ASSERT_EQ("test1", activitiesToday.front()->getDescription());
    ASSERT_EQ("test2", activitiesToday.back()->getDescription());

    auto activitiesTomorrow = activityManager.getActivitiesByDate(tomorrow);

    ASSERT_EQ(1, activitiesTomorrow.size());
    ASSERT_EQ("test3", activitiesTomorrow.front()->getDescription());
}