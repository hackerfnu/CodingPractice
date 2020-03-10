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
	2.node to explore that always PUT NEW FIRST
	3.Data structure that keep track of predecesor
	*/
	std::cout<<"DFS"<<key1<<","<<key2<<"\n";
	_open_list.pop_front();
	_visited[key1] = true;
	for(const auto &element : _graph[key1])
	{
		if(_visited.find(element) == _visited.end())
		{
			_pred[element] = key1;
			if(element == key2)
				return true;
			_open_list.push_front(element);
		}
	}
	if(_open_list.empty())
		return false;
	DFS(_open_list.front(),key2);
}

bool Graph_Obj::BFS(int key1,int key2)
{
	/* TODO: Have 3 data structure
	1.Visited
	2.node to explore that always PUT NEW At THE END
	3.Data structure that keep track of predecesor
	*/
	std::cout<<"BFS"<<key1<<","<<key2<<"\n";
	_open_list.pop_front();
	_visited[key1] = true;
	for(const auto &element : _graph[key1])
	{
		if(_visited.find(element) == _visited.end())
		{
			_pred[element] = key1;
			if(element == key2)
				return true;
			_open_list.push_back(element);
		}
	}
	if(_open_list.empty())
		return false;
	BFS(_open_list.front(),key2);
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

