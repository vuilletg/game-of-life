CC=g++
CFLAGS=-Wall -O0 -g3 -I. -MMD -MP -Werror

PROG=testGrille

# Sources et objets
testGrille_SRCS := testGrille.cpp grille.cpp
testGrille_OBJS := $(testGrille_SRCS:.cpp=.o)

# Fichiers .d générés
DEPS := $(testGrille_SRCS:.cpp=.d)

# Cible par défaut
all: $(PROG)

# Règle pour le programme final
$(PROG): $(testGrille_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Règle pour les fichiers objets
%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ -c $<

# Inclusion des dépendances
-include $(DEPS)

# Nettoyage
clean:
	rm -rf *.o *.d $(PROG)

.PHONY: all clean