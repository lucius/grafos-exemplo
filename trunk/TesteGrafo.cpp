/*
 * TesteGrafo.cpp
 *
 *  Created on: Nov 24, 2008
 *      Author: bode
 */

#include <assert.h>
#include <iostream>
#include <vector>
#include "Algoritmos.h"
#include "Grafo.h"
#include "TesteGrafo.h"

void TesteGrafo::todos_testes() {
	std::cout << ">>> TesteGrafo::todos_testes" << std::endl;


	std::cout << "Criando grafo com 10 vertices..." << std::endl;
	Grafo grafo(10);


	testa_ligacoes(grafo);
	testa_dijkstra(grafo);


	std::cout << "<<< TesteGrafo::todos_testes" << std::endl;
}

void TesteGrafo::testa_ligacoes(Grafo& grafo) {
	std::cout << ">>> TesteGrafo::testa_ligacoes" << std::endl;


	std::cout << "Ligando vertice 0 ao vertice 1 com peso 5..." << std::endl;
	grafo.liga_vertices(0, 1, 5);

	std::cout << "Ligando vertice 0 ao vertice 2 com peso 2..." << std::endl;
	grafo.liga_vertices(0, 2, 2);

	std::cout << "Ligando vertice 0 ao vertice 3 com peso 3..." << std::endl;
	grafo.liga_vertices(0, 3, 3);

	std::cout << "Ligando vertice 1 ao vertice 4 com peso 2..." << std::endl;
	grafo.liga_vertices(1, 4, 2);

	std::cout << "Ligando vertice 2 ao vertice 5 com peso 5..." << std::endl;
	grafo.liga_vertices(2, 5, 5);

	std::cout << "Ligando vertice 3 ao vertice 4 com peso 1..." << std::endl;
	grafo.liga_vertices(3, 4, 1);

	std::cout << "Ligando vertice 3 ao vertice 6 com peso 4..." << std::endl;
	grafo.liga_vertices(3, 6, 4);

	std::cout << "Ligando vertice 4 ao vertice 8 com peso 7..." << std::endl;
	grafo.liga_vertices(4, 8, 7);

	std::cout << "Ligando vertice 6 ao vertice 7 com peso 4..." << std::endl;
	grafo.liga_vertices(6, 7, 4);

	std::cout << "Ligando vertice 7 ao vertice 8 com peso 3..." << std::endl;
	grafo.liga_vertices(7, 8, 3);

	std::cout << "Ligando vertice 7 ao vertice 9 com peso 5..." << std::endl;
	grafo.liga_vertices(7, 9, 5);


	std::cout << "Testando ligacao entre os vertices 0 e 1..." << std::endl;
	assert(grafo.estao_ligados(0, 1));

	std::cout << "Testando ligacao entre os vertices 1 e 0..." << std::endl;
	assert(grafo.estao_ligados(1, 0));

	std::cout << "Testando ligacao entre os vertices 3 e 6..." << std::endl;
	assert(grafo.estao_ligados(3, 6));

	std::cout << "Testando ligacao entre os vertices 6 e 3..." << std::endl;
	assert(grafo.estao_ligados(6, 3));

	std::cout << "Testando ligacao entre os vertices 3 e 4..." << std::endl;
	assert(grafo.estao_ligados(3, 4));

	std::cout << "Testando ligacao entre os vertices 4 e 3..." << std::endl;
	assert(grafo.estao_ligados(4, 3));

	std::cout << "Testando ligacao entre os vertices 8 e 7..." << std::endl;
	assert(grafo.estao_ligados(8, 7));

	std::cout << "Testando ligacao entre os vertices 7 e 6..." << std::endl;
	assert(grafo.estao_ligados(7, 6));

	std::cout << "Testando ligacao entre os vertices 7 e 9..." << std::endl;
	assert(grafo.estao_ligados(7, 9));

	std::cout << "Testando ligacao entre os vertices 2 e 5..." << std::endl;
	assert(grafo.estao_ligados(2, 5));

	std::cout << "Testando ligacao entre os vertices 5 e 2..." << std::endl;
	assert(grafo.estao_ligados(5, 2));

	std::cout << "Testando ligacao entre os vertices 0 e 2..." << std::endl;
	assert(grafo.estao_ligados(0, 2));


	std::cout << "<<< TesteGrafo::testa_ligacoes" << std::endl;
}

void TesteGrafo::testa_dijkstra(Grafo& grafo) {
	std::cout << ">>> TesteGrafo::testa_dijkstra" << std::endl;


	std::vector<unsigned int> menor_caminho;
	Algoritmos::dijkstra(grafo, menor_caminho);


	std::cout << "<<< TesteGrafo::testa_dijkstra" << std::endl;
}
