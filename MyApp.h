//
// Created by Niccolò Caselli on 14/06/23.
//

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif


#ifndef ACTIVITYJOURNAL_MYAPP_H
#define ACTIVITYJOURNAL_MYAPP_H


class MyApp: public wxApp   {
public:
    bool OnInit() override;

    static int windowWidth;
    static int windowHeight;
    static std::string appName;
};



#endif //ACTIVITYJOURNAL_MYAPP_H
