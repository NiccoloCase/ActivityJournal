//
// Created by Niccolò Caselli on 14/06/23.
//

#include <wx/wxprec.h>
#include <wx/timectrl.h>
#include <wx/dateevt.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include "ActivityManager.h"
#include "Form.h"

#ifndef ACTIVITYJOURNAL_MYFRAME_H
#define ACTIVITYJOURNAL_MYFRAME_H


class MyFrame: public wxFrame {
    public:
        MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
    private:

        ActivityManager activityManager;
        Form myForm;

        wxTextCtrl* textInput;

        // eventi:
        void OnExit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnSubmitButtonClicked(wxCommandEvent& event);
        void OnTextInputChanged(wxCommandEvent& event);
        void OnStartTimeSelected(wxDateEvent& event);
        void OnEndTimeSelected(wxDateEvent& event);
        void OnDateSelected(wxDateEvent& event);
        void OnSearchDateChanged(wxDateEvent& event);

        wxDECLARE_EVENT_TABLE();
};

enum IDs {
    SUBMIT_BUTTON_ID = 2,
    TEXT_INPUT_ID = 3,
    TIME_START_CTRL_ID = 4,
    TIME_END_CTRL_ID = 5,
    DATE_CTRL_ID = 6,
    SEARCH_DATE_CTRL_ID = 7
};



#endif //ACTIVITYJOURNAL_MYFRAME_H
