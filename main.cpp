/*==================================================================
	Auteur		: �mile Loiselle et Zachary Cockburn
	Date		: 29 octobre 2018
	Programme	: main.cpp
	But			: G�re les op�rations et les comparaisons entre la
				  carte du labyrinthe et le robot.
==================================================================*/

//SFML Librairies
#include <SFML/Graphics.hpp>
#include <iostream>

//Default Librairies
#include <stack>

//Custom Librairies
#include <labyrinthe.h>
#include <map.h>

using namespace std;

int main()
{
	//Le labyrinthe actuel
	labyrinthe labActif;

	//Cr�e une fen�tre
	sf::RenderWindow window(sf::VideoMode(640, 480), "Labyrinthe");

	//Tant que la fen�tre est ouverte
	while (window.isOpen())
	{
		//D�clare un �v�nement
		sf::Event event;

		//Si un �v�nement est d�clanch�
		while (window.pollEvent(event))
		{
			//Pour l'�v�nement
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//S�quence qui rafra�chi l'affichage
		window.clear();
		//window.draw(shape);
		window.display();
	}

	return 0;
}