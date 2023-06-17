//
// Created by Niccolò Caselli on 14/06/23.
//

#ifndef ACTIVITYJOURNAL_MYSCROLLVIEW_H
#define ACTIVITYJOURNAL_MYSCROLLVIEW_H

#include <wx/scrolwin.h>
#include <wx/wx.h>
#include "Utils.h"
#include "ActivityManager.h"
#include "Observer.h"

class MyScrollView : public wxScrolledWindow, public Observer {

public:
    MyScrollView(wxWindow* parent, wxPoint point, ActivityManager* activityManager, Form* subject)
            : wxScrolledWindow(parent, wxID_ANY, point), subject(subject), activityManager(activityManager){

        // Regsitra l'observer
        subject->registerObserver(this);


        // Crea un sizer per il contenuto
        wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

        // Aggiungi il contenuto desiderato al sizer
        for (auto activity : shownActivities){
            wxStaticText* text = new wxStaticText(this, wxID_ANY, wxString(activity->getDescription()));
            sizer->Add(text, 0, wxALL, 10);
        }

        // Imposta il sizer come sizer del controllo
        SetSizer(sizer);

        // Calcola la dimensione del contenuto
        sizer->Fit(this);
        sizer->SetSizeHints(this);
    }

    ~MyScrollView() {
        subject->removeObserver( this );
    }

    void update() override {
        std::cout << "Observer updated" << std::endl;

        auto date = subject->getSearchDate();

        fetchActivitiesToShow(date);
    }

private:
    ActivityManager* activityManager;
    Form* subject;
    std::list<Activity*> shownActivities;



    /**
     * Metodo che recupera le attività da mostrare del giorno sceleto
     */
    void fetchActivitiesToShow(std::time_t date) {
        std::cout << "Showing activities in: " << std::asctime(std::localtime(&date)) << std::endl;
        shownActivities = activityManager->getActivitiesByDate(*std::localtime(&date));

        // TODO:remove
        for (auto activity : shownActivities){
            std::cout << "description: "<< activity->getDescription() << std::endl;
        }

    }

};

#endif //ACTIVITYJOURNAL_MYSCROLLVIEW_H
