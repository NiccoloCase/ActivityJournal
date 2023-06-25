//
// Created by Niccolò Caselli on 14/06/23.
//

#ifndef ACTIVITYJOURNAL_UTILS_H
#define ACTIVITYJOURNAL_UTILS_H

#include <ctime>
#include <wx/datetime.h>
#include <iostream>

class Utils {
    public:

        /**
         * Restituisce la data corrente
         * @return
         */
        static std::tm getCurrentDate() {
            std::time_t now = std::time(0);
            std::tm* currentTime = std::localtime(&now);
            return *currentTime;
        }

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
        static std::time_t convertWxDateTimeToTimeT(const wxDateTime& dateTime) {
            int year = dateTime.GetYear();
            int month = static_cast<int>(dateTime.GetMonth()) + 1;
            int day = dateTime.GetDay();
            int hour = dateTime.GetHour();
            int minute = dateTime.GetMinute();
            int second = dateTime.GetSecond();

            std::tm timeInfo{};
            timeInfo.tm_year = year - 1900;   // Years since 1900
            timeInfo.tm_mon = month - 1;      // Months range from 0 to 11
            timeInfo.tm_mday = day;
            timeInfo.tm_hour = hour-1;
            timeInfo.tm_min = minute;
            timeInfo.tm_sec = second;

            return std::mktime(&timeInfo);
    }

    /**
     * Converte in una data in formato tm da una wxDateTime
     * @param wxdt
     */
    static std::tm convertWxDateTimeToTm(const wxDateTime& wxDate){
        std::tm result = {};
        result.tm_year = wxDate.GetYear() - 1900;
        result.tm_mon = wxDate.GetMonth();
        result.tm_mday = wxDate.GetDay();
        result.tm_hour = wxDate.GetHour();
        result.tm_min = wxDate.GetMinute();
        result.tm_sec = wxDate.GetSecond();
        return result;
    }

    /**
     * Restitusce una stringa che rappresenta un orario in formato HH:MM
     * @param time
     * @return
     */
    static std::string formatTime(std::tm time){
        char buffer[6];
        std::strftime(buffer, sizeof(buffer), "%H:%M", &time);
        std::string timeString(buffer);
        return timeString;
        }

        /**
         * Passata una data, restituisce la data del giorno successivo
         * @param date
         * @return
         */
        static std::tm  getTomorrowDate(std::tm date){
            std::tm tomorrowDate = date;
            tomorrowDate.tm_mday++;
            return tomorrowDate;
        }
};


#endif //ACTIVITYJOURNAL_UTILS_H
