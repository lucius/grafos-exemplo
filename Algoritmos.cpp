/*
 * Algoritmos.cpp
 *
 *  Created on: Nov 23, 2008
 *      Author: Evandro Couto Mantese
 *      Author: Marcus Vinicius Ventura Bortolotti
 *      Author: Rafael de Paula Herrera
 */

#include "Algoritmos.h"
#include <queue>
#include <vector>
#include <stack>

std::vector<unsigned int>*
Algoritmos::busca_largura(Grafo& grafo, unsigned int vertice_origem, unsigned int vertice_destino)
{
	grafo.reseta_cores();

	std::vector<unsigned int>*
	caminho = new std::vector<unsigned int>();

	std::queue<unsigned int>
	fila;

	fila.push(vertice_origem);

	while (! fila.empty())
	{
		unsigned int
		vertice_atual = fila.front();

		caminho->push_back(vertice_atual);

		fila.pop();

		if (vertice_atual == vertice_destino)
		{
			return caminho;
		}

		std::vector< std::pair<Grafo::Vertice*, unsigned int> >
		filhos = grafo.vertice(vertice_atual)->sucessores();

		for (std::vector< std::pair<Grafo::Vertice*, unsigned int> >::iterator it = filhos.begin();
			it != filhos.end(); ++it)
		{
			if (it->first->_cor == Grafo::Vertice::BRANCO)
			{
				it->first->_cor = Grafo::Vertice::CINZA;
				fila.push(it->first->id());
			}
		}
	}

	return caminho;
}

std::vector<unsigned int>*
Algoritmos::busca_profundidade(Grafo& grafo, unsigned int vertice_origem, unsigned int vertice_destino)
{
	grafo.reseta_cores();

	std::vector<unsigned int>*
	caminho = new std::vector<unsigned int>();

	std::stack<unsigned int>
	pilha;

	pilha.push(vertice_origem);

	while (! pilha.empty())
	{
		unsigned int
		vertice_atual = pilha.top();

		pilha.pop();

		caminho->push_back(vertice_atual);

		grafo.vertice(vertice_atual)->_cor = Grafo::Vertice::CINZA;

		if (vertice_atual == vertice_destino)
		{
			return caminho;
		}

		std::vector< std::pair<Grafo::Vertice*, unsigned int> >
		filhos = grafo.vertice(vertice_atual)->sucessores();

		for (std::vector< std::pair<Grafo::Vertice*, unsigned int> >::iterator it = filhos.begin();
			it != filhos.end(); ++it)
		{
			if (it->first->_cor == Grafo::Vertice::BRANCO)
			{
				pilha.push(it->first->id());
			}
		}

		grafo.vertice(vertice_atual)->_cor = Grafo::Vertice::PRETO;
	}

	return caminho;
}

std::vector<unsigned int>*
Algoritmos::dijkstra(Grafo& grafo, unsigned int vertice_origem, unsigned int vertice_destino)
{
	return NULL;
}
