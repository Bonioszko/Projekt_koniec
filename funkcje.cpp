#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include <math.h>
#include <stdlib.h>
#include "funkcje.h"
int sprawdzanie_ruchu(int tablica[8][8], int x, int y, int grana, int przeciwna)
{
    int pomoc = 0;
    int i;
    i = x;
    int j;
    j = y;
    // gora
    while ((i - 2) >= 0 && tablica[i - 1][j] == przeciwna)
    {
        i--;
        if (tablica[i - 1][j] == grana)
        {
            pomoc = 1;
            break;
        }
    }
    i = x;
    j = y;
    // dol
    while ((i + 2) < 8 && tablica[i + 1][j] == przeciwna)
    {
        i++;
        if (tablica[i + 1][j] == grana)
        {

            pomoc = 1;
            break;
        }
    }
    i = x;
    j = y;
    // prawo
    while ((j + 2) < 8 && tablica[i][j + 1] == przeciwna)
    {
        j++;
        if (tablica[i][j + 1] == grana)
        {

            pomoc = 1;
            break;
        }
    }

    i = x;
    j = y;
    // lewo
    while ((j - 2) >= 0 && tablica[i][j - 1] == przeciwna)
    {
        j--;
        if (tablica[i][j - 1] == grana)
        {

            pomoc = 1;
            break;
        }
    }

    i = x;
    j = y;
    // lewo gora
    while ((i - 2) >= 0 && (j - 2) >= 0 && tablica[i - 1][j - 1] == przeciwna)
    {
        i--;
        j--;
        if (tablica[i - 1][j - 1] == grana)
        {

            pomoc = 1;
            break;
        }
    }

    i = x;
    j = y;
    // prawo dol
    while ((i + 2) < 8 && (j + 2) < 8 && tablica[i + 1][j + 1] == przeciwna)
    {

        i++;
        j++;
        if (tablica[i + 1][j + 1] == grana)
        {

            pomoc = 1;

            break;
        }
    }

    i = x;
    j = y;
    // prawo gora
    while ((i - 2) >= 0 && (j + 2) < 8 && tablica[i - 1][j + 1] == przeciwna)
    {
        i--;
        j++;
        if (tablica[i - 1][j + 1] == grana)
        {

            pomoc = 1;
            break;
        }
    }

    i = x;
    j = y;
    // lewo dol
    while ((i + 2) < 8 && (j - 2) >= 0 && tablica[i + 1][j - 1] == przeciwna)
    {
        i++;
        j--;
        if (tablica[i + 1][j - 1] == grana)
        {

            pomoc = 1;
            break;
        }
    }

    if (pomoc == 1)
        return 1;
    else
        return 0;
}

