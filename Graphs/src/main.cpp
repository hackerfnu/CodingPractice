#include <iostream>
#include <queue> 
#include <unordered_map> 
#include <vector> 
#include <utility> 
#include <boost/functional/hash.hpp>
#include <cmath>
#include <cstdlib> 
#include "graph.h"    


int main()
{
	std::cout<<"Wut\n";
	Graph_Obj new_graph;
	new_graph.add_edge(1,2);
	new_graph.add_edge(1,3);
	new_graph.add_edge(2,4);
	new_graph.add_edge(2,5);
	new_graph.add_edge(3,4);
	new_graph.add_edge(5,6);
	new_graph.print_edges();
	new_graph.ForwardDFS(1,4);
}