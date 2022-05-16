#ifndef FUNKCJE_H
#define FUNKCJE_H

#include <SFML/Graphics.hpp>

int sprawdzanie_ruchu(int tablica[8][8], int x, int y, int grana, int przeciwna);
void resetowaniegry(int tablica[8][8]);
int wstawianie(int tablica[8][8], int x, int y, int grana, int przeciwna);
int sprawdzanieGry(int tablica[8][8], int grana);
int zliczanie_punktow(int tablica[8][8], int zwyciezca[2]);
int wstawianie_bot(int tablica[8][8], int x, int y, int grana, int przeciwna);
void *bot(int grana, int przeciwna, int tablica[8][8], int *ruch_x, int *ruch_y);

#endif
