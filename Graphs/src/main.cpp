#include <iostream>
#include <queue> 
#include <unordered_map> 
#include <vector> 
#include <utility> 
#include <cmath>
#include <cstdlib> 
#include "graph.h"    

int main()
{
	std::cout<<"Wut\n";
	GraphImpl sampleGraph;
	sampleGraph.AddEdge(1,2);
	sampleGraph.AddEdge(1,3);
	sampleGraph.AddEdge(2,4);
	sampleGraph.AddEdge(2,5);
	sampleGraph.AddEdge(3,4);
	sampleGraph.AddEdge(5,6);
	sampleGraph.PrintEdges();

	sampleGraph.BFS(1);
}