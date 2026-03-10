//
// Created by vuilletg on 3/6/26.
//

#ifndef TP3_FENETRE_H
#define TP3_FENETRE_H

#include <wx/wx.h>
#include "grille.h"
class Fenetre : public wxFrame{
    Jeu *j ;
    int m;
    int n;
    bool test = true;
    std::vector<std::vector<wxButton*>> matrice;
    void update();
    wxTimer* m_timer; // Ajoute ça
    void OnTimer(wxTimerEvent& event);
public:
    Fenetre(const wxString& title, int m, int n);
    wxButton * start;
    wxButton * stop;
    wxButton * clear;

    void SiStart (wxCommandEvent& event );
    void SiStop (wxCommandEvent& event );
    void SiClear(wxCommandEvent& event );
    void matClick (wxCommandEvent& event);

    DECLARE_EVENT_TABLE()
};


#endif //TP3_FENETRE_H