void resetowaniegry(int tablica[8][8])
{

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            tablica[i][j] = 0;
        }
    }

    tablica[3][3] = 2;
    tablica[3][4] = 1;
    tablica[4][3] = 1;
    tablica[4][4] = 2;
}
int wstawianie(int tablica[8][8], int x, int y, int grana, int przeciwna)
{
    int value = 0;
    int pomoc = 0;
    int pomoc1 = 0;
    int p;
    int i;
    i = x;
    int j;
    j = y;
    // gora
    while ((i - 2) >= 0 && tablica[i - 1][j] == przeciwna)
    {
        i--;
        if (tablica[i - 1][j] == grana)
        {
            pomoc1 = 1;
            pomoc = 1;
            break;
        }
    }
    if (pomoc == 1)
    {
        for (int c = i; c < x; c++)
        {
            tablica[c][j] = grana;
            value += 1;
        }
    }
    pomoc = 0;
    i = x;
    j = y;
    // dol
    while ((i + 2) < 8 && tablica[i + 1][j] == przeciwna)
    {
        i++;
        if (tablica[i + 1][j] == grana)
        {
            pomoc1 = 1;
            pomoc = 1;
            break;
        }
    }
    if (pomoc == 1)
    {
        for (int c = x + 1; c <= i; c++)
        {
            tablica[c][j] = grana;
            value += 1;
        }
    }
    pomoc = 0;
    i = x;
    j = y;
    // prawo
    while ((j + 2) < 8 && tablica[i][j + 1] == przeciwna)
    {
        j++;
        if (tablica[i][j + 1] == grana)
        {
            pomoc1 = 1;
            pomoc = 1;
            break;
        }
    }
    if (pomoc == 1)
    {
        for (int c = y + 1; c <= j; c++)
        {
            tablica[i][c] = grana;
            value += 1;
        }
    }
    pomoc = 0;
    i = x;
    j = y;
    // lewo
    while ((j - 2) >= 0 && tablica[i][j - 1] == przeciwna)
    {
        j--;
        if (tablica[i][j - 1] == grana)
        {
            pomoc1 = 1;
            pomoc = 1;
            break;
        }
    }
    if (pomoc == 1)
    {
        for (int c = j; c <= y; c++)
        {
            tablica[x][c] = grana;
            value += 1;
        }
    }
    pomoc = 0;
    i = x;
    j = y;
    // lewo gora
    while ((i - 2) >= 0 && (j - 2) >= 0 && tablica[i - 1][j - 1] == przeciwna)
    {
        i--;
        j--;
        if (tablica[i - 1][j - 1] == grana)
        {
            pomoc1 = 1;
            pomoc = 1;
            break;
        }
    }
    if (pomoc == 1)
    {
        p = j;
        for (int c = i; c <= x; c++)
        {
            tablica[c][p] = grana;
            p++;
            value += 1;
        }
    }
    pomoc = 0;
    i = x;
    j = y;
    // prawo dol
    while ((i + 2) < 8 && (j + 2) < 8 && tablica[i + 1][j + 1] == przeciwna)
    {

        i++;
        j++;
        if (tablica[i + 1][j + 1] == grana)
        {
            pomoc1 = 1;
            pomoc = 1;

            break;
        }
    }

    if (pomoc == 1)
    {

        p = y + 1;
        for (int c = x + 1; c <= i; c++)
        {

            tablica[c][p] = grana;
            p++;
            value += 1;
        }
    }
    pomoc = 0;
    i = x;
    j = y;
    // prawo gora
    while ((i - 2) >= 0 && (j + 2) < 8 && tablica[i - 1][j + 1] == przeciwna)
    {
        i--;
        j++;
        if (tablica[i - 1][j + 1] == grana)
        {
            pomoc1 = 1;
            pomoc = 1;
            break;
        }
    }
    if (pomoc == 1)
    {
        p = j;
        for (int c = i; c < x; c++)
        {
            tablica[c][p] = grana;
            p--;
            value += 1;
        }
    }
    pomoc = 0;
    i = x;
    j = y;
    // lewo dol
    while ((i + 2) < 8 && (j - 2) >= 0 && tablica[i + 1][j - 1] == przeciwna)
    {
        i++;
        j--;
        if (tablica[i + 1][j - 1] == grana)
        {
            pomoc1 = 1;
            pomoc = 1;
            break;
        }
    }
    if (pomoc == 1)
    {
        p = j;
        for (int c = i; c > x; c--)
        {
            tablica[c][p] = grana;
            p++;
            value += 1;
        }
    }

    if (pomoc1 == 1)
    {
        tablica[x][y] = grana;
        value += 1;
    }
    return value;
}
int sprawdzanieGry(int tablica[8][8], int grana)
{
    int licznik = 0;
    int licznikruchowB = 0;
    int licznikruchowC = 0;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (tablica[i][j] == 1 || tablica[i][j] == 2)
            {
                licznik = licznik + 1;
            }
        }
    }

    if (licznik == 64)
    {

        return 1;
    }
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (sprawdzanie_ruchu(tablica, i, j, 1, 2) == 1 && tablica[i][j] != 1 && tablica[i][j] != 2)
            {
                licznikruchowC += 1;
            }
            if (sprawdzanie_ruchu(tablica, i, j, 2, 1) == 1 && tablica[i][j] != 1 && tablica[i][j] != 2)
            {
                licznikruchowB += 1;
            }
        }
    }
    if (licznikruchowC + licznikruchowB == 0)
    {

        return 1;
    }
    else if (licznikruchowB == 0 && grana == 2)
    {

        return 2;
    }
    else if (licznikruchowC == 0 && grana == 1)
    {

        return 3;
    }
    // printf("%d\n", licznikruchowB);
    // printf("%d\n", licznikruchowC);
    return 0;
}
// jesli wygraja czarni zwraca 1 , jesli biali 2, remis 0
int zliczanie_punktow(int tablica[8][8], int zwyciezca[2])
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (tablica
                    [i][j] == 1)
                zwyciezca[0] = zwyciezca[0] + 1;
            if (tablica
                    [i][j] == 2)
                zwyciezca[1] = zwyciezca[1] + 1;
        }
    }
    if (zwyciezca[0] > zwyciezca[1])
        return 1;
    else if (zwyciezca[0] == zwyciezca[1])
    {
        return 0;
    }
    else
    {
        return 2;
    }
}
int wstawianie_bot(int tablica[8][8], int x, int y, int grana, int przeciwna)
{
    int value = 0;
    int pomoc = 0;
    int pomoc1 = 0;
    int p;
    int i;
    i = x;
    int j;
    j = y;
    // gora
    while ((i - 2) >= 0 && tablica[i - 1][j] == przeciwna)
    {
        i--;
        if (tablica[i - 1][j] == grana)
        {
            pomoc1 = 1;
            pomoc = 1;
            break;
        }
    }
    if (pomoc == 1)
    {
        for (int c = i; c < x; c++)
        {

            value += 1;
        }
    }
    pomoc = 0;
    i = x;
    j = y;
    // dol
    while ((i + 2) < 8 && tablica[i + 1][j] == przeciwna)
    {
        i++;
        if (tablica[i + 1][j] == grana)
        {
            pomoc1 = 1;
            pomoc = 1;
            break;
        }
    }
    if (pomoc == 1)
    {
        for (int c = x + 1; c <= i; c++)
        {
            value += 1;
        }
    }
    pomoc = 0;
    i = x;
    j = y;
    // prawo
    while ((j + 2) < 8 && tablica[i][j + 1] == przeciwna)
    {
        j++;
        if (tablica[i][j + 1] == grana)
        {
            pomoc1 = 1;
            pomoc = 1;
            break;
        }
    }
    if (pomoc == 1)
    {
        for (int c = y + 1; c <= j; c++)
        {

            value += 1;
        }
    }
    pomoc = 0;
    i = x;
    j = y;
    // lewo
    while ((j - 2) >= 0 && tablica[i][j - 1] == przeciwna)
    {
        j--;
        if (tablica[i][j - 1] == grana)
        {
            pomoc1 = 1;
            pomoc = 1;
            break;
        }
    }
    if (pomoc == 1)
    {
        for (int c = j; c <= y; c++)
        {

            value += 1;
        }
    }
    pomoc = 0;
    i = x;
    j = y;
    // lewo gora
    while ((i - 2) >= 0 && (j - 2) >= 0 && tablica[i - 1][j - 1] == przeciwna)
    {
        i--;
        j--;
        if (tablica[i - 1][j - 1] == grana)
        {
            pomoc1 = 1;
            pomoc = 1;
            break;
        }
    }
    if (pomoc == 1)
    {
        p = j;
        for (int c = i; c <= x; c++)
        {

            p++;
            value += 1;
        }
    }
    pomoc = 0;
    i = x;
    j = y;
    // prawo dol
    while ((i + 2) < 8 && (j + 2) < 8 && tablica[i + 1][j + 1] == przeciwna)
    {

        i++;
        j++;
        if (tablica[i + 1][j + 1] == grana)
        {
            pomoc1 = 1;
            pomoc = 1;

            break;
        }
    }

    if (pomoc == 1)
    {

        p = y + 1;
        for (int c = x + 1; c <= i; c++)
        {

            p++;
            value += 1;
        }
    }
    pomoc = 0;
    i = x;
    j = y;
    // prawo gora
    while ((i - 2) >= 0 && (j + 2) < 8 && tablica[i - 1][j + 1] == przeciwna)
    {
        i--;
        j++;
        if (tablica[i - 1][j + 1] == grana)
        {
            pomoc1 = 1;
            pomoc = 1;
            break;
        }
    }
    if (pomoc == 1)
    {
        p = j;
        for (int c = i; c < x; c++)
        {

            p--;
            value += 1;
        }
    }
    pomoc = 0;
    i = x;
    j = y;
    // lewo dol
    while ((i + 2) < 8 && (j - 2) >= 0 && tablica[i + 1][j - 1] == przeciwna)
    {
        i++;
        j--;
        if (tablica[i + 1][j - 1] == grana)
        {
            pomoc1 = 1;
            pomoc = 1;
            break;
        }
    }
    if (pomoc == 1)
    {
        p = j;
        for (int c = i; c > x; c--)
        {

            p++;
            value += 1;
        }
    }

    if (pomoc1 == 1)
    {

        value += 1;
    }
    return value;
}
void *bot(int grana, int przeciwna, int tablica[8][8], int *ruch_x, int *ruch_y)
{

    int ruch = 0;
    *ruch_x = 0;
    *ruch_y = 0;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (wstawianie_bot(tablica, i, j, grana, przeciwna) > ruch && tablica[i][j] != 1 && tablica[i][j] != 2)
            {
                *ruch_x = i;
                *ruch_y = j;
            }
        }
    }
}
