#ifndef DIRECTEDEDGE_H_
#define DIRECTEDEDGE_H_

class DirectedEdge{

	int node0;		// node number of the head node
	int node1;		// node number of the tail node

	double weight;	// weight of the ordered edge

public:
	DirectedEdge(int n0, int n1, double w): node0(n0), node1(n1), weight(w) {}

	// returns the head node of the ordered edge
	int from();

	// returns the tail node of the ordered edge
	int to();

	// returns the weight of the ordered edge
	double getWeight();
};

#endif /* DIRECTEDEDGE_H_ */
