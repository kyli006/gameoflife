#ifndef ANIME_H
#define ANIME_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <time.h>
#include "const.h"
#include <grid.h>
class Anime
{
public:
    Anime();
    void FillShapes();
    void ShowShapes();
    void update();
    void run();
    void processEvent();
    void render();
    void Text();
    void drawText();
    void clickcolor(int set);
    int findPos(int x, int y);

private:
    sf::RenderWindow window;
    sf::RectangleShape shapeArray[GRID_HEIGHT][GRID_WIDTH];

    //setting text and font
    sf::Font font;
    sf::Text clear;
    sf::Text random;
    sf::Text step;
    sf::Text go;
    sf::Text stop;
    sf::Text save;
    sf::Text load;
    sf::Text savepattern;
    sf::Text loadpattern;
    sf::RectangleShape box1;
    sf::RectangleShape box2;
    sf::RectangleShape box3;
    sf::RectangleShape box4;
    sf::RectangleShape box5;
    sf::RectangleShape box6;
    sf::RectangleShape box7;
    sf::RectangleShape box8;
    sf::RectangleShape box9;
    grid a;
    grid b;
    bool On;
    bool Save;
    bool Load;
    int set;
    int x1;
    int x2;
    int y1;
    int y2;
    int x_set;
    int y_set;
};

#endif // ANIME_H
