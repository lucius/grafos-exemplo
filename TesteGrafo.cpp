/*
 * TesteGrafo.cpp
 *
 *  Created on: Nov 23, 2008
 *      Author: Evandro Couto Mantese
 *      Author: Marcus Vinicius Ventura Bortolotti
 *      Author: Rafael de Paula Herrera
 */

#include <assert.h>
#include <iostream>
#include <vector>
#include "Algoritmos.h"
#include "Grafo.h"
#include "TesteGrafo.h"

void
TesteGrafo::todos_testes() {
	std::cout << ">>> TesteGrafo::todos_testes" << std::endl;


	std::cout << "Criando grafo com 10 vertices..." << std::endl;

	Grafo
	grafo;

	Grafo::Vertice
	*vertice0 = new Grafo::Vertice(0),
	*vertice1 = new Grafo::Vertice(1),
	*vertice2 = new Grafo::Vertice(2),
	*vertice3 = new Grafo::Vertice(3),
	*vertice4 = new Grafo::Vertice(4),
	*vertice5 = new Grafo::Vertice(5),
	*vertice6 = new Grafo::Vertice(6),
	*vertice7 = new Grafo::Vertice(7),
	*vertice8 = new Grafo::Vertice(8),
	*vertice9 = new Grafo::Vertice(9);

	grafo.adiciona_vertice(vertice0);
	grafo.adiciona_vertice(vertice1);
	grafo.adiciona_vertice(vertice2);
	grafo.adiciona_vertice(vertice3);
	grafo.adiciona_vertice(vertice4);
	grafo.adiciona_vertice(vertice5);
	grafo.adiciona_vertice(vertice6);
	grafo.adiciona_vertice(vertice7);
	grafo.adiciona_vertice(vertice8);
	grafo.adiciona_vertice(vertice9);

	vertice0->liga_com(vertice1, 5);
	vertice0->liga_com(vertice2, 2);
	vertice0->liga_com(vertice3, 3);
	vertice1->liga_com(vertice4, 2);
	vertice2->liga_com(vertice5, 5);
	vertice3->liga_com(vertice4, 1);
	vertice3->liga_com(vertice6, 4);
	vertice4->liga_com(vertice0, 4);
	vertice4->liga_com(vertice8, 7);
	vertice6->liga_com(vertice7, 4);
	vertice7->liga_com(vertice8, 3);
	vertice7->liga_com(vertice9, 5);


	testa_ligacoes(grafo);
	testa_adjacentes(grafo, 0);
	testa_adjacentes(grafo, 4);
	testa_busca_largura(grafo, 0, 5);
	testa_busca_profundidade(grafo, 0, 5);
	testa_busca_largura(grafo, 0, 9);
	testa_busca_profundidade(grafo, 0, 9);
//	testa_dijkstra(grafo);


	std::cout << "<<< TesteGrafo::todos_testes" << std::endl;
}

void
TesteGrafo::testa_ligacoes(Grafo& grafo) {
	std::cout << ">>> TesteGrafo::testa_ligacoes" << std::endl;

	std::cout << "Testando ligacao entre os vertices 0 e 1..." << std::endl;
	assert(grafo.vertice(0)->esta_ligado_com(grafo.vertice(1)));
	std::cout << "Testando ligacao entre os vertices 1 e 0..." << std::endl;
	assert(grafo.vertice(1)->esta_ligado_com(grafo.vertice(0)));
	std::cout << "Testando ligacao entre os vertices 3 e 6..." << std::endl;
	assert(grafo.vertice(3)->esta_ligado_com(grafo.vertice(6)));
	std::cout << "Testando ligacao entre os vertices 6 e 3..." << std::endl;
	assert(grafo.vertice(6)->esta_ligado_com(grafo.vertice(3)));
	std::cout << "Testando ligacao entre os vertices 3 e 4..." << std::endl;
	assert(grafo.vertice(3)->esta_ligado_com(grafo.vertice(4)));
	std::cout << "Testando ligacao entre os vertices 4 e 0..." << std::endl;
	assert(grafo.vertice(4)->esta_ligado_com(grafo.vertice(0)));
	std::cout << "Testando ligacao entre os vertices 4 e 3..." << std::endl;
	assert(grafo.vertice(4)->esta_ligado_com(grafo.vertice(3)));
	std::cout << "Testando ligacao entre os vertices 8 e 7..." << std::endl;
	assert(grafo.vertice(8)->esta_ligado_com(grafo.vertice(7)));
	std::cout << "Testando ligacao entre os vertices 7 e 6..." << std::endl;
	assert(grafo.vertice(7)->esta_ligado_com(grafo.vertice(6)));
	std::cout << "Testando ligacao entre os vertices 7 e 9..." << std::endl;
	assert(grafo.vertice(7)->esta_ligado_com(grafo.vertice(9)));
	std::cout << "Testando ligacao entre os vertices 2 e 5..." << std::endl;
	assert(grafo.vertice(2)->esta_ligado_com(grafo.vertice(5)));
	std::cout << "Testando ligacao entre os vertices 5 e 2..." << std::endl;
	assert(grafo.vertice(5)->esta_ligado_com(grafo.vertice(2)));
	std::cout << "Testando ligacao entre os vertices 0 e 2..." << std::endl;
	assert(grafo.vertice(0)->esta_ligado_com(grafo.vertice(2)));
	std::cout << "Testando ligacao entre os vertices 0 e 0..." << std::endl;
	assert(!grafo.vertice(0)->esta_ligado_com(grafo.vertice(0)));

	std::cout << "<<< TesteGrafo::testa_ligacoes" << std::endl;
}

