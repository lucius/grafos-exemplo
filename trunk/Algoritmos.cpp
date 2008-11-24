/*
 * Algoritmos.cpp
 *
 *  Created on: Nov 24, 2008
 *      Author: bode
 */

#include "Algoritmos.h"
#include <iostream>

void Algoritmos::dijkstra(Grafo& grafo, std::vector<unsigned int>& menor_caminho) {
	unsigned int numero_vertices = grafo.vertices();
	int vertices[numero_vertices];
	int distancia[numero_vertices];

	for (unsigned int i = 0; i < numero_vertices; ++i) vertices[i] = i;

	vertices[0] = -1;
	distancia[0] = 0;

	for (unsigned int i = 1; i < numero_vertices; ++i) distancia[i] = grafo.peso(0, i);


	for (unsigned int vertice_corrente = 1; vertice_corrente < numero_vertices; ++vertice_corrente) {
		dijkstra(grafo, vertices, distancia);
		std::cout << "Vertice " << vertice_corrente << std::endl;

		// Just to show what the current distances are for each path as we
		// loop through the vertexs and evaluate.
		for (unsigned int i = 0; i < numero_vertices; i++) {
			std::cout << distancia[i] << " ";
		}
		std::cout << std::endl;

		// Show which vertexs have yet to be visted (-1 means visited)
		for (unsigned int i = 0; i < numero_vertices; i++) {
			std::cout << vertices[i] << " ";
		}
		std::cout << std::endl;
	}


	//    // Ok, lets start at level 1 and move to level 7
	//    // Each time we call our function to evaluate the following...
	//
	//    // 1. What paths are available to us (we use the vertexes closes to our point)
	//    // 2. How far are they away?
	//    // 3. Take whichever is shortest path with the least cost.
	//
	//    for (int curlevel = 1; curlevel < LEVELS; curlevel++) {
	//        Dijkstra(Vertexes, Dist, L);
	//        cout << "Level " << curlevel << endl;
	//
	//        // Just to show what the current distances are for each path as we
	//        // loop through the vertexs and evaluate.
	//        for (int i = 0; i < LEVELS; i++) {
	//            cout << Dist[i] << " ";
	//        }
	//        cout << endl;
	//
	//        // Show which vertexs have yet to be visted (-1 means visited)
	//        for (int i = 0; i < LEVELS; i++) {
	//            cout << Vertexes[i] << " ";
	//        }
	//        cout << endl;
	//    }
}

void Algoritmos::dijkstra(Grafo& grafo, int* vertices, int* distancia) {
	unsigned int numero_vertices = grafo.vertices();
	int valor_minimo = 32767;
	int vertice_minimo = 0;

	// Loop entre os vertices para checar se foram visitados.
	// Se nao foram, checa a distancia e verifica se eh menor que a menor distancia
	// atual. Se for, a define como valor minimo e define como vertice minimo.
	for (unsigned int i = 0; i < numero_vertices; ++i) {
		if (vertices[i] == -1) continue;
		if (distancia[i] > 0 && distancia[i] < valor_minimo) {
			valor_minimo = distancia[i];
			vertice_minimo = i;
		}
	}

	// Marca como visitado, o vertice cuja distancia eh minima
	vertices[vertice_minimo] = -1;

	// Adiciona a distancia ao caminho de distancias do inicio ao destino.
	// O resultado eh uma lista que mostra o menor caminho entre ambos.
	for (unsigned int i = 0; i < numero_vertices; ++i) {
		if (grafo.peso(vertice_minimo, i) < 0) continue;
		if (distancia[i] < 0) {
			distancia[i] = valor_minimo + grafo.peso(vertice_minimo, i);
			continue;
		}
		if ((distancia[vertice_minimo] + grafo.peso(vertice_minimo, i)) < distancia[i]) {
			distancia[i] = valor_minimo + grafo.peso(valor_minimo, i);
		}
	}
}

//    int L[LEVELS][LEVELS] = {
//                {-1,  5, -1, -1, -1,  3, -1, -1},
//                { 5, -1,  2, -1, -1, -1,  3, -1},
//                {-1,  2, -1,  6, -1, -1, -1, 10},
//                {-1, -1,  6, -1,  3, -1, -1, -1},
//                {-1, -1, -1,  3, -1,  8, -1,  5},
//                { 3, -1, -1, -1,  8, -1,  7, -1},
//                {-1,  3, -1, -1, -1,  7, -1,  2},
//                {-1, -1, 10, -1,  5, -1,  2, -1}
//            };


//// Dijkstra implements the algorithm for checking the vertexs and their
//// relative path distances in relation to where we are in the graph.
//void Dijkstra(int *Vertexes, int *Dist, int L[LEVELS][LEVELS]) {
//    int minValue = 32767;
//    int minNode = 0;
//
//    // Loop through the vertexs to see if they have been visited
//    // If they haven't, check their distance and see if it is smaller than
//    // our current shortest distance. If so, set the new shortest distance
//    // to minValue and label the node as the shortest
//    for (int i = 0; i < LEVELS; i++) {
//        if (Vertexes[i] == -1) { continue; }
//        if (Dist[i] > 0 && Dist[i] < minValue) {
//            minValue = Dist[i];
//            minNode = i;
//        }
//    }
//
//    // Mark the new shortest distance vertex as visited
//    Vertexes[minNode] = -1;
//
//    // Add the distance to the overall path distance from start
//    // to destination. The result is a list of values at the end which will
//    // show the shortest paths between any two nodes.
//    for (int i = 0; i < LEVELS; i++) {
//        if (L[minNode][i] < 0) { continue; }
//        if (Dist[i] < 0) {
//            Dist[i] = minValue + L[minNode][i];
//            continue;
//        }
//        if ((Dist[minNode] + L[minNode][i]) < Dist[i]) {
//            Dist[i] = minValue + L[minNode][i];
//        }
//    }
//}
