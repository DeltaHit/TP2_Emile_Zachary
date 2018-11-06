/*==================================================================
	Auteur		: �mile Loiselle et Zachary Cockburn
	Date		: 2 novembre 2018
	Programme	: robot.h
	But			: Entit� qui se d�place dans un labyrinthe en essayant
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
	deplacement _nextMove;		//Planifie le prochain d�placement

public:

	//Constructeurs et destructeurs
	robot();
	robot(deplacement d);
	~robot();

	//Getteur
	deplacement& nextMove();

	const deplacement& top();			//Retourne un �l�ment au dessus de la pile
	void push(const deplacement&);		//Ajoute un �l�ment au dessus de la pile
	void pop();							//Enl�ve un �l�ment au dessus de la pile
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

//Retourne un �l�ment au dessus de la pile
const deplacement & robot::top()
{
	return _pileDeplacement.top();
}

//Ajoute un �l�ment au dessus de la pile
void robot::push(const deplacement& dep)
{
	_pileDeplacement.push(dep);
}

//Enl�ve un �l�ment au dessus de la pile
void robot::pop()
{
	_pileDeplacement.pop();
}