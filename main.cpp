
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#include <wx/datectrl.h>

#endif

class MyApp: public wxApp   {
    public:
        virtual bool OnInit();

        static int windowWidth;
        static int windowHeight;
        static std::string appName;
};

class MyFrame: public wxFrame {
    public:
        MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
    private:
        void OnExit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);

        wxDECLARE_EVENT_TABLE();




};


enum {
    ID_Hello = 1
};

wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
EVT_MENU(wxID_EXIT,  MyFrame::OnExit)
EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
wxEND_EVENT_TABLE()
wxIMPLEMENT_APP(MyApp);



int MyApp::windowWidth = 600;
int MyApp::windowHeight = 500;
std::string MyApp::appName = "Nome applicazione";

bool MyApp::OnInit() {


    MyFrame *frame = new MyFrame( "Hello World", wxPoint(50, 50), wxSize(windowWidth, windowHeight) );


    frame->Show( true );

    return true;
}





MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
        : wxFrame(NULL, wxID_ANY, title, pos, size, wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER | wxMAXIMIZE_BOX)) {


    // Crea la barra di stato
    CreateStatusBar();
    SetStatusText( MyApp::appName);


    auto leftPanel = new wxPanel(this,wxID_ANY,wxPoint(0,0), wxSize(MyApp::windowWidth/2,MyApp::windowHeight));
    leftPanel->SetBackgroundColour(wxColour("#1B1B3A"));

    auto rightPanel = new wxPanel(this,wxID_ANY,wxPoint(MyApp::windowWidth/2,0), wxSize(MyApp::windowWidth/2,MyApp::windowHeight));
    rightPanel->SetBackgroundColour(wxColour("orange"));

    // LATO SINISTRO

    // titolo
    auto titleText = new wxStaticText(leftPanel, wxID_ANY, "Cosa hai fatto oggi?",wxPoint(20,20));
    auto font = titleText->GetFont();
    font.SetPointSize(20);
    titleText->SetFont(font);

    
    auto input = new wxTextCtrl(leftPanel, wxID_ANY, "", wxPoint(20,40), wxSize(200,100));
    input->SetBackgroundColour("#693668");
    input->SetHint("Inserisci la descrizione dell'attività");

    new wxButton(leftPanel, wxID_ANY, "Aggiungi attività",wxPoint(0,100),wxSize(200, 30));


    // LATO DESTRO
    new wxDatePickerCtrl(rightPanel, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT);


}

void MyFrame::OnExit(wxCommandEvent& event) {
    Close( true );
}

void MyFrame::OnAbout(wxCommandEvent& event) {
    wxMessageBox( "This is a wxWidgets' Hello world sample",
                  "About Hello World", wxOK | wxICON_INFORMATION );
}

