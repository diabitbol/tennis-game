#include <SFML/Graphics.hpp>
#include <iostream>
#include "fonction.h"
using namespace sf;
using namespace std;
int main()
{
    sf::RenderWindow window(sf::VideoMode(2000, 1500), "tennis 2D");
    window.setFramerateLimit(60);
    Balle balle; //création de la balle
    Raquette raquette1(40, 650, Color::Blue), raquette2(1940, 650, Color::Red);
    bool pause = false; // quand cette variable est vrai le jeu est en pause
    //création de deux raquettes
    RectangleShape filet = creerUnFilet();
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == event.KeyPressed && event.key.code == Keyboard::Escape)
                window.close();
        }
            // la balle a un mouvement originel vers la droite puis si elle touche un objet elle part dans la
            //direction opposée
            balle.move();
            //si la balle touche la raquête de gauche
            if (balle.getPosition().x <= raquette1.getPosition().x + 20 && balle.getPosition().y + 10 >= raquette1.getPosition().y && balle.getPosition().y - 10 <= raquette1.getPosition().y + 180)
            {
                balle.coordonneesCoincidesRaquette = true;
            }
            //si la balle touche la raquette de droite
            if (balle.getPosition().x + 20 >= raquette2.getPosition().x && balle.getPosition().y >= raquette2.getPosition().y && balle.getPosition().y + 10 <= raquette2.getPosition().y + 180)
            {
                balle.coordonneesCoincidesRaquette = true;
            }
            //si la balle touche le mur haut ou bas
            if (balle.getPosition().y <= 0 || balle.getPosition().y >= 1480)
            {
                balle.coordonneesCoincidesMur = true;
            }
            if ((balle.getPosition().x <= 10 || balle.getPosition().x + 20 >= 1970))
            {
                pause = true;
                balle.FinPartie(pause);
            }
            raquette1.raquetteDepasse();
            raquette2.raquetteDepasse();
            // si la balle sort par le mur de gauche ou de droite la balle retourne au center du terrain jusqu'à
            // l'appui sur espace
        //déplacements de raquette
        deplacerRaquette(raquette1);
        window.clear();
        window.draw(balle.getCircle());
        window.draw(raquette1.getRectangle());
        window.draw(raquette2.getRectangle());
        window.draw(filet);
        window.display();
    }

    return 0;
}
