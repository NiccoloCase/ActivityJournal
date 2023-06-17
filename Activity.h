//
// Created by Niccolò Caselli on 14/06/23.
//

#ifndef ACTIVITYJOURNAL_ACTIVITY_H
#define ACTIVITYJOURNAL_ACTIVITY_H
#include "stdio.h"
#include "string"

class Activity {
    public:
        Activity(std::string description, std::tm startTime, std::tm endTime) : description(description), startTime(startTime),endTime(endTime) {}


    const std::string &getDescription() const {
            return description;
        }

    void setDescription(const std::string &description) {
        Activity::description = description;
    }

    const std::tm &getStartTime() const {
        return startTime;
    }

    void setStartTime(const std::tm &startTime) {
        Activity::startTime = startTime;
    }

    const std::tm &getEndTime() const {
        return endTime;
    }

    void setEndTime(const std::tm &endTime) {
        Activity::endTime = endTime;
    }

    private:
        std::string description;
        std::tm startTime;
        std::tm endTime;


};


#endif //ACTIVITYJOURNAL_ACTIVITY_H
