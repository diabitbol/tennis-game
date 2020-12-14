#include <SFML/Graphics.hpp>
#include <iostream>
class Balle
{
    sf::CircleShape cercle;
    public:
    int Dx, Dy;
    int stockerX, stockerY;

public:
    Balle();
    // la balle change de direction lorsque la balle touche le fillet, une raquette ou le mur
    sf::CircleShape getCircle() { return cercle; }
    // cette fonction permet de bouger la balle dans une direction si la balle touche le mur horizontal ou une raquette
    // elle va rebondir dessus et si elle touche un mur vertical elle revient au milieu
    bool coordonneesCoincidesRaquette;
    // lorsque cette variable est vrai la balle a les mêmes coordonnées qu'une raquêtte elle change de mouvement
    bool coordonneesCoincidesMur;
    // lorsque cette variable est vrai la balle a les mêmes coordonnées qu'un mur horizontal elle change de mouvement
    sf::Vector2f getPosition() { return cercle.getPosition(); }
    void FinPartie(bool &);
    void move();
    void remettreDeplacement();
};
class Raquette
{
    sf::RectangleShape rectangle;

public:
    Raquette(int, int, sf::Color);
    sf::RectangleShape getRectangle() { return rectangle; }
    sf::Vector2f getPosition() { return rectangle.getPosition(); }
    int Dx = 10;
    int Dy = 10;
    void deplacerX(int);
    void deplacerY(int);
    void raquetteDepasse();
};
sf::RectangleShape creerUnFilet();
void finPartie(Balle);
void deplacerRaquette(Raquette &);