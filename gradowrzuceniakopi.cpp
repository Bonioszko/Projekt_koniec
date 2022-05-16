#include <SFML/Graphics.hpp>
#include <math.h>
#include <stdlib.h>
#include "funkcje.h"
int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 800), "SFML works!");
    sf::RectangleShape pole;
    sf::RectangleShape przycisk;
    sf::RectangleShape przycisk1;
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
    sf::Text napis_bot("Tura bota", font);
    sf::Text napis_gracz("Tura gracza", font);

    napis_bot.setFillColor(sf::Color::White);
    napis_bot.setCharacterSize(30);

    napis_gracz.setFillColor(sf::Color::White);
    napis_gracz.setCharacterSize(30);

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

    przycisk.setSize(sf::Vector2f(500, 150));
    przycisk.setOutlineColor(sf::Color::White);
    przycisk.setOutlineThickness(2);
    przycisk.setFillColor(sf::Color::Black);

    przycisk1.setSize(sf::Vector2f(600, 150));
    przycisk1.setOutlineColor(sf::Color::White);
    przycisk1.setOutlineThickness(2);
    przycisk1.setFillColor(sf::Color::Black);
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

    int tablica[8][8];
    int ruchy = rand() % 2 + 1;

    int tury = 0;
    int zwyciezca[2];
    zwyciezca[0] = 0;
    zwyciezca[1] = 0;
    int state = 0;
    int koniec = 1;
    int tura = rand() % 2 + 1;
    resetowaniegry(tablica);
    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                int x = mousePos.x;
                int y = mousePos.y;

                if (koniec == 0)
                {
                    state = 0;
                    koniec = 1;
                    resetowaniegry(tablica);
                    ruchy = rand() % 2 + 1;
                    tura = rand() % 2 + 1;
                }
                if (state == 0)
                {
                    int a = 0;
                    if (x > 200 && x < 800 && y > 155 && y < 305)
                    {
                        state = 1;
                    }
                    else if (x > 200 && x < 800 && y > 455 && y < 605)
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

                    if (sprawdzanie_ruchu(tablica, x / 100, y / 100, ruchy, z) == 1 && tablica[x / 100][y / 100] != 1 && tablica[x / 100][y / 100] != 2)
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

                        if (sprawdzanie_ruchu(tablica, x / 100, y / 100, ruchy, z) == 1 && tablica[x / 100][y / 100] != 1 && tablica[x / 100][y / 100] != 2)
                        {
                            wstawianie(tablica, x / 100, y / 100, ruchy, z);

                            if (ruchy == 1)
                            {
                                ruchy = 2;
                                tura = 2;
                            }
                            else
                            {
                                ruchy = 1;
                                tura = 2;
                            }
                        }
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
                        if (sprawdzanie_ruchu(tablica, ruch_x, ruch_y, ruchy, t) == 1 && tablica[ruch_x][ruch_y] != 1 && tablica[ruch_x][ruch_y] != 2)
                        {
                            wstawianie(tablica, ruch_x, ruch_y, ruchy, t);

                            if (ruchy == 1)
                            {
                                ruchy = 2;
                                tura = 1;
                            }
                            else
                            {
                                ruchy = 1;
                                tura = 1;
                            }
                        }
                    }
                }
            }
        }
        window.clear();
        if (state == 0)
        // zmienic te klikanie w przicyski
        {
            auto bounds = przycisk1.getLocalBounds();
            przycisk1.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
            przycisk1.setPosition(500, 230);
            window.draw(przycisk1);
            bounds = gracz.getLocalBounds();
            gracz.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
            gracz.setPosition(500, 200);
            window.draw(gracz);

            bounds = przycisk1.getLocalBounds();
            przycisk1.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
            przycisk1.setPosition(500, 530);
            window.draw(przycisk1);
            bounds = Bot.getLocalBounds();
            Bot.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
            Bot.setPosition(500, 500);
            window.draw(Bot);
        }

        if (state == 1)
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
                    draw.setPosition(330, 300);
                    window.draw(draw);
                }
                koniec = 0;
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
                    tura = 0;
                    window.clear();
                    whiteZ.setPosition(225, 300);
                    window.draw(whiteZ);
                }
                else if (zliczanie_punktow(tablica, zwyciezca) == 1)
                {
                    ruchy = 0;
                    tura = 0;
                    window.clear();
                    blackZ.setPosition(225, 300);
                    window.draw(blackZ);
                }

                else
                {
                    ruchy = 0;
                    tura = 0;
                    window.clear();
                    draw.setPosition(300, 300);
                    window.draw(draw);
                }
                koniec = 0;
            }
            else if (sprawdzanieGry(tablica, ruchy) == 2)
            {
                ruchy = 1;
                if (tura == 2)
                {
                    tura = 1;
                }
                else
                {
                    tura = 2;
                }
            }
            else if (sprawdzanieGry(tablica, ruchy) == 3)
            {
                ruchy = 2;
                if (tura == 2)
                {
                    tura = 1;
                }
                else
                {
                    tura = 2;
                }
            }
            if (tura == 2)
            {
                napis_bot.setPosition(840, 240);
                window.draw(napis_bot);
            }
            else if (tura == 1)
            {
                napis_gracz.setPosition(820, 240);
                window.draw(napis_gracz);
            }
            if (ruchy == 2)
            {
                white.setPosition(840, 300);
                pionekbialy.setPosition(860, 350);
                window.draw(white);
                window.draw(pionekbialy);
            }
            else if (ruchy == 1)
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
        window.display();
    }
    return 0;
}