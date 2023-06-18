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


    void drawActivities() {
        if (sizer != nullptr){
            sizer->Clear(true);
            std::cout << "Cleared sizer" << std::endl;
        }

        sizer = new wxBoxSizer(wxVERTICAL);

        for (auto activity : shownActivities){
           wxStaticText* text = new wxStaticText(this, wxID_ANY, wxString(activity->getDescription()));
           text->SetBackgroundColour(wxColour("#02758c"));
           auto textFont = text->GetFont();
            textFont.SetPointSize(15);
           text->SetFont(textFont);

           sizer->Add(text, 0, wxALL, 10);



            wxStaticText* startTimeText = new wxStaticText(this, wxID_ANY, wxString(Utils::formatTime(activity->getStartTime())));


            sizer->Add(startTimeText, 0, wxALL, 10);

        }

        // TODO: remove
      /*  for (int i = 0; i < 200; i++) {
             wxStaticText* text = new wxStaticText(this, wxID_ANY, wxString::Format("%d) Elemento", i+1));
             text->SetBackgroundColour(wxColour("red"));
             text->SetSize(wxSize(200, 100));
             sizer->Add(text, 0, wxALL, 5);
         }
*/
        SetSizer(sizer);
        SetSize(size);
        SetVirtualSize(size.GetWidth(),10000);


        SetScrollRate(10, 10);
        EnableScrolling(false, true);
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

        // TODO:remove
        for (auto activity : shownActivities){
            std::cout << "description: "<< activity->getDescription() << std::endl;
        }
    }

};

#endif //ACTIVITYJOURNAL_MYSCROLLVIEW_H
