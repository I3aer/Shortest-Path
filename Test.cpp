#include "DijkstraSP.h"
#include <exception>
#include <iostream>
#include <stdlib.h>

int main(int argc, char** argv)
{
	string gfile;
	int s, t;

	try
	{
		if (argc == 1)
		{
			gfile.assign("digraph.txt");

			s = atoi("0");

			// target node
			t = atoi("3");

		}
		else
		{
			// digraph file
			gfile.assign(argv[1]);

			// source node
			s = atoi(argv[2]);

			// target node
			t = atoi(argv[3]);

		}

		// digraph object
		Digraph dgraph (gfile);

		std::cout << "digraph was generated\n";

		// compute shortest paths
		DijkstraSP sp (dgraph, s);

		std::cout << "shortest paths were found\n";

		// print the shortest path
		vector<int> sp_st = sp.pathTo(t);

		std::cout << "the shortest path from node " << s << " to " << "node " << t  << ":\n";

		vector<int>::reverse_iterator rit;
		for (rit = sp_st.rbegin(); rit!= sp_st.rend(); ++rit)
		    std::cout << *rit  << "\t";

	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}




