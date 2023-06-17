//
// Created by Niccolò Caselli on 16/06/23.
//

#ifndef ACTIVITYJOURNAL_FORM_H
#define ACTIVITYJOURNAL_FORM_H

#include "string"
#include "Subject.h"
#include "Observer.h"
#include "list"


/**
 * Classe che si occupa di gestire i dati del form
 * Fa ta Subject nel pattern Observer
 */
class Form: Subject {

    public:

        Form(){
            date = std::time(0);
            searchDate = std::time(0);
        }

        const std::string &getDescription() const;
        void setDescription(const std::string &description);

        time_t getStartTime() const;
        void setStartTime(time_t startTime);

        time_t getEndTime() const;
        void setEndTime(time_t endTime);

        time_t getDate() const;
        void setDate(time_t date);

        time_t getSearchDate() const;
        void setSearchDate(time_t date);


        /**
         * Metodo che notifica gli observer di un cambiamento dei dati
         */
        void notifyObservers() const override {
            for (auto observer : observers) {
                observer->update();
            }
        }

        /**
         * Registra un observer
         * @param observer
         */
        void registerObserver(Observer *observer) override {
            observers.push_back(observer);
        }

        /**
         * Rimuove un observer
         * @param observer
         */
        void removeObserver(Observer *observer) override {
            observers.remove(observer);
        }

    private:
        // dati del form:
        std::string description;
        std::time_t startTime;
        std::time_t endTime;
        std::time_t date;
        std::time_t searchDate;
        // pattern observer:
        std::list<Observer*> observers;
};


#endif //ACTIVITYJOURNAL_FORM_H
