/*==================================================================
	Auteur		: �mile Loiselle et Zachary Cockburn
	Date		: 2 novembre 2018
	Programme	: robot.h
	But			: Entit� qui se d�lace dans un labyrinthe en essayant
				  tous les passages possibles.
==================================================================*/

//================================
//	Instructions pr�-processeur
//================================

#pragma once

//Default Librairies
#include <assert.h>

//Custom Librairies
#include "pile.h"

using namespace std;

//================================
//			D�clarations
//================================

class robot
{
private:
	pile<deplacement> historique;

public:
	robot();
	robot(deplacement d);
	~robot();

	pile<deplacement>& getHistorique();
};

//================================
//			D�finitions
//================================

//	Constructeurs / Destructeur
//================================

robot::robot()
{
}

robot::robot(deplacement d)
{
	historique.push(d);
}

robot::~robot()
{
}

pile<deplacement>& robot::getHistorique()
{
	return historique;
}