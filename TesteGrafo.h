/*
 * TesteGrafo.h
 *
 *  Created on: Nov 24, 2008
 *      Author: bode
 */

#ifndef TESTEGRAFO_H_
#define TESTEGRAFO_H_

#include <string>
#include "Grafo.h"

class TesteGrafo {
	public:
		static void todos_testes();
		static void testa_ligacoes(Grafo& grafo);
		static void testa_dijkstra(Grafo& grafo);
};

#endif /* TESTEGRAFO_H_ */
