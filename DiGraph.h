#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include "DirectedEdge.h"

using std:: vector;
using std::map;
using std::string;
using std::ifstream;

#ifndef DIGRAPH_H_
#define DIGRAPH_H_

class Digraph{

	int numV;      // number of nodes in this digraph
    int numE;      // number of edges in this digraph

    // adjacency list to represent the weighted digraph
    map<int,vector<DirectedEdge> > adjlist;

public:
       /*
        * Initializes a weighted digraph from the specified input file:
        * The first line is the number of nodes numV,
        * the next line is the number of edges numE,
        * the following lines are the ordered pairs
        * of nodes and their weights with each entry
        * separated by whitespace., i.e., u, v, w for
        * a edge from node u to node v with weight w.
        *
        * throws runtime exception  if the input file cannot be cannot be opened.
        */
       Digraph(string);

       /*
		* Adds a directed edge to the digraph.
		*
        * throws argument exception if the tail and head nodes are not in the range.
        * throws argument exception if the number of vertices or edges is negative.
		*/
       void addEdge(DirectedEdge);

		/*
		 * Returns the number of nodes in this weighted digraph.
		 */
       int getV();

       /*
       	* Return the number of edges in this weighted digraph.
       	*/
       int getE();

       /*
        *  Return the directed edges of a node
        */
       vector<DirectedEdge> getEdges(int);


};



#endif /* DIGRAPH_H_ */
