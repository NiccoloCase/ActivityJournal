//
// Created by Niccolò Caselli on 14/06/23.
//

#include "MyApp.h"
#include "MyFrame.h"


int MyApp::windowWidth = 600;
int MyApp::windowHeight = 500;
std::string MyApp::appName = "Activity Journal";

bool MyApp::OnInit() {
    auto frame = new MyFrame( appName, wxPoint(50, 50), wxSize(windowWidth, windowHeight) );
    frame->Show( true );

    return true;
}


wxIMPLEMENT_APP(MyApp);