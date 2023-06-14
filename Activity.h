//
// Created by Niccolò Caselli on 14/06/23.
//

#ifndef ACTIVITYJOURNAL_ACTIVITY_H
#define ACTIVITYJOURNAL_ACTIVITY_H
#include "stdio.h"
#include "string"

class Activity {
    public:
        Activity(std::string description) : description(description) {}

        const std::string &getDescription() const {
            return description;
        }

        void setDescription(const std::string &description) {
            Activity::description = description;
        }

    private:
        std::string description;

};


#endif //ACTIVITYJOURNAL_ACTIVITY_H
