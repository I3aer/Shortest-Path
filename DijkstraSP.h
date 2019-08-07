#ifndef DIJKSTRASP_H_
#define DIJKSTRASP_H_

#include "Digraph.h"
#include <set>
#include <limits>

using std::multiset;


class DijkstraSP{

	vector<double> distTo;          	     // distTo[v] = distance of shortest s->v path
    vector<int> edgeTo;    	     			 // edgeTo[v] = last edge on shortest s->v path
    multiset<std::pair<double, int> > pq;    // min-priority queue in the form (weight,node)
    vector<bool> visNodes; 				     // vector of visited nodes
	const double inf;						 // positive infinity

public:

    /* Solves the single-source shortest paths problem for a weighted digraphs
     * with positive weights using the Dijkstra's shortest path algorithm. This
     * implementation of the Dijkstra's shortest path algorithm uses a binary min-heap
     */
    DijkstraSP(Digraph, int);

    /*
     * Relax the distances of the connected nodes to the popped node in case of
     * current node distance + edge weight < next node distance, then push the
     * new node with its new distance to min-priority queue.
     */
    void relax(DirectedEdge);

    /*
     * Returns true if there is a path from the source s to node v
     */
    bool hasPathTo(int);

    /*
     * Returns a shortest path (node numbers) from the source s to node v
     */
     vector<int> pathTo(int);

     // throw invalid argument exception  unless 0 <= v < V
     void validateVertex(int);

};

#endif




