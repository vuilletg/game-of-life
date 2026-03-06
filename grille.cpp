//
// Created by vuilletg on 2/13/26.
//
#include <iostream>
#include "grille.h"
#include <cstdlib>

// Dans grille.cpp
Grille::Grille(int m, int n) : m(m), n(n), plateau(m, std::vector<bool>(n, false)) {}

void Grille::affiche() const {
    std::cout.flush();
    for (int i = 0; i < m; ++i) {
        std::cout<<"_";
    }
    std::cout<<std::endl;
    for (int i = 0; i < m; ++i) {
        std::cout<<"|";
        for (int j = 0; j < n; ++j) {
            if (plateau[i][j]){
                std::cout<<"0";
            }else{
                std::cout<<" ";
            }
        }
        std::cout<<"|"<<std::endl;
    }
    for (int i = 0; i < m; ++i) {
        std::cout<<"_";
    }
}
bool Grille::estOccupe(int i, int j) const {return plateau[i][j];}
int Grille::nbVoisins(int i, int j) const {
    int res = 0;
    // On parcourt les cases de (i-1, j-1) à (i+1, j+1)
    for (int x = i - 1; x <= i + 1; ++x) {
        for (int y = j - 1; y <= j + 1; ++y) {
            if (x == i && y == j) continue;
            if (x >= 0 && x < m && y >= 0 && y < n) {
                if (plateau[x][y]) {
                    res++;
                }
            }
        }
    }
    return res;
}
void Grille::ajouter(int i, int j) {
    plateau[i][j]= true;
}
void Grille::suprimer(int i, int j) {
    plateau[i][j]= false;
}
Jeu::Jeu(int m, int n): Grille(m,n) {}

void Jeu::avance() {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!estOccupe(i,j)){
                if(nbVoisins(i,j)==3){
                    ajouter(i,j);
                }
            }else{
                if(nbVoisins(i,j)<=1 || nbVoisins(i,j)>=4){
                    suprimer(i,j);
                }
            }
        }
    }
}
