//
// Created by vuilletg on 3/6/26.
//
#include <chrono>
#include <thread>
#include "fenetre.h"

Fenetre::Fenetre(const wxString &title, int m, int n)
        : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(1000, 1000)), m(m), n(n) {

    // 1. Initialiser les données AVANT l'interface
    j = new Jeu(m, n);
    matrice.resize(m, std::vector<wxButton *>(n));
    m_timer = new wxTimer(this, 100);

    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* controlSizer = new wxBoxSizer(wxHORIZONTAL);

    // 2. Création des boutons de contrôle avec des IDs explicites
    start = new wxButton(this, wxID_ANY, "Start");
    stop  = new wxButton(this, wxID_ANY, "Stop");
    clear = new wxButton(this, wxID_ANY, "Clear");

    stop->Enable(false);

    controlSizer->Add(start, 0, wxALL, 5);
    controlSizer->Add(stop, 0, wxALL, 5);
    controlSizer->Add(clear, 0, wxALL, 5);
    mainSizer->Add(controlSizer, 0, wxALIGN_CENTER | wxTOP, 10);

    // 3. Liaison des événements (on remplace la table d'événements)
    start->Bind(wxEVT_BUTTON, &Fenetre::SiStart, this);
    stop->Bind(wxEVT_BUTTON, &Fenetre::SiStop, this);
    clear->Bind(wxEVT_BUTTON, &Fenetre::SiClear, this);
    this->Bind(wxEVT_TIMER, &Fenetre::OnTimer, this, 100);

    // 4. Grille de boutons
    wxGridSizer* gridSizer = new wxGridSizer(m, n, 0, 0);

    for (int i = 0; i < m; ++i) {
        for (int k = 0; k < n; ++k) {
            // Utilisation d'un ID unique pour chaque bouton
            int btnId = (i * 100) + k;
            matrice[i][k] = new wxButton(this, btnId, wxEmptyString, wxDefaultPosition, wxSize(30, 30));
            matrice[i][k]->SetBackgroundColour(*wxWHITE);

            // Correction du Bind : on passe l'ID pour que matClick sache qui a cliqué
            matrice[i][k]->Bind(wxEVT_BUTTON, &Fenetre::matClick, this);

            gridSizer->Add(matrice[i][k], 1, wxEXPAND);
        }
    }

    mainSizer->Add(gridSizer, 1, wxEXPAND | wxALL, 20);
    this->SetSizer(mainSizer);
    this->Layout();
    this->Centre();
}

void Fenetre::update() {
    for (int i = 0; i < m; ++i) {
        for (int k = 0; k < n; ++k) {
            if(j->getGrille().estOccupe(i, k)) {
                matrice[i][k]->SetBackgroundColour(*wxBLACK);
            } else {
                matrice[i][k]->SetBackgroundColour(*wxWHITE);
            }
        }
    }
    this->Refresh();
}

void Fenetre::SiClear(wxCommandEvent &event) {
    for (int i = 0; i < m; ++i) {
        for (int k = 0; k < n; ++k) {
            j->getGrille().suprimer(i, k);
            matrice[i][k]->SetBackgroundColour(*wxWHITE);
        }
    }
    this->Refresh();
}

void Fenetre::matClick(wxCommandEvent &event) {
    int id = event.GetId();
    int click_i = id / 100;
    int click_k = id % 100;

    if (click_i >= 0 && click_i < m && click_k >= 0 && click_k < n) {
        if (j->getGrille().estOccupe(click_i, click_k)) {
            j->getGrille().suprimer(click_i, click_k);
        } else {
            j->getGrille().ajouter(click_i, click_k);
        }
        update();
    }
}

void Fenetre::SiStart(wxCommandEvent &event) {
    m_timer->Start(200);
    this->start->Enable(false);
    this->stop->Enable(true);
}

void Fenetre::SiStop(wxCommandEvent &event) {
    m_timer->Stop();
    this->start->Enable(true);
    this->stop->Enable(false);
}
void Fenetre::OnTimer(wxTimerEvent& event) {
    j->avance();
    update();
    this->update();
}

BEGIN_EVENT_TABLE(Fenetre, wxFrame
)

EVT_BUTTON(1, Fenetre::SiStart)
EVT_BUTTON(2, Fenetre::SiStop)
EVT_BUTTON(3, Fenetre::SiClear)
EVT_TIMER(100, Fenetre::OnTimer)

END_EVENT_TABLE()