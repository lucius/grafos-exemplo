/*
 * Grafo.h
 *
 *  Created on: Nov 23, 2008
 *      Author: Evandro Couto Mantese
 *      Author: Marcus Vinicius Ventura Bortolotti
 *      Author: Rafael de Paula Herrera
 */

#ifndef GRAFO_H_
#define GRAFO_H_

#include <map>
#include <vector>
#include <utility>

class
Grafo
{
	public:
		class
		Vertice;

		Grafo();

		virtual
		~Grafo();

		void
		adiciona_vertice(Vertice* vertice);

		Vertice*
		vertice(unsigned int id);

		void
		reseta_cores();

	protected:
		std::map<unsigned int, Grafo::Vertice*>		// Chave: Vertice._id, Valor: Vertice
		_vertices;
};

class
Grafo::Vertice
{
	public:
		Vertice(unsigned int identificador);

		~Vertice();

		unsigned int
		id();

		void
		liga_com(Grafo::Vertice* vertice, unsigned int peso);

		bool
		esta_ligado_com(Grafo::Vertice* vertice);

		std::vector< std::pair<Grafo::Vertice*, unsigned int> >
		antecessores();

		void
		adiciona_antecessor(Grafo::Vertice* antecessor, unsigned int peso);

		std::vector< std::pair<Grafo::Vertice*, unsigned int> >
		sucessores();

		void
		adiciona_sucessor(Grafo::Vertice* sucessor, unsigned int peso);

		enum
		Cores
		{
			BRANCO	= 0,
			CINZA	= 1,
			PRETO	= 2
		};

		Cores
		_cor;

	protected:
		unsigned int
		_id;

		std::vector< std::pair<Vertice*, unsigned int> >	// First: Vertice, Second: peso
		_antecessores;

		std::vector< std::pair<Vertice*, unsigned int> >	// First: Vertice, Second: peso
		_sucessores;
};

#endif /* GRAFO_H_ */
