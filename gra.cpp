#include <SFML/Graphics.hpp>
#include <math.h>
#include <stdlib.h>
#include "funkcje.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 800), "SFML works!");
    sf::RectangleShape pole;
    sf::RectangleShape przycisk;
    sf::CircleShape pionekbialy;
    sf::CircleShape pionekczarny;
    sf::CircleShape pionekczarny1;
    sf::Font font;
    font.loadFromFile("arial.ttf");
    sf::Text black("BLACK", font);
    sf::Text white("WHITE", font);
    sf::Text whiteZ("WHITE WON", font);
    sf::Text blackZ("BLACK WON", font);
    sf::Text draw("DRAW", font);
    sf::Text Bot("Gra z botem", font);
    sf::Text gracz("Gra 1vs1", font);

    Bot.setFillColor(sf::Color::White);
    Bot.setCharacterSize(100);

    gracz.setFillColor(sf::Color::White);
    gracz.setCharacterSize(100);

    white.setFillColor(sf::Color::White);
    white.setCharacterSize(40);

    whiteZ.setFillColor(sf::Color::White);
    whiteZ.setCharacterSize(100);

    black.setFillColor(sf::Color::Black);
    black.setCharacterSize(40);
    black.setOutlineColor(sf::Color::White);
    black.setOutlineThickness(2);

    blackZ.setFillColor(sf::Color::Black);
    blackZ.setCharacterSize(100);
    blackZ.setOutlineColor(sf::Color::White);
    blackZ.setOutlineThickness(2);

    draw.setFillColor(sf::Color::Black);
    draw.setCharacterSize(100);
    draw.setOutlineColor(sf::Color::White);
    draw.setOutlineThickness(2);

    przycisk.setSize(sf::Vector2f(300, 150));
    przycisk.setOutlineColor(sf::Color::White);
    pole.setOutlineColor(sf::Color::White);
    pole.setSize(sf::Vector2f(100, 100));
    pole.setFillColor(sf::Color{0, 255, 0, 130});
    pole.setOutlineColor(sf::Color::Black);
    pionekbialy.setRadius(45);
    pionekbialy.setPointCount(1000000);
    pionekczarny.setRadius(45);
    pionekczarny.setPointCount(1000000);
    pionekbialy.setFillColor(sf::Color::White);
    pionekczarny.setFillColor(sf::Color::Black);
    pionekczarny1.setRadius(45);
    pionekczarny1.setPointCount(1000000);
    pionekczarny1.setFillColor(sf::Color::Black);
    pionekczarny1.setOutlineColor(sf::Color::White);
    pionekczarny1.setOutlineThickness(2);
    pole.setOutlineThickness(1);
    pole.setPosition(10, 10);
    int tablica[8][8];
    int ruchy = rand() % 2 + 1;
    printf("%d", ruchy);
    int tury = 0;
    int zwyciezca[2];
    zwyciezca[0] = 0;
    zwyciezca[1] = 0;
    int tura = rand() % 2 + 1;
    int state = 0;
    resetowaniegry(tablica);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                int x = mousePos.x;
                int y = mousePos.y;

                if (state == 0)
                {
                    int a = 0;
                    if (x > 300 && x < 600 && y > 100 && y < 250)
                    {
                        state = 1;
                    }
                    else if (x > 300 && x < 600 && y > 400 && y < 550)
                    {
                        state = 2;
                    }
                }
                else if (state == 1)
                {

                    int z = 1;
                    if (ruchy == 1)
                    {
                        z = 2;
                    }
                    if (ruchy == 2)
                    {
                        z = 1;
                    }

                    if (sprawdzanie_ruchu(tablica, x / 100, y / 100, ruchy, z) == 1 && tablica[x][y] != 1 && tablica[x][y] != 2)
                    {
                        wstawianie(tablica, x / 100, y / 100, ruchy, z);

                        if (ruchy == 1)
                            ruchy = 2;
                        else
                            ruchy = 1;
                    }
                }
                else if (state == 2)
                {
                    if (tura == 1)
                    {
                        int z = 1;
                        if (ruchy == 1)
                        {
                            z = 2;
                        }
                        if (ruchy == 2)
                        {
                            z = 1;
                        }

                        if (sprawdzanie_ruchu(tablica, x / 100, y / 100, ruchy, z) == 1 && tablica[x][y] != 1 && tablica[x][y] != 2)
                        {

                            wstawianie(tablica, x / 100, y / 100, ruchy, z);

                            if (ruchy == 1)
                                ruchy = 2;
                            else
                                ruchy = 1;
                        }

                        tura = 2;
                    }
                    else if (tura == 2)
                    {
                        int ruch_x;
                        int ruch_y;
                        int t = 1;
                        if (ruchy == 1)
                        {
                            t = 2;
                        }
                        if (ruchy == 2)
                        {
                            t = 1;
                        }
                        bot(ruchy, t, tablica, &ruch_x, &ruch_y);
                        if (sprawdzanie_ruchu(tablica, ruch_x, ruch_y, ruchy, t) == 1 && tablica[x][y] != 1 && tablica[x][y] != 2)
                        {
                            wstawianie(tablica, x, y, ruchy, t);

                            if (ruchy == 1)
                                ruchy = 2;
                            else
                                ruchy = 1;
                        }
                    }

                    window.clear();
                }
            }
            window.clear();
            if (state == 0)
            {
                przycisk.setPosition(300, 100);
                window.draw(przycisk);
                gracz.setPosition(300, 100);
                window.draw(gracz);

                przycisk.setPosition(300, 400);
                window.draw(przycisk);
                Bot.setPosition(300, 400);
                window.draw(Bot);
            }

            else if (state == 1)
            {

                if (sprawdzanieGry(tablica, ruchy) == 1)
                {
                    if (zliczanie_punktow(tablica, zwyciezca) == 2)
                    {
                        ruchy = 0;
                        window.clear();
                        whiteZ.setPosition(225, 300);
                        window.draw(whiteZ);
                    }
                    else if (zliczanie_punktow(tablica, zwyciezca) == 1)
                    {
                        ruchy = 0;
                        window.clear();
                        blackZ.setPosition(225, 300);
                        window.draw(blackZ);
                    }

                    else
                    {
                        ruchy = 0;
                        window.clear();
                        draw.setPosition(300, 300);
                        window.draw(draw);
                    }
                }
                else if (sprawdzanieGry(tablica, ruchy) == 2)
                {
                    ruchy = 1;
                }
                else if (sprawdzanieGry(tablica, ruchy) == 3)
                {
                    ruchy = 2;
                }

                if (ruchy == 2)
                {
                    white.setPosition(840, 300);
                    pionekbialy.setPosition(860, 350);
                    window.draw(white);
                    window.draw(pionekbialy);
                }
                if (ruchy == 1)
                {
                    black.setPosition(840, 300);
                    pionekczarny1.setPosition(860, 350);
                    window.draw(black);
                    window.draw(pionekczarny1);
                }
                if (ruchy == 1 || ruchy == 2)
                {
                    for (int i = 0; i < 8; i++)
                    {
                        for (int j = 0; j < 8; j++)
                        {
                            pole.setPosition(i * 100, j * 100);
                            window.draw(pole);
                            if (tablica[i][j] == 2)
                            {
                                pionekbialy.setPosition(i * 100 + 5, j * 100 + 5);
                                window.draw(pionekbialy);
                            }
                            if (tablica[i][j] == 1)
                            {
                                pionekczarny.setPosition(i * 100 + 5, j * 100 + 5);
                                window.draw(pionekczarny);
                            }
                        }
                    }
                }
            }
            else if (state == 2)
            {

                if (sprawdzanieGry(tablica, ruchy) == 1)
                {
                    if (zliczanie_punktow(tablica, zwyciezca) == 2)
                    {
                        ruchy = 0;
                        window.clear();
                        whiteZ.setPosition(225, 300);
                        window.draw(whiteZ);
                    }
                    else if (zliczanie_punktow(tablica, zwyciezca) == 1)
                    {
                        ruchy = 0;
                        window.clear();
                        blackZ.setPosition(225, 300);
                        window.draw(blackZ);
                    }

                    else
                    {
                        ruchy = 0;
                        window.clear();
                        draw.setPosition(300, 300);
                        window.draw(draw);
                    }
                }
                else if (sprawdzanieGry(tablica, ruchy) == 2)
                {
                    ruchy = 1;
                }
                else if (sprawdzanieGry(tablica, ruchy) == 3)
                {
                    ruchy = 2;
                }

                if (ruchy == 2)
                {
                    white.setPosition(840, 300);
                    pionekbialy.setPosition(860, 350);
                    window.draw(white);
                    window.draw(pionekbialy);
                }
                if (ruchy == 1)
                {
                    black.setPosition(840, 300);
                    pionekczarny1.setPosition(860, 350);
                    window.draw(black);
                    window.draw(pionekczarny1);
                }
                if (ruchy == 1 || ruchy == 2)
                {
                    for (int i = 0; i < 8; i++)
                    {
                        for (int j = 0; j < 8; j++)
                        {
                            pole.setPosition(i * 100, j * 100);
                            window.draw(pole);
                            if (tablica[i][j] == 2)
                            {
                                pionekbialy.setPosition(i * 100 + 5, j * 100 + 5);
                                window.draw(pionekbialy);
                            }
                            if (tablica[i][j] == 1)
                            {
                                pionekczarny.setPosition(i * 100 + 5, j * 100 + 5);
                                window.draw(pionekczarny);
                            }
                        }
                    }
                }
            }
        }
        window.display();
    }

    return 0;
}