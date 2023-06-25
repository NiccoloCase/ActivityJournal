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
    MyScrollView(wxWindow* parent,wxPoint pos,wxSize size, ActivityManager* activityManager, Form* subject):
        subject(subject), wxScrolledWindow(parent, wxID_ANY, pos),
        activityManager(activityManager), size(size), pos(pos){

        // Registra l'observer
        subject->registerObserver(this);

        // GARFICA
        drawActivities();
    }

    /**
     * Disegna le attività del giorno selezionato
     */
    void drawActivities() {
        if (sizer != nullptr){
            sizer->Clear(true);
            std::cout << "Cleared sizer" << std::endl;
        }

        sizer = new wxBoxSizer(wxVERTICAL);

        for (auto activity : shownActivities){
            auto textPanel = new wxPanel(this, wxID_ANY);
            textPanel->SetBackgroundColour("#02758c");

            std::string timeString;
            if(Utils::formatTime(activity->getStartTime()) == Utils::formatTime(activity->getEndTime()))
                timeString = Utils::formatTime(activity->getStartTime());
            else timeString = Utils::formatTime(activity->getStartTime()) + " - " + Utils::formatTime(activity->getEndTime());

            auto timeText=  new wxStaticText(textPanel, wxID_ANY, wxString(timeString), wxPoint(0,0));
            auto timeFont = timeText->GetFont();
            timeFont.SetPointSize(10);
            timeText->SetFont(timeFont);


            wxStaticText* text = new wxStaticText(textPanel, wxID_ANY, wxString(activity->getDescription()),wxPoint(0,30));
            auto textFont = text->GetFont();
            textFont.SetPointSize(15);
            text->SetFont(textFont);

            sizer->Add(textPanel, 0, wxALL, wxBorder(6));

        }

        SetSizer(sizer);
        SetSize(size);
        SetVirtualSize(size.GetWidth() ,10000);


        SetScrollRate(10, 10);
        EnableScrolling(true, true);
    }


    ~MyScrollView() {
        subject->removeObserver( this );
    }

    void update() override {
        std::cout << "Observer updated" << std::endl;

        auto date = subject->getSearchDate();

        fetchActivitiesToShow(date);
        drawActivities();
    }

private:
    ActivityManager* activityManager;
    Form* subject;
    std::list<Activity*> shownActivities;
    wxBoxSizer* sizer;
    wxSize size;
    wxPoint pos;

    /**
     * Metodo che recupera le attività da mostrare del giorno sceleto
     */
    void fetchActivitiesToShow(std::time_t date) {
        std::cout << "Showing activities in: " << std::asctime(std::localtime(&date)) << std::endl;
        shownActivities = activityManager->getActivitiesByDate(*std::localtime(&date));

        for (auto activity : shownActivities){
            std::cout << "description: "<< activity->getDescription() << std::endl;
        }
    }

};

#endif //ACTIVITYJOURNAL_MYSCROLLVIEW_H
