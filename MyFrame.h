//
// Created by Niccolò Caselli on 14/06/23.
//

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#ifndef ACTIVITYJOURNAL_MYFRAME_H
#define ACTIVITYJOURNAL_MYFRAME_H


class MyFrame: public wxFrame {
public:
    MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
private:
    // eventi:
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnSubmitButtonClicked(wxCommandEvent& event);
    void OnTextInputChanged(wxCommandEvent& event);

    wxDECLARE_EVENT_TABLE();

};

enum IDs {
    SUBMIT_BUTTON_ID = 2,
    TEXT_INPUT_ID = 3

};






#endif //ACTIVITYJOURNAL_MYFRAME_H
