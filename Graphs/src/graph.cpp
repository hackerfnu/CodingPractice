#include "graph.h"

Graph_Obj::Graph_Obj()
{
}


void Graph_Obj::add_vertex(int key1, int key2)
{
	std::cout<<"Adding vertex";
}

void Graph_Obj::add_edge(int key1, int key2)
{
	// std::cout<<"Adding Edge";
	if (_graph.find(key1) == _graph.end())
	{
		std::unordered_set<int> vect{key2};
		_graph[key1] = vect;
	}
	else
	{
		_graph[key1].insert(key2);
	}

	if (_graph.find(key2) == _graph.end())
	{
		std::unordered_set<int> vect{key1};
		_graph[key2] = vect;
	}
	else
	{
		_graph[key2].insert(key1);
	}
}


void Graph_Obj::print_edges()
{
	std::cout<<"Printing All edges";
	for (const auto &element : _graph) {
	    std::cout << element.first << ": ";
	    for(const auto &edge_elem : element.second)
	    {
	    	std::cout<<edge_elem<<",";
	    }
	    std::cout<<std::endl;
	}

}

bool Graph_Obj::DFS(int key1,int key2)
{
	/* TODO: Have 3 data structure
	1.Visited
	2.node to explore that always PUT NEW FIRST in _open_list
	3.Data structure that keep track of predecesor
	Might use recusrsion
	*/
	return false;
}

bool Graph_Obj::BFS(int key1,int key2)
{
	/* TODO: Have 3 data structure
	1.Visited
	2.node to explore that always PUT NEW At THE END in _open_list
	3.Data structure that keep track of predecesor
	*/
	return false;
}

void Graph_Obj::BackTrack(int key1, int key2)
{
	int element = key2;
	std::list<int> path;
	path.push_front(element);
	while(element != key1)
	{
		element = _pred[element];
		path.push_front(element);

	}

	std::cout<<"Path: ";
	for(const auto &elem: path){
		std::cout<<elem<<",";
	}
	std::cout<<std::endl;

}


void Graph_Obj::ForwardBFS(int key1,int key2)
{
	_open_list.push_back(key1);
	bool result = BFS(key1,key2);
	if(result == true)
	{
		BackTrack(key1,key2);
	}
	else
		std::cout<<"Path not found\n";

}

void Graph_Obj::ForwardDFS(int key1,int key2)
{
	_open_list.push_back(key1);
	bool result = DFS(key1,key2);
	if(result == true)
	{
		BackTrack(key1,key2);
	}
	else
		std::cout<<"Path not found\n";

}

