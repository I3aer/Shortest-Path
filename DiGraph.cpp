#include "Digraph.h"

Digraph::Digraph(string filename): numV(0), numE(0)
{
	string line; 		// line
	int linenum = 0;	// line number

	int n0, n1;   // head and tail nodes
	double w;     // weight of the edge

	// open the file for reading
	ifstream infile (filename.c_str());

	// check if the file is open
	if ( infile.is_open() )
	{
		// Read the next line from File until it reaches the end.
		while (std::getline(infile, line))
		{

			// string stream object to tokenize each lines
			std::istringstream iss(line);

			// read the number of nodes
			if (linenum == 0){
				iss >> numV;

				if (numV < 0)
					throw std::invalid_argument("number of edges cannot be negative");
			}

			// read the number of edges
			else if (linenum == 1) {
				iss >> numE;

				if (numE < 0)
					throw std::invalid_argument("number of nodes cannot be negative");
			}

			// read the ordered pairs and weight to add a directed edge
			else
			{
				iss >> n0 >> n1 >> w;

				addEdge(DirectedEdge(n0, n1, w));
			}

			++linenum;
		}

		infile.close();
	}
	else
		throw std::runtime_error("could not the open file");

}

void Digraph::addEdge(DirectedEdge e)
{

	int n0 = e.from();
	int n1 = e.to();
	double w = e.getWeight();

	// validate the directed edge e
	if (n0 == n1)
		throw std::invalid_argument("nodes cannot be same");

	else if (n0 < 0 || n0 >= numV)
		throw std::invalid_argument("invalid head node" );

	else if (n1 < 0 || n1 >= numV)
		throw std::invalid_argument("invalid tail node");

	else if (w < 0 )
		throw std::invalid_argument("negative edge weight");

    // add the edge e from node n0 to node n1
	adjlist[n0].push_back(e);
}

int Digraph::getV() { return numV; }

int Digraph::getE() { return numE; }

vector<DirectedEdge> Digraph::getEdges(int u)
{
	return adjlist[u];
}

