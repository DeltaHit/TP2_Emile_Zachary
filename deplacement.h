/*==================================================================
	Auteur		: �mile Loiselle et Zachary Cockburn
	Date		: 2 novembre 2018
	Programme	: robot.h
	But			: G�re les informations sur les d�placements.
==================================================================*/

//================================
//	Instructions pr�-processeur
//================================

#pragma once

//Default Librairies
#include <assert.h>

using namespace std;

//================================
//			D�clarations
//================================

class deplacement
{
private:

	int _x;		//Position X
	int _y;		//Position Y

public:

	deplacement();				//Initialise sans param�tres
	deplacement(int, int);		//Initialise avec 2 param�tres
	~deplacement();				//Destruction

	int& x();		//Obtient la valeur de x par r�f�rence
	int& y();		//Obtient la valeur de y par r�f�rence

	const int& x() const;		//Obtient la valeur de x par r�f�rence constante
	const int& y() const;		//Obtient la valeur de y par r�f�rence constante

	void init(int, int);		//Initialise le d�placement
	void clear();				//Remet tout � NULL

	//Op�rateurs
	const deplacement& operator=(const deplacement& d);
	bool operator==(const deplacement& s)const;
	bool operator!=(const deplacement& s)const;
};

//================================
//			D�finitions
//================================

//	Constructeurs / Destructeur
//================================

deplacement::deplacement()
{
	clear();
}

deplacement::deplacement(int x, int y)
{
	init(x, y);
}

deplacement::~deplacement()
{
	clear();
}

//			Getteurs
//================================

int& deplacement::x()
{
	return _x;
}

int& deplacement::y()
{
	return _y;
}

//		Getteurs const
//================================

const int & deplacement::x()const
{
	return _x;
}

const int & deplacement::y() const
{
	return _y;
}

//Initialise toutes les variables avec les param�tres
void deplacement::init(int x, int y)
{
	_x = x;
	_y = y;
}

//Remet tout � NULL
void deplacement::clear()
{
	//nullptr non-accept�?
	_x = NULL;
	_y = NULL;
}

//			Op�rateurs
//================================

const deplacement & deplacement::operator=(const deplacement & d)
{
	_x = d._x;
	_y = d._y;

	return *this;
}

bool deplacement::operator==(const deplacement & p) const
{
	return _x == p._x && _y == p._y;
}

bool deplacement::operator!=(const deplacement & p) const
{
	return !(_x == p._x && _y == p._y);
}