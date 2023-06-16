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
