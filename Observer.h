//
// Created by Niccolò Caselli on 17/06/23.
//

#ifndef ACTIVITYJOURNAL_OBSERVER_H
#define ACTIVITYJOURNAL_OBSERVER_H


class Observer {
    protected:
        ~Observer() {};

    public:
        virtual void update() = 0;

};


#endif //ACTIVITYJOURNAL_OBSERVER_H
