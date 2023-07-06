//
// Created by Niccolò Caselli on 06/07/23.
//

#include <ctime>
#include <wx/datetime.h>
#include <iostream>

namespace Utils {

    std::tm getCurrentDate() {
        std::time_t now = std::time(0);
        std::tm* currentTime = std::localtime(&now);
        return *currentTime;
    }

    bool isSameDay(std::tm date1, std::tm date2) {
        return (date1.tm_year == date2.tm_year &&
                date1.tm_mon == date2.tm_mon &&
                date1.tm_mday == date2.tm_mday);
    }

    std::time_t convertWxDateTimeToTimeT(const wxDateTime& dateTime) {
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

    std::tm convertWxDateTimeToTm(const wxDateTime& wxDate){
        std::tm result = {};
        result.tm_year = wxDate.GetYear() - 1900;
        result.tm_mon = wxDate.GetMonth();
        result.tm_mday = wxDate.GetDay();
        result.tm_hour = wxDate.GetHour();
        result.tm_min = wxDate.GetMinute();
        result.tm_sec = wxDate.GetSecond();
        return result;
    }

    std::string formatTime(std::tm time){
        char buffer[6];
        std::strftime(buffer, sizeof(buffer), "%H:%M", &time);
        std::string timeString(buffer);
        return timeString;
    }

    std::tm getTomorrowDate(std::tm date){
        std::tm tomorrowDate = date;
        tomorrowDate.tm_mday++;
        return tomorrowDate;
    }
};
