/*
 * Algoritmos.h
 *
 *  Created on: Nov 24, 2008
 *      Author: Evandro Couto Mantese
 *      Author: Marcus Vinicius Ventura Bortolotti
 *      Author: Rafael de Paula Herrera
 */

#ifndef ALGORITMOS_H_
#define ALGORITMOS_H_

#include <vector>
#include "Grafo.h"

class
Algoritmos
{
	public:
		static std::vector<unsigned int>*
		busca_largura(Grafo& grafo, unsigned int vertice_origem, unsigned int vertice_destino);

		static std::vector<unsigned int>*
		busca_profundidade(Grafo& grafo, unsigned int vertice_origem, unsigned int vertice_destino);

		static std::vector<unsigned int>*
		dijkstra(Grafo& grafo, unsigned int vertice_origem, unsigned int vertice_destino);

		static std::vector<unsigned int>*
		fortemente_conexos(Grafo& grafo);
};

#endif /* ALGORITMOS_H_ */
