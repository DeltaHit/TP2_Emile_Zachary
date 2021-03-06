/*==================================================================
	Auteur		: Émile Loiselle et Zachary Cockburn
	Date		: 29 octobre 2018
	Programme	: labyrinthe.h
	But			: Gère les opérations et les comparaisons entre la
				  carte du labyrinthe et le robot.
==================================================================*/

//================================
//	Instructions pré-processeur
//================================

#pragma once

//Default Librairies
#include <string>
#include <fstream>

//Custom Librairies
#include "map.h"
#include "deplacement.h"

using namespace std;

//================================
//			Déclarations
//================================

class labyrinthe
{
private:

	//Contient le flag si la solution a été trouvée
	bool _finRecherche;

	//Contient les murs d'une map
	customMap<char> _mapLab;

	//Point d'entrée et sortie
	deplacement _posDepart;
	deplacement _posArrivee;

public:

	//Constructeurs et destructeurs
	labyrinthe();
	labyrinthe(istream& input, ostream& output);
	~labyrinthe();

	//Getteurs
	deplacement getPosDepart() const;
	deplacement getPosArriver() const;
	customMap<char>& getMap();
	bool& getFinRecherche();

	//Vérifications
	bool canMove(const deplacement& pos, deplacement& posToCheck) const;
	bool arrived(const deplacement& pos) const;

	//Utilitaires
	void clear();
	void print(ostream&) const;
};

//================================
//			Définitions
//================================

//	Constructeurs / Destructeur
//================================

labyrinthe::labyrinthe()
{
	clear();
}

labyrinthe::labyrinthe(istream& input, ostream& output)
{
	string inputText;
	ifstream fichier;

	do
	{
		output << "Numéro du fichier du labyrinthe : ";
		getline(input, inputText);

		//Reformat du nombre pour trouver le fichier
		inputText.insert(0, "maps/labyrinthe");
		inputText.append(".txt");

		fichier.open(inputText);

		if (!fichier)
			output << "Le fichier '" << inputText << "' n'a pas été trouvé." << endl;

		else
			break;
	} while (true);

	//Enregistre les coordonnées du début et de la fin
	_mapLab.init(fichier);

	//Positions de X et Y inversées, étant donné que Y et X sont... BLABALBALBL
	fichier >> _posDepart.x() >> _posDepart.y()
		>> _posArrivee.x() >> _posArrivee.y();

	fichier.close();

	_finRecherche = false;
}

labyrinthe::~labyrinthe()
{
	clear();
}

//			Getteurs
//================================

deplacement labyrinthe::getPosDepart() const
{
	return _posDepart;
}

deplacement labyrinthe::getPosArriver() const
{
	return _posArrivee;
}

customMap<char>& labyrinthe::getMap()
{
	return _mapLab;
}

bool & labyrinthe::getFinRecherche()
{
	return _finRecherche;
}

//			Vérifications
//================================

//Vérifie si la case donnée est possible d'y bouger
bool labyrinthe::canMove(const deplacement& pos, deplacement& posToCheck) const
{
	//Check nord
	if (_mapLab.at(pos.x(), pos.y() + 1) == '0')
	{
		posToCheck.init(pos.x(), pos.y() + 1);
		return true;
	}

	//Check est
	if (_mapLab.at(pos.x() - 1, pos.y()) == '0')
	{
		posToCheck.init(pos.x() - 1, pos.y());
		return true;
	}

	//Check sud
	if (_mapLab.at(pos.x(), pos.y() - 1) == '0')
	{
		posToCheck.init(pos.x(), pos.y() - 1);
		return true;
	}

	//Check ouest
	if (_mapLab.at(pos.x() + 1, pos.y()) == '0')
	{
		posToCheck.init(pos.x() + 1, pos.y());
		return true;
	}

	//S'il ne peut pas bouger à l'emplacement
	return false;
}

//Vérifie si la position est celle d'arrivée
bool labyrinthe::arrived(const deplacement& pos) const
{
	if (pos.x() != getPosArriver().x() || pos.y() != getPosArriver().y())
		return false;

	return true;
}

//			Utilitaires
//================================

void labyrinthe::clear()
{
	_mapLab.clear();

	_posDepart.clear();
	_posArrivee.clear();

	_finRecherche = false;
}

void labyrinthe::print(ostream& output) const
{
	_mapLab.print(output);
}