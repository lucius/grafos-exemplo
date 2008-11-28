/*
 * TesteGrafo.h
 *
 *  Created on: Nov 24, 2008
 *      Author: Evandro Couto Mantese
 *      Author: Marcus Vinicius Ventura Bortolotti
 *      Author: Rafael de Paula Herrera
 */

#ifndef TESTEGRAFO_H_
#define TESTEGRAFO_H_

#include <string>
#include "Grafo.h"

class TesteGrafo
{
	public:
		static void
		todos_testes();

		static void
		testa_ligacoes(Grafo& grafo);

		static void
		testa_adjacentes(Grafo& grafo, unsigned int vertice);

		static void
		testa_busca_largura(Grafo& grafo, unsigned int vertice_origem, unsigned int vertice_destino);

		static void
		testa_busca_profundidade(Grafo& grafo, unsigned int vertice_origem, unsigned int vertice_destino);

		static void
		testa_dijkstra(Grafo& grafo);
};

#endif /* TESTEGRAFO_H_ */
