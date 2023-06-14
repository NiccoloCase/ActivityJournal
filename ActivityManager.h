//
// Created by Niccolò Caselli on 14/06/23.
//

#ifndef ACTIVITYJOURNAL_ACTIVITYMANAGER_H
#define ACTIVITYJOURNAL_ACTIVITYMANAGER_H

#include <string>
#include "stdio.h"
#include "stdio.h"
#include <list>
#include "Day.h"

class ActivityManager {

    public:
        /**
         * Aggiunge un'attività alla giornata corrente
         * @param description
         */
         void addActivity(std::string description);

    private:
         std::list<Day*> daysList;
};


#endif //ACTIVITYJOURNAL_ACTIVITYMANAGER_H
