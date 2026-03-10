//
// Created by vuilletg on 2/13/26.
//
#include <vector>

#ifndef TP3_GRILLE_H
#define TP3_GRILLE_H


class Grille {
    int m;
    int n;
    std::vector<std::vector<bool>> plateau;
public:
    Grille(int m , int n);
    int getM();
    int getN();
    void ajouter(int i, int j);
    void suprimer(int i, int j);
    void affiche ()const;
    bool estOccupe(int i, int j) const;
    int nbVoisins (int i, int j)const;
};
class Jeu{
    Grille grille;
public:
    Grille& getGrille();
    Jeu(int m , int n);
    void avance();
};


#endif //TP3_GRILLE_H
