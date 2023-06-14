//
// Created by Niccolò Caselli on 14/06/23.
//

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include "MyFrame.h"
#include "MyApp.h"
#include <wx/datectrl.h>
#include "MyScrollView.h"
#include <wx/timectrl.h>
#include "ActivityManager.h"

wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_MENU(wxID_EXIT,  MyFrame::OnExit)
    EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
    EVT_BUTTON(SUBMIT_BUTTON_ID, MyFrame::OnSubmitButtonClicked)
    EVT_TEXT(TEXT_INPUT_ID, MyFrame::OnTextInputChanged)
    EVT_TIME_CHANGED(TIME_START_CTRL_ID, MyFrame::OnStartTimeSelected)
    EVT_TIME_CHANGED(TIME_END_CTRL_ID, MyFrame::OnEndTimeSelected)
wxEND_EVENT_TABLE()


MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
        : wxFrame(NULL, wxID_ANY, title, pos, size, wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER | wxMAXIMIZE_BOX)) {








    // Crea la barra di stato
    CreateStatusBar();
    SetStatusText( MyApp::appName);

    // Pannelli:
    auto leftPanel = new wxPanel(this,wxID_ANY,wxPoint(0,0), wxSize(MyApp::windowWidth/2,MyApp::windowHeight));
    leftPanel->SetBackgroundColour(wxColour("#1B1B3A"));

    auto rightPanel = new wxPanel(this,wxID_ANY,wxPoint(MyApp::windowWidth/2,0), wxSize(MyApp::windowWidth/2,MyApp::windowHeight));
    rightPanel->SetBackgroundColour(wxColour("orange"));

    // Costanti
    int MARGIN_HORIZONTAL = 20;
    int TITLE_MARGIN_BOTTOM = 60;
    int TITLE_MARGIN_TOP = 25;

    // LATO SINISTRO:

    int currentPosY = TITLE_MARGIN_TOP;

    // Titolo
    auto leftTitleText = new wxStaticText(leftPanel, wxID_ANY, "Cosa hai fatto oggi?",wxPoint(MARGIN_HORIZONTAL,currentPosY));
    auto leftTitleTextFont = leftTitleText->GetFont();
    leftTitleTextFont.SetPointSize(20);
    leftTitleText->SetFont(leftTitleTextFont);
    currentPosY+=TITLE_MARGIN_BOTTOM;

    // Text input
    int textInputHeight = 150;
    auto input = new wxTextCtrl(leftPanel, TEXT_INPUT_ID, "", wxPoint(MARGIN_HORIZONTAL,currentPosY), wxSize(MyApp::windowWidth/2-MARGIN_HORIZONTAL*2,textInputHeight));
    input->SetBackgroundColour("#693668");
    input->SetHint("Inserisci la descrizione dell'attività");
    currentPosY += textInputHeight + 20;

    // Time picker (1)
    new wxStaticText(leftPanel, wxID_ANY, "Inizio:",wxPoint(MARGIN_HORIZONTAL,currentPosY));
    currentPosY += 20;
    new wxTimePickerCtrl(leftPanel, TIME_START_CTRL_ID, wxDefaultDateTime, wxPoint(MARGIN_HORIZONTAL, currentPosY), wxDefaultSize, wxDP_DEFAULT);
    currentPosY += 50;

    // Time picker (2)
    new wxStaticText(leftPanel, wxID_ANY, "Fine:",wxPoint(MARGIN_HORIZONTAL,currentPosY));
    currentPosY += 20;
    new wxTimePickerCtrl(leftPanel, TIME_END_CTRL_ID, wxDefaultDateTime, wxPoint(MARGIN_HORIZONTAL, currentPosY), wxDefaultSize, wxDP_DEFAULT);
    currentPosY += 50;

    // Submit
    auto submitButton = new wxButton(leftPanel, SUBMIT_BUTTON_ID, "Aggiungi attività",wxPoint(MARGIN_HORIZONTAL,currentPosY),wxSize(MyApp::windowWidth/2-MARGIN_HORIZONTAL*2, 30));


    // LATO DESTRO
    currentPosY = TITLE_MARGIN_TOP;

    // Titolo
    auto rightTitleText = new wxStaticText(rightPanel, wxID_ANY, "Registro attività",wxPoint(MARGIN_HORIZONTAL,currentPosY));
    auto rightTitleTextFont = rightTitleText->GetFont();
    rightTitleTextFont.SetPointSize(20);
    rightTitleText->SetFont(rightTitleTextFont);
    currentPosY+=TITLE_MARGIN_BOTTOM;

    // Date picker
    new wxDatePickerCtrl(rightPanel, wxID_ANY, wxDefaultDateTime, wxPoint(MARGIN_HORIZONTAL, currentPosY), wxDefaultSize, wxDP_DEFAULT);
    currentPosY+=40;

    // Crea una finestra con scorrimento
    MyScrollView* scrollWindow = new MyScrollView(rightPanel, wxPoint(MARGIN_HORIZONTAL, currentPosY));




}

// eventi

void MyFrame::OnExit(wxCommandEvent& event) {
    Close( true );
}

void MyFrame::OnAbout(wxCommandEvent& event) {
    wxMessageBox( "This is a wxWidgets' Hello world sample",
                  "About Hello World", wxOK | wxICON_INFORMATION );
}


void MyFrame::OnSubmitButtonClicked(wxCommandEvent &event) {
   /* wxMessageBox( "titlo",
                  "descrizione", wxOK );*/


   this->activityManager.addActivity( "s");

}

void MyFrame::OnTextInputChanged(wxCommandEvent &event) {

    std::cout << event.GetString();
}


void MyFrame::OnStartTimeSelected(wxDateEvent &event) {
auto date = event.GetDate();
    std::cout << date.GetHour() << date.GetMinute()  << std::endl;


}

void MyFrame::OnEndTimeSelected(wxDateEvent &event) {

    std::cout << event.GetString();
}
