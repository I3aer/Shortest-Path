#include "DijkstraSP.h"
#include <iostream>

DijkstraSP::DijkstraSP(Digraph G, int s)
            : distTo(G.getV()),
			  edgeTo(G.getV(),-1),
			  visNodes(G.getV(),false),
			  inf(std::numeric_limits<double>::infinity())
{

	// set all d[v] = infinity except that d[s] = 0
	vector<double>::iterator it;
	for (it = distTo.begin(); it != distTo.end(); ++it)
	{
		*it = inf;
	}
	distTo[s] = 0;

	// relax vertices in order of distance from s
	pq.insert(std::make_pair( distTo[s], s));

	while (!pq.empty())
	{
		// pop the node with the minimum weight
		std::pair<int , int> p = *pq.begin();

		// remove the element with minimum weight
		pq.erase(pq.begin());

		for (DirectedEdge & e : G.getEdges(p.second))
			relax(e);

		// set visit flag true for the selected node
		visNodes[p.second] = true;
	}

}

void DijkstraSP::relax(DirectedEdge edge)
{
    // head and tail nodes
	int n0, n1;

	// weight of edge
	double w;

	n0 = edge.from();

	n1 = edge.to();

	w = edge.getWeight();

	// check node n1 visited before
	if (!visNodes[n1])
	{
		// check the relaxation condition
		if (distTo[n1] > distTo[n0] + w)
		{
			// update the weight of path to s
			distTo[n1] = distTo[n0] + w;

			// update the predecessor of n1
			edgeTo[n1] = n0;
		}
		// insert the next vertex with the updated distance
		pq.insert(std::make_pair(distTo[n1],  n1));

	}
}

void DijkstraSP::validateVertex(int v)
{
	int V = distTo.size();

	if (v < 0 || v >= V)
		throw std::invalid_argument("invalid node");
}

bool DijkstraSP::hasPathTo(int v)
{

	validateVertex(v);

	return distTo[v] < inf ? true : false;
}


vector<int> DijkstraSP::pathTo(int v)
{
	// shortest path
	vector<int> path;

	if (!hasPathTo(v))
		return path;

	path.push_back(v);

    for (int e = edgeTo[v]; e != -1; e = edgeTo[e])
    {
    	path.push_back(e);
    }

    return path;
}

