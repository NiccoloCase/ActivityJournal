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
#include "Utils.h"

wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_MENU(wxID_EXIT,  MyFrame::OnExit)
    EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
    EVT_BUTTON(SUBMIT_BUTTON_ID, MyFrame::OnSubmitButtonClicked)
    EVT_TEXT(TEXT_INPUT_ID, MyFrame::OnTextInputChanged)
    EVT_TIME_CHANGED(TIME_START_CTRL_ID, MyFrame::OnStartTimeSelected)
    EVT_TIME_CHANGED(TIME_END_CTRL_ID, MyFrame::OnEndTimeSelected)
    EVT_DATE_CHANGED(DATE_CTRL_ID, MyFrame::OnDateSelected)
    EVT_DATE_CHANGED(SEARCH_DATE_CTRL_ID, MyFrame::OnSearchDateChanged)
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
    rightPanel->SetBackgroundColour(wxColour("#025464"));

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
    textInput = new wxTextCtrl(leftPanel, TEXT_INPUT_ID, "", wxPoint(MARGIN_HORIZONTAL,currentPosY), wxSize(MyApp::windowWidth/2-MARGIN_HORIZONTAL*2,textInputHeight));
    textInput->SetBackgroundColour("#212148");
    textInput->SetHint("Inserisci la descrizione dell'attività");
    currentPosY += textInputHeight + 20;

    // Date picker
    new wxDatePickerCtrl(leftPanel, DATE_CTRL_ID, wxDefaultDateTime, wxPoint(MARGIN_HORIZONTAL, currentPosY), wxDefaultSize, wxDP_DEFAULT);
    currentPosY+=40;

    // Time picker (1)
    new wxStaticText(leftPanel, wxID_ANY, "Inizio:",wxPoint(MARGIN_HORIZONTAL,currentPosY));
    currentPosY += 20;
    new wxTimePickerCtrl(leftPanel, TIME_START_CTRL_ID, wxDefaultDateTime, wxPoint(MARGIN_HORIZONTAL, currentPosY), wxDefaultSize, wxDP_DEFAULT);
    currentPosY += 40;


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
    new wxDatePickerCtrl(rightPanel, SEARCH_DATE_CTRL_ID, wxDefaultDateTime, wxPoint(MARGIN_HORIZONTAL, currentPosY), wxDefaultSize, wxDP_DEFAULT);
    currentPosY+=40;

    // Crea una finestra con scorrimento
    auto scrollView = new MyScrollView(
            rightPanel,
            wxPoint(MARGIN_HORIZONTAL, currentPosY),
            wxSize(rightPanel->GetSize().GetWidth()-MARGIN_HORIZONTAL*2,rightPanel->GetSize().GetHeight()-pos.y-130),
            &activityManager, &myForm
            );

    scrollView->SetBackgroundColour("#026478");
}


///////////////////
////// EVENTI \\\\\\
\\\\\\\\\\\\\\\\\\\\

void MyFrame::OnExit(wxCommandEvent& event) {
    Close( true );
}

void MyFrame::OnAbout(wxCommandEvent& event) {
    wxMessageBox( "Registro di attività che memorizza cosa si è fatto durante una giornata. Classe che rappresenta attività con descrizione, tempo inizio e fine, Classe registro che colleziona attività su base del giorno.",
                  "About", wxOK | wxICON_INFORMATION );
}

void MyFrame::OnSubmitButtonClicked(wxCommandEvent &event) {

    std::cout << "submit button clicked" << std::endl;
    std::cout << "description: " << myForm.getDescription() << std::endl;
    std::cout << "start time: " << myForm.getStartTime() << std::endl;
    std::cout << "end time: " << myForm.getEndTime() << std::endl;
    std::cout << "Day:" << myForm.getDate().tm_mday<< std::endl;

    // Valida il form
    if(!myForm.validateForm()) {
        wxMessageBox("I dati inseriti non sono validi", "Errore", wxOK | wxICON_ERROR, this);
        return;
    }

    // Aggiunge la nuova attività
    std::time_t startTime = myForm.getStartTime();
    std::time_t endTime = myForm.getEndTime();
    std::tm date = myForm.getDate();


    activityManager.addActivity( new Activity(myForm.getDescription(), *std::localtime(&startTime), *std::localtime(&endTime)),date);

    // Resetta il formli
    myForm.setDescription("");
    textInput->Clear();

    // Notifica gli observer
    myForm.notifyObservers();

}

void MyFrame::OnTextInputChanged(wxCommandEvent &event) {
    myForm.setDescription(event.GetString().ToStdString());
    std::cout << event.GetString();
}


void MyFrame::OnStartTimeSelected(wxDateEvent &event) {
    auto date = event.GetDate();
    std::time_t timeT = Utils::convertWxDateTimeToTimeT(date);
    std::cout << date.GetHour() << date.GetMinute()  << std::endl;
    myForm.setStartTime(timeT);

}

void MyFrame::OnEndTimeSelected(wxDateEvent &event) {
    auto date = event.GetDate();
    std::time_t timeT = Utils::convertWxDateTimeToTimeT(date);
    std::cout << date.GetHour() << date.GetMinute()  << std::endl;
    myForm.setEndTime(timeT);
}

void MyFrame::OnDateSelected(wxDateEvent &event) {
    auto date = event.GetDate();
    std::tm timeT = Utils::convertWxDateTimeToTm(date);
    std::cout << date.GetDay() << "/" << date.GetMonth()<< "/" << date.GetYear()<< std::endl;
    myForm.setDate(timeT);
}

void MyFrame::OnSearchDateChanged(wxDateEvent &event) {
    auto date = event.GetDate();
    std::time_t timeT = Utils::convertWxDateTimeToTimeT(date);
    std::cout << date.GetDay() << "/" << date.GetMonth()<< "/" << date.GetYear()<< std::endl;
    myForm.setSearchDate(timeT);
}