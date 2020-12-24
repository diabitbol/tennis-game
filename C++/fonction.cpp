#include <SFML/Graphics.hpp>
#include "fonction.h"
using namespace std;
using namespace sf;
Balle::Balle()
{
    cercle = CircleShape(10);
    cercle.setPosition(990, 730);
    cercle.setFillColor(Color::White);
    Dx = 10;
    Dy = 10;
    stockerX=Dx;
    stockerY=Dy;
}
Raquette::Raquette(int x, int y, Color c)
{
    rectangle = RectangleShape(Vector2f(20, 200));
    rectangle.setFillColor(c);
    rectangle.setPosition(x, y);
}
sf::RectangleShape creerUnFilet()
{
    RectangleShape rectangle(Vector2f(20, 1500));
    rectangle.setFillColor(Color(255, 255, 255, 100));
    rectangle.setPosition(990, 0);
    return rectangle;
}
void Balle::FinPartie(bool & pause)
{
    cercle.setPosition(990, 730);
    Dx=0; Dy=0;
    if (!pause)
    {
        Dx=stockerY; Dy=stockerY;
    }
}
void Raquette::deplacerX(int n)
{
    rectangle.move(n * Dx, 0);
}
void Raquette::deplacerY(int n)
{
    rectangle.move(0, n * Dy);
}
void deplacerRaquette(Raquette & raquette)
{
    //cette fonction deplace la raquette en fonction des flèches
    if (Keyboard::isKeyPressed(Keyboard::Up))
    {
        raquette.deplacerY(-1);
    }
    if (Keyboard::isKeyPressed(Keyboard::Down))
    {
        raquette.deplacerY(1);
    }
}

void Balle::move()
{
    if (coordonneesCoincidesRaquette)
    {
        Dx = -Dx;
        coordonneesCoincidesRaquette = false;
    }
    else if (coordonneesCoincidesMur)
    {
        Dy = -Dy;
        coordonneesCoincidesMur = false;
    }
    cercle.move(Dx, Dy);
}
void Balle::remettreDeplacement()
{
    Dx=stockerX;
    Dy=stockerY;
}
void Raquette::raquetteDepasse()
{
    if (rectangle.getPosition().y <= 5)
    {
        rectangle.setPosition(rectangle.getPosition().x, rectangle.getPosition().y-20);
    }
    if (rectangle.getPosition().y+20 >= 1495)
    {
        rectangle.setPosition(rectangle.getPosition().x, rectangle.getPosition().y+20);
    }
}