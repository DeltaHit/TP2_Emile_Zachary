/*==================================================================
	Auteur		: �mile Loiselle et Zachary Cockburn
	Date		: 5 novembre 2018
	Programme	: pile.h
	But			: Objet qui permet d'ajouter, enlever
				  et modifier l'element du dessus d'une pile.
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

template <class TYPE>
class pile
{
protected:

	struct cellule
	{
		TYPE element;			//�l�ment dans la cellule
		cellule	*next; 			//Pointeur vers la prochaine cellule

		cellule(const TYPE& e, cellule * n)		//Constructeur avec 2 param�tres
		{
			element = e;
			next = n;
		}
	};

	cellule	*_top;			//1er �l�ment de la pile
	int	_size;				//Nombre d'�l�ment de la pile

	pile(const pile<TYPE>& p) {};		//Copieur prot�g�

public:

	//Constructeurs et destructeur
	pile();
	~pile();

	void push(const TYPE& e);	//Ajoute un dessus
	void pop();					//Enl�ve un dessus

	const TYPE& top() const;	//Obtient la valeure au dessus de la pile
	TYPE& top();				//Obtient la valeure au dessus de la pile (const)
	int size() const;			//Obtient la grandeur de la pile

	bool isEmpty() const;		//V�rifie si la pile est vide
	void clear();				//Vide la pile

	//Op�rateurs
	const pile<TYPE>& operator=(const pile& s);
	bool operator==(const pile& s)const;
};

//================================
//			D�finitions
//================================

template<class TYPE>
pile<TYPE>::pile()
{
	_top = nullptr;
	_size = 0;
}

template<class TYPE>
pile<TYPE>::~pile()
{
	clear();
}

template<class TYPE>
void pile<TYPE>::push(const TYPE & e)
{
	_size++;
	_top = new cellule(e, _top);
}

//Enl�ve le premier �l�ment dans la pile
template<class TYPE>
void pile<TYPE>::pop()
{
	assert(!isEmpty());
	_size--;

	cellule *temp = _top;
	_top = _top->next;

	delete temp;
}

template<class TYPE>
const TYPE & pile<TYPE>::top() const
{
	assert(!isEmpty());
	return _top->element;
}

template<class TYPE>
TYPE & pile<TYPE>::top()
{
	assert(!isEmpty());
	return _top->element;
}

template<class TYPE>
int pile<TYPE>::size() const
{
	int compteur = 0;

	cellule* tempE = _top;

	//Tant qu'on ne revient pas au d�but
	while (tempE != nullptr)
	{
		tempE = tempE->next;
		compteur++;
	}
	return compteur;
}

template<class TYPE>
bool pile<TYPE>::isEmpty() const
{
	return _top == nullptr;
}

template<class TYPE>
void pile<TYPE>::clear()
{
	while (!isEmpty())
		pop();
}

//			Op�rateurs
//================================

//Copie le contenu d'une pile vers une autre
template<class TYPE>
const pile<TYPE>& pile<TYPE>::operator=(const pile& p)
{
	//Si les 2 piles sont d�j� identiques
	if (this == &p)
		return *this;

	clear();
	if (!p.isEmpty())
	{
		cellule* tempI = nullptr;
		cellule* tempE = p._top;

		//Copie un �l�ment de la pile source en tant que premi�re case dans la pile cible
		tempI = _top = new cellule(tempE->element, nullptr);
		tempE = tempE->next;

		//Tant qu'on ne revient pas au d�but
		while (tempE != nullptr)
		{
			//Copie un �l�ment de la pile source en tant que nouvelle case dans la pile cible
			tempI = tempI->next = new cellule(tempE->element, nullptr);
			tempE = tempE->next;
		}

		//Copie la grandeur
		_size = p.size();
	}
	return *this;
}

//Compare deux piles
template<class TYPE>
bool pile<TYPE>::operator==(const pile & p) const
{
	//2 piles de grandeur �gale
	if (_size == p.size())
	{
		//Marqueurs sur les 2 piles � comparer
		cellule* tempExp = p._top;
		cellule* tempImp = _top;

		//Tant qu'on a pas fait le tour de la pile
		while (tempExp != nullptr)
		{
			//Si l'�l�ment n'est pas �gale � l'autre
			if (tempExp->element != tempImp->element)
			{
				//Un �l�ment n'est pas �gal � l'autre
				return false;
			}

			//Passe aux prochaines cases
			tempExp = tempExp->next;
			tempImp = tempImp->next;
		}

		//Tous les �l�ments sont identiques
		return true;
	}

	//Les 2 piles ne sont pas de grandeur �gales
	return false;
}