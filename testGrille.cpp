//
// Created by vuilletg on 2/13/26.
//
// Source - https://stackoverflow.com/a/10613664
// Posted by HighCommander4, modified by community. See post 'Timeline' for change history
// Retrieved 2026-02-13, License - CC BY-SA 3.0

#include <chrono>
#include <thread>

#include "grille.h"
int main(){
    Jeu *j = new Jeu(40,400);
    j->ajouter(1,2);
    while(1){
        j->affiche();
        j->avance();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}