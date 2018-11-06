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

	pile<deplacement> _pileDeplacement;
	deplacement _nextMove;			//Planifie le prochain d�placement

public:

	robot();					//Initialise sans param�tres
	robot(deplacement d);		//Initialise avec 3 param�tres
	~robot();					//Destruction

	deplacement& nextMove();		//Getteur

	const deplacement& top();
	void push(const deplacement&);
	void pop();
};

//================================
//			D�finitions
//================================

//	Constructeurs / Destructeur
//================================

robot::robot()
{
	_pileDeplacement.clear();
}

robot::robot(deplacement d)
{
	_pileDeplacement.push(d);
}

robot::~robot()
{
	_pileDeplacement.clear();
}

//Obtient le deplacement _nextMove
deplacement& robot::nextMove()
{
	return _nextMove;
}

//		Operations pile
//================================

const deplacement & robot::top()
{
	return _pileDeplacement.top();
}

void robot::push(const deplacement& dep)
{
	_pileDeplacement.push(dep);
}

void robot::pop()
{
	_pileDeplacement.pop();
}
