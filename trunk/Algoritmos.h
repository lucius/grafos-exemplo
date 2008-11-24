/*
 * Algoritmos.h
 *
 *  Created on: Nov 24, 2008
 *      Author: bode
 */

#ifndef ALGORITMOS_H_
#define ALGORITMOS_H_

#include <vector>
#include "Grafo.h"

class Algoritmos {
	public:
		static void dijkstra(Grafo& grafo, std::vector<unsigned int>& menor_caminho);
	protected:
		static void dijkstra(Grafo& grafo, int* vertices, int* distancia);
};

#endif /* ALGORITMOS_H_ */
