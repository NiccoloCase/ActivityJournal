//
// Created by Niccolò Caselli on 14/06/23.
//

#ifndef ACTIVITYJOURNAL_UTILS_H
#define ACTIVITYJOURNAL_UTILS_H

#include <ctime>
#include <wx/datetime.h>
#include <iostream>

namespace Utils {

    /**
     * Restituisce la data corrente
     * @return
     */
     std::tm getCurrentDate();

    /**
     * Verifica se due date sono dello stesso giorno
     */
     bool isSameDay(std::tm date1, std::tm date2);

    /**
     * Converte in una data in formato time_t da una wxDateTime
     * @param wxdt
     */
     std::time_t convertWxDateTimeToTimeT(const wxDateTime& dateTime);

    /**
     * Converte in una data in formato tm da una wxDateTime
     * @param wxdt
     */
     std::tm convertWxDateTimeToTm(const wxDateTime& wxDate);

    /**
     * Restitusce una stringa che rappresenta un orario in formato HH:MM
     * @param time
     * @return
     */
     std::string formatTime(std::tm time);

    /**
     * Passata una data, restituisce la data del giorno successivo
     * @param date
     * @return
     */
     std::tm getTomorrowDate(std::tm date);
};


#endif //ACTIVITYJOURNAL_UTILS_H
