//
// Created by Niccolò Caselli on 14/06/23.
//

#include "ActivityManager.h"
#include "Utils.h"
#include "iostream"


 void ActivityManager::addActivity(std::string description){
    // ottiene la data odierna
    std::time_t now = std::time(0);
    std::tm* currentTime = std::localtime(&now);

    // cerca se esiste già un giorno con la data odierna
    for (auto day : daysList){
        if (Utils::isSameDay(day->getDate(), *currentTime)){
            std::cout << "Added activity to an existing day" << std::endl;
            day->addActivity(description);
            return;
        }
     }

     std::cout << "No existing day found, creating new one" << std::endl;
     auto newDay = new Day(*currentTime);
     newDay->addActivity(description);
     daysList.push_back(newDay);
     return;

}