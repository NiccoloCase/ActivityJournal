//
// Created by Niccolò Caselli on 14/06/23.
//

#ifndef ACTIVITYJOURNAL_UTILS_H
#define ACTIVITYJOURNAL_UTILS_H

#include <ctime>
#include <wx/datetime.h>


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


        /**
         * Converte in una data in formato time_t da una wxDateTime
         * @param wxdt
         */
        static std::time_t ConvertWxDateTimeToTimeT(const wxDateTime& wxdt){
            std::tm timeStruct;
            timeStruct.tm_year = wxdt.GetYear() - 1900;
            timeStruct.tm_mon = wxdt.GetMonth() - 1;
            timeStruct.tm_mday = wxdt.GetDay();
            timeStruct.tm_hour = wxdt.GetHour();
            timeStruct.tm_min = wxdt.GetMinute();
            timeStruct.tm_sec = wxdt.GetSecond();
            return std::mktime(&timeStruct);
        }
};


#endif //ACTIVITYJOURNAL_UTILS_H
