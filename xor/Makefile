# Le compilateur et ses options
CC = gcc
CPPFLAGS =
CFLAGS = -g -Wall -std=c99

# L'editeur de lien et ses options
LD = gcc
LDFLAGS =

# Librairies
LIBS = -lm

# Sources
SRCS = main.c

# Objets
OBJS = main.o

# But de la compilation
CIBLE = main

# Cible par defaut
all: $(CIBLE)

# Generation de la cible
$(CIBLE): $(OBJS)
	$(LD) $(LDFLAGS) $(OBJS) $(LIBS) -o $(CIBLE)

# Dependances
depend: $(SRCS)
	makedepend $(CPPFLAGS) $(SRCS)

# Nettoyage
clean:
	rm -f *.o core *~ *.exe $(CIBLE)

# Nettoyage simple
soft:
	rm -f *.o core *~
