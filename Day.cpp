//
// Created by Niccolò Caselli on 14/06/23.
//

#include "Day.h"


void Day::addActivity(std::string description) {
    auto newActivity = new Activity(description);
    activities.push_back(newActivity);
}