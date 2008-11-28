/*
 * Grafo.cpp
 *
 *  Created on: Nov 23, 2008
 *      Author: Evandro Couto Mantese
 *      Author: Marcus Vinicius Ventura Bortolotti
 *      Author: Rafael de Paula Herrera
 */

#include <utility>
#include "Grafo.h"

Grafo::Grafo()
{

}

Grafo::~Grafo()
{

}

void
Grafo::adiciona_vertice(Vertice* vertice)
{
	this->_vertices[vertice->id()] = vertice;
}

Grafo::Vertice*
Grafo::vertice(unsigned int id)
{
	if (!this->_vertices.empty())
	{
		if (this->_vertices.find(id) != this->_vertices.end())
		{
			return this->_vertices[id];
		}
	}

	return NULL;
}

void
Grafo::reseta_cores()
{
	for (std::map<unsigned int, Grafo::Vertice*>::iterator it = this->_vertices.begin();
			it != this->_vertices.end(); ++it)
	{
		it->second->_cor = Grafo::Vertice::BRANCO;
	}
}

Grafo::Vertice::Vertice(unsigned int identificador)
{
	this->_id = identificador;
}

Grafo::Vertice::~Vertice()
{

}

unsigned int
Grafo::Vertice::id()
{
	return this->_id;
}

void
Grafo::Vertice::liga_com(Grafo::Vertice* vertice, unsigned int peso)
{
	vertice->adiciona_antecessor(this, peso);
	this->adiciona_sucessor(vertice, peso);
}

bool
Grafo::Vertice::esta_ligado_com(Grafo::Vertice* vertice)
{
	if (!vertice) return false;

	for (std::vector< std::pair<Vertice*, unsigned int> >::iterator it = this->_sucessores.begin();
			it != this->_sucessores.end(); ++it)
	{

		if (it->first == vertice) return true;
	}

	for (std::vector< std::pair<Vertice*, unsigned int> >::iterator it = this->_antecessores.begin();
				it != this->_antecessores.end(); ++it)
	{
		if (it->first == vertice) return true;
	}

	return false;
}

void
Grafo::Vertice::adiciona_antecessor(Grafo::Vertice* antecessor, unsigned int peso)
{
	std::pair<Grafo::Vertice*, unsigned int>
	par;

	par.first = antecessor;
	par.second = peso;

	this->_antecessores.push_back(par);
}

std::vector< std::pair<Grafo::Vertice*, unsigned int> >
Grafo::Vertice::antecessores()
{
	return this->_antecessores;
}

void
Grafo::Vertice::adiciona_sucessor(Grafo::Vertice* sucessor, unsigned int peso)
{
	std::pair<Grafo::Vertice*, unsigned int>
	par;

	par.first = sucessor;
	par.second = peso;

	this->_sucessores.push_back(par);
}

std::vector< std::pair<Grafo::Vertice*, unsigned int> >
Grafo::Vertice::sucessores()
{
	return this->_sucessores;
}
