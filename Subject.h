//
// Created by Niccolò Caselli on 17/06/23.
//

#ifndef ACTIVITYJOURNAL_SUBJECT_H
#define ACTIVITYJOURNAL_SUBJECT_H

#include "Observer.h"

class Subject {
    protected:
        ~Subject() {};

    public:
        virtual void registerObserver(Observer *o) = 0;
        virtual void removeObserver(Observer *o) = 0;
        virtual void notifyObservers() const = 0;
};


#endif //ACTIVITYJOURNAL_SUBJECT_H
