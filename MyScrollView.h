//
// Created by Niccolò Caselli on 14/06/23.
//

#ifndef ACTIVITYJOURNAL_MYSCROLLVIEW_H
#define ACTIVITYJOURNAL_MYSCROLLVIEW_H

#include <wx/scrolwin.h>
#include <wx/wx.h>
#include "Utils.h"
#include "ActivityManager.h"

class MyScrollView : public wxScrolledWindow
{
public:
    MyScrollView(wxWindow* parent, wxPoint point, ActivityManager* activityManager)
            : wxScrolledWindow(parent, wxID_ANY, point){

        // data corrente
        std::tm currentTime = Utils::getCurrentDate();
        // Richiede le attività della giornata
        auto activities = activityManager->getActivitiesByDate(currentTime);

        for (auto activity : activities){
            std::cout << activity->getDescription() << std::endl;
        }




        // Crea un sizer per il contenuto
        wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

        // Aggiungi il contenuto desiderato al sizer
        for (int i = 0; i < 100; i++){
            wxStaticText* text = new wxStaticText(this, wxID_ANY, wxString::Format("Elemento %d", i));
            sizer->Add(text, 0, wxALL, 10);
        }

        // Imposta il sizer come sizer del controllo
        SetSizer(sizer);

        // Calcola la dimensione del contenuto
        sizer->Fit(this);
        sizer->SetSizeHints(this);
    }
};


#endif //ACTIVITYJOURNAL_MYSCROLLVIEW_H
