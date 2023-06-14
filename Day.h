//
// Created by Niccolò Caselli on 14/06/23.
//

#ifndef ACTIVITYJOURNAL_DAY_H
#define ACTIVITYJOURNAL_DAY_H

#include "stdio.h"
#include "string"
#include "stdio.h"
#include "list"
#include "Activity.h"
#include <ctime>


class Day {
    public:

        Day(std::tm date) : date(date) { }

        void addActivity(std::string description);

        std::tm getDate() const{
            return date;
        }

    private:
        std::list<Activity*> activities;
        std::tm date;
};


#endif //ACTIVITYJOURNAL_DAY_H
