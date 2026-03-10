CC=g++
CFLAGS= -Wall -Werror
CXXFLAGS=`wx-config --cxxflags`
LDLIBS=`wx-config --libs`

all: main

# On ajoute grille.o aux dépendances de main
main: testGrilleGraphique.o fenetre.o grille.o
	$(CC) $(CFLAGS) $(CXXFLAGS) $^ $(LDLIBS) -o $@ --save-temps

# Règle pour compiler testGrilleGraphique.o
testGrilleGraphique.o: testGrilleGraphique.cpp testGrilleGraphique.h
	$(CC) $(CFLAGS) $(CXXFLAGS) -c -o $@ $<

# Ta règle existante pour fenetre.o
fenetre.o: fenetre.cpp fenetre.h grille.h
	$(CC) $(CFLAGS) $(CXXFLAGS) -c -o $@ $<

# NOUVELLE RÈGLE pour compiler grille.o
grille.o: grille.cpp grille.h
	$(CC) $(CFLAGS) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -rf *.o *.s *.ii main