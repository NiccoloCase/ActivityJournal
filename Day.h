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

        /**
         * Aggiunge un'attività alla giornata
         * @param activity
         */
        void addActivity(Activity* activity) {
            activities.push_back(activity);
        }

        /**
         * Restituisce la data della giornata
         * @return
         */
        std::tm getDate() const{
            return date;
        }

        /**
         * Restituisce la lista delle attività della giornata
         * @return
         */
        const std::list<Activity*> getActivities() const {
            return activities;
        }

        /**
         * Restituisce il numero di attività della giornata
         * @return
         */
        int getActivitiesSize() const{
            return activities.size();
        }

        ~Day() {
            for (auto activity : activities){
                delete activity;
            }
        }

    private:
        std::list<Activity*> activities;
        std::tm date;
};


#endif //ACTIVITYJOURNAL_DAY_H
