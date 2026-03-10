//
// Created by vuilletg on 3/6/26.
//

#include "testGrilleGraphique.h"
#include "fenetre.h"
bool MyApp::OnInit() {
    Fenetre *fenetre = new Fenetre
            (wxT("game of life"),50,50);
    fenetre->Show(true);
    return true;
}
wxIMPLEMENT_APP(MyApp);