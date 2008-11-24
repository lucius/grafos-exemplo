/*
 * Grafo.cpp
 *
 *  Created on: Nov 23, 2008
 *      Author: bode
 */

#include "Grafo.h"

Grafo::Grafo(unsigned int numero_vertices) {
	this->numero_vertices = numero_vertices;
	this->matriz_adjacencia = new int*[this->numero_vertices];
	for (unsigned int i = 0; i < this->numero_vertices; ++i) {
		this->matriz_adjacencia[i] = new int[this->numero_vertices];

		for (unsigned int j = 0; j < this->numero_vertices; ++j) {
			this->matriz_adjacencia[i][j] = -1;
		}
	}
}

Grafo::~Grafo() {
	for (unsigned int i = 0; i < this->numero_vertices; ++i) {
		delete this->matriz_adjacencia[i];
	}
	delete[] this->matriz_adjacencia;
}

void Grafo::liga_vertices(unsigned int vertice1, unsigned int vertice2, int peso) {
	if (vertice1 > this->numero_vertices - 1 || vertice2 > this->numero_vertices - 1) {
		// lancar excessao pois nao existem na matriz
		return;
	}
	if (peso <= 0) {
		// lancar excessao pois o peso nao pode ser negativo
		return;
	}

	this->matriz_adjacencia[vertice1][vertice2] = peso;
	this->matriz_adjacencia[vertice2][vertice1] = peso;
}

bool Grafo::estao_ligados(unsigned int vertice1, unsigned int vertice2) {
	if (vertice1 > this->numero_vertices - 1 || vertice2 > this->numero_vertices - 1) {
		// lancar excessao pois nao existem na matriz
		return false;
	}

	return (this->matriz_adjacencia[vertice1][vertice2] > 0);
}

int Grafo::peso(unsigned int vertice1, unsigned int vertice2) {
	if (vertice1 > this->numero_vertices - 1 || vertice2 > this->numero_vertices - 1) {
		// lancar excessao pois nao existem na matriz
		return false;
	}

	return this->matriz_adjacencia[vertice1][vertice2];
}

unsigned int Grafo::vertices() {
	return this->numero_vertices;
}
