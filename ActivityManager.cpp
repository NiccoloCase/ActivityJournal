//
// Created by Niccolò Caselli on 14/06/23.
//

#include "ActivityManager.h"
#include "Utils.h"
#include "iostream"


 void ActivityManager::addActivity(Activity* activity, std::tm date) {
    // cerca se esiste già un giorno con la data odierna
    for (auto day : daysList){
        if (Utils::isSameDay(day->getDate(), date)){
            std::cout << "Added activity to an existing day" << std::endl;
            day->addActivity(activity);
            return;
        }
     }

     std::cout << "No existing day found, creating new one for day " << date.tm_mday << std::endl;
     auto newDay = new Day(date);
     newDay->addActivity(activity);
     daysList.push_back(newDay);
     return;
}

std::list<Activity*> ActivityManager::getActivitiesByDate(std::tm date) const {
    for (auto day : daysList){
        if (Utils::isSameDay(day->getDate(), date)){
            auto activities = day->getActivities();
            return activities;
        }
    }
    std::cout << "No activities found for the specified date" << std::endl;
    return  std::list<Activity*>();
}

ActivityManager::~ActivityManager() {
    for (auto day : daysList){
        delete day;
    }
}
