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
         * @param description
         */
        void addActivity(std::string description);

        /**
         * Restituisce la data della giornata
         * @return
         */
        std::tm getDate() const{
            return date;
        }

        /**
         * Restituisce la lista di tutte le attività della giornata
         * @return
         */
        std::list<Activity*> getActivities() const{
            return activities;
        }

    private:
        std::list<Activity*> activities;
        std::tm date;
};


#endif //ACTIVITYJOURNAL_DAY_H