void
TesteGrafo::testa_adjacentes(Grafo& grafo, unsigned int vertice) {
	std::cout << ">>> TesteGrafo::testa_adjacentes" << std::endl;

	Grafo::Vertice*
	vertice_teste = grafo.vertice(vertice);

	if (vertice_teste)
	{
		std::cout << "Testando as adjacencias do vertice " << vertice << std::endl;

		std::vector< std::pair<Grafo::Vertice*, unsigned int> >
		antecessores =  vertice_teste->antecessores();

		std::cout << "    Vertices antecessores:" << std::endl;
		for (std::vector< std::pair<Grafo::Vertice*, unsigned int> >::iterator it = antecessores.begin();
				it != antecessores.end(); ++it)
		{
			std::cout << "        id: " << it->first->id() << " peso: " << it->second << std::endl;
		}

		std::vector< std::pair<Grafo::Vertice*, unsigned int> >
		sucessores =  vertice_teste->sucessores();
		std::cout << "    Vertices sucessores:" << std::endl;
		for (std::vector< std::pair<Grafo::Vertice*, unsigned int> >::iterator it = sucessores.begin();
				it != sucessores.end(); ++it)
		{
			std::cout << "        id: " << it->first->id() << " peso: " << it->second << std::endl;
		}
	}
	else
	{
		std::cout << "Erro: Vertice " << vertice << " nao encontrado" << std::endl;
	}


	std::cout << "<<< TesteGrafo::testa_adjacentes" << std::endl;
}

void
TesteGrafo::testa_busca_largura(Grafo& grafo, unsigned int vertice_origem, unsigned int vertice_destino)
{
	std::cout << ">>> TesteGrafo::testa_busca_largura" << std::endl;

	Grafo::Vertice
	*vertice_teste_origem	= grafo.vertice(vertice_origem),
	*vertice_teste_destino	= grafo.vertice(vertice_destino);

	if (!vertice_teste_origem)
	{
		std::cout << "ERRO: Vertice de origem " << vertice_origem << " nao encontrado." << std::endl;
		return;
	}

	if (!vertice_teste_destino)
	{
		std::cout << "ERRO: Vertice de destino " << vertice_destino << " nao encontrado." << std::endl;
		return;
	}

	std::cout << "Partindo do vertice " << vertice_origem << " ate o vertice " << vertice_destino << std::endl;

	std::vector<unsigned int>*
	caminho = Algoritmos::busca_largura(grafo, vertice_origem, vertice_destino);

	std::cout << "Caminho percorrido:" << std::endl;

	for (std::vector<unsigned int>::iterator it = caminho->begin(); it != caminho->end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	std::cout << "<<< TesteGrafo::testa_busca_largura" << std::endl;
}

void
TesteGrafo::testa_busca_profundidade(Grafo& grafo, unsigned int vertice_origem, unsigned int vertice_destino)
{
	std::cout << ">>> TesteGrafo::testa_busca_profundidade" << std::endl;

	Grafo::Vertice
	*vertice_teste_origem	= grafo.vertice(vertice_origem),
	*vertice_teste_destino	= grafo.vertice(vertice_destino);

	if (!vertice_teste_origem)
	{
		std::cout << "ERRO: Vertice de origem " << vertice_origem << " nao encontrado." << std::endl;
		return;
	}

	if (!vertice_teste_destino)
	{
		std::cout << "ERRO: Vertice de destino " << vertice_destino << " nao encontrado." << std::endl;
		return;
	}

	std::cout << "Partindo do vertice " << vertice_origem << " ate o vertice " << vertice_destino << std::endl;

	std::vector<unsigned int>*
	caminho = Algoritmos::busca_profundidade(grafo, vertice_origem, vertice_destino);

	std::cout << "Caminho percorrido:" << std::endl;

	for (std::vector<unsigned int>::iterator it = caminho->begin(); it != caminho->end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	std::cout << "<<< TesteGrafo::testa_busca_profundidade" << std::endl;
}

void
TesteGrafo::testa_dijkstra(Grafo& grafo) {
	std::cout << ">>> TesteGrafo::testa_dijkstra" << std::endl;


//	std::vector<unsigned int> menor_caminho;
//	Algoritmos::dijkstra(grafo, menor_caminho);


	std::cout << "<<< TesteGrafo::testa_dijkstra" << std::endl;
}
