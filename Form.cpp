//
// Created by Niccolò Caselli on 16/06/23.
//

#include "Form.h"

const std::string &Form::getDescription() const {
    return description;
}

void Form::setDescription(const std::string &description) {
    Form::description = description;
}

time_t Form::getStartTime() const {
    return startTime;
}

void Form::setStartTime(time_t startTime) {
    Form::startTime = startTime;
}

time_t Form::getEndTime() const {
    return endTime;
}

void Form::setEndTime(time_t endTime) {
    Form::endTime = endTime;
}

time_t Form::getDate() const {
    return date;
}

void Form::setDate(time_t date) {
    Form::date = date;
}

time_t Form::getSearchDate() const {
    return searchDate;
}

void Form::setSearchDate(time_t date) {
    Form::searchDate = date;
    notifyObservers();
}


bool Form::validateForm() const {
    // Controlla se la descrizione è vuota
    if(description.empty()) return false;
    // Controlla se la data di inizio è prima della data di fine
    //if(startTime > endTime) return false; // TODO:remove controllo

    return true;
}
