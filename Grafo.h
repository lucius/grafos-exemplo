/*
 * Grafo.h
 *
 *  Created on: Nov 23, 2008
 *      Author: bode
 */

#ifndef GRAFO_H_
#define GRAFO_H_

class Grafo {
	public:
		Grafo(unsigned int numero_vertices);
		virtual ~Grafo();

		void liga_vertices(unsigned int vertice1, unsigned int vertice2, int peso);
		bool estao_ligados(unsigned int vertice1, unsigned int vertice2);
		int peso(unsigned int vertice1, unsigned int vertice2);
		unsigned int vertices();
	protected:
		unsigned int numero_vertices;
		int** matriz_adjacencia;
};

#endif /* GRAFO_H_ */
