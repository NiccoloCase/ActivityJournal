//
// Created by Niccolò Caselli on 14/06/23.
//

#ifndef ACTIVITYJOURNAL_UTILS_H
#define ACTIVITYJOURNAL_UTILS_H

#include <ctime>


class Utils {
    public:
        /**
         * Verifica se due date sono dello stesso giorno
         */
        static bool isSameDay(std::tm date1, std::tm date2) {
            return (date1.tm_year == date2.tm_year &&
                    date1.tm_mon == date2.tm_mon &&
                    date1.tm_mday == date2.tm_mday);
        }

};


#endif //ACTIVITYJOURNAL_UTILS_H
