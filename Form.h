//
// Created by Niccolò Caselli on 16/06/23.
//

#ifndef ACTIVITYJOURNAL_FORM_H
#define ACTIVITYJOURNAL_FORM_H

#include "string"


class Form {

    public:
        const std::string &getDescription() const;

        void setDescription(const std::string &description);

        time_t getStartTime() const;

        void setStartTime(time_t startTime);

        time_t getEndTime() const;

        void setEndTime(time_t endTime);

        time_t getDate() const;

        void setDate(time_t date);

    private:
        std::string description;
        std::time_t startTime;
        std::time_t endTime;
        std::time_t date;
};


#endif //ACTIVITYJOURNAL_FORM_H
