/*==================================================================
	Auteur		: �mile Loiselle et Zachary Cockburn
	Date		: 29 octobre 2018
	Programme	: main.cpp
	But			: G�re les op�rations et les comparaisons entre la
				  carte du labyrinthe et le robot.
==================================================================*/

//================================
//	Instructions pr�-processeur
//================================

//SFML Librairies
#include <SFML/Graphics.hpp>

//Default Librairies
#include <iostream>
#include <fstream>

//Custom Librairies
#include "labyrinthe.h"
#include "robot.h"

using namespace std;

int main()
{
	//================================
	//			Initialisations
	//================================

	//PLanifie le prochain d�placement
	deplacement nextMove;

	//Le labyrinthe actuel
	labyrinthe labActif("Maps/Labyrinthe4.txt");

	//Les d�placements du robot
	robot robActif(labActif.getPosDepart());

	//Charge les textures
	sf::Texture textureMap;
	textureMap.loadFromFile("images/map_spriteSheet.png");

	//Cr�er les sprites
	sf::IntRect rectSourceMap(0, 0, 32, 32);
	sf::Sprite spriteMap(textureMap, rectSourceMap);

	//Cr�e une fen�tre
	sf::RenderWindow window(sf::VideoMode(
		labActif.getMap().getNbCol() * 32,
		labActif.getMap().getNbLine() * 32),
		"Labyrinthe");

	//================================
	//		Input utilisateur
	//================================

	//Tant que la fen�tre est ouverte
	while (window.isOpen())
	{
		//D�clare un �v�nement
		sf::Event event;

		//Si un �v�nement est d�clanch�
		while (window.pollEvent(event))
		{
			//Pour l'�v�nement fermeture de fen�tre ( le X )
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();

			//Si on tente de resize l'�cran
			if (event.type == sf::Event::Resized)
			{
				//Rafra�chi la vue au nouvel �cran
				sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
				window.setView(sf::View(visibleArea));
			}
		}

		//================================
		//			Affichage
		//================================

		//Efface tout
		window.clear();

		//Pour chaques cases
		for (int i = 0; i < labActif.getMap().getNbLine(); i++)
		{
			for (int j = 0; j < labActif.getMap().getNbCol(); j++)
			{
				//Emplacement de la fen�tre qui va �tre modifi�
				spriteMap.setPosition(j * 32, i * 32);

				//Si c'est un mur dans la carte
				if (labActif.getMap()[i][j] == '1')
				{
					//Place la texture sur l'emplacement du mur
					rectSourceMap.left = 32;
					rectSourceMap.top = 0;
				}

				//Si c'est vide
				else if (labActif.getMap()[i][j] == '0')
				{
					//Place la texture sur l'emplacement du plancher
					rectSourceMap.left = 0;
					rectSourceMap.top = 0;
				}

				//Met � jour le sprite avec la nouvelle texture
				spriteMap.setTextureRect(rectSourceMap);

				//Affiche le sprite avec la nouvelle texture
				window.draw(spriteMap);
			}
		}

		//Afficher icone de depart du labyrinthe
		spriteMap.setPosition(labActif.getPosDepart().y() * 32, labActif.getPosDepart().x() * 32);
		rectSourceMap.left = 96;
		rectSourceMap.top = 0;
		spriteMap.setTextureRect(rectSourceMap);
		window.draw(spriteMap);

		//Afficher icone d'arriv�e du labyrinthe
		spriteMap.setPosition(labActif.getPosArriver().y() * 32, labActif.getPosArriver().x() * 32);
		rectSourceMap.left = 0;
		rectSourceMap.top = 32;
		spriteMap.setTextureRect(rectSourceMap);
		window.draw(spriteMap);

		//if (!labActif.arrived(robActif.getPileDeplacement().top()))
		//{
		//	if (labActif.canMove(robActif.getPileDeplacement().top()))
		//	{
		//		if (robActif.getPileDeplacement().top().orientation() == 'N')
		//		{
		//			nextMove = robActif.getPileDeplacement().top();
		//			nextMove.y()++;

		//			robActif.getPileDeplacement().push(nextMove);
		//		}

		//		if (robActif.getPileDeplacement().top().orientation() == 'E')
		//		{
		//			nextMove = robActif.getPileDeplacement().top();
		//			nextMove.x()++;

		//			robActif.getPileDeplacement().push(nextMove);
		//		}

		//		if (robActif.getPileDeplacement().top().orientation() == 'S')
		//		{
		//			nextMove = robActif.getPileDeplacement().top();
		//			nextMove.y()--;

		//			robActif.getPileDeplacement().push(nextMove);
		//		}

		//		if (robActif.getPileDeplacement().top().orientation() == 'O')
		//		{
		//			nextMove = robActif.getPileDeplacement().top();
		//			nextMove.x()--;

		//			robActif.getPileDeplacement().push(nextMove);
		//		}
		//	}

		//	labActif.getMap().at(robActif.getPileDeplacement().top().x(),
		//		robActif.getPileDeplacement().top().y()) = 'V';

		//	robActif.getPileDeplacement().pop();
		//}
		//else
		//{
		//	cout << "SUCCESS";
		//}

		//Rafra�chit l'�cran avec les nouvelles modifications
		window.display();
	}

	return EXIT_SUCCESS;
}

//bool resoudre(robot robot, labyrinthe lab)
//{
//	if (robot.getPileDeplacement().top() == lab.getPosArriver())
//	{
//		return true;
//	}
//
//	if (lab.getMap().at(robot.getPileDeplacement().top().x(), robot.getPileDeplacement().top().x()) == '0' && resoudre(robot()))
//	{
//	}
//}