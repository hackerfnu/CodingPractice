#include "graph.h"

Graph_Obj::Graph_Obj()
{
}


void Graph_Obj::add_edge(int key1, int key2)
{
	if(graph_.find(key1) == graph_.end()) {
		std::unordered_set<int> key1_vect{key2};
		graph_[key1] = std::move(key1_vect);
	}
	else {
		graph_[key1].insert(key2);
	}

	if(graph_.find(key2) == graph_.end()) {
		std::unordered_set<int> key2_vect{key1};
		graph_[key2] = std::move(key2_vect);
	} else {
		graph_[key2].insert(key1);
	}
	return;
}


void Graph_Obj::print_edges()
{
	for(const auto &node_it : graph_) {
		std::cout<<"Node["<<node_it.first<<"]: ";
		for(const auto &elem : node_it.second) {
			std::cout<<elem<<",";
		}
		std::cout<<"\n";
	}
}

void Graph_Obj::Search(int key1,int key2, std::string mode)
{
	/* TODO: Have 3 data structure
	1.Visited
	2.node to explore that always PUT NEW FIRST if DFS, put LAST if BFS
	3.Data structure that keep track of predecesor
	*/
	std::cout<<"running search mode "<<mode<<"\n";
	std::unordered_set<int> visited;
	std::unordered_map<int,int> pred;
	std::list<int> open_list;
	open_list.push_back(key1);
	int cur_node = key1;
	bool goal_found = false;
	while(!open_list.empty() && !goal_found) {
		cur_node = open_list.front();
		open_list.pop_front();
		for(auto child_node : graph_[cur_node]) {
			if(visited.find(child_node) != visited.end()) continue;
			if(mode == "BFS") {
				open_list.push_back(child_node);
			}
			else if( mode == "DFS") {
				open_list.push_front(child_node);
			}
			visited.insert(child_node);
			pred[child_node] = cur_node;
			if(child_node == key2) goal_found = true;
		}
	}
	if(!goal_found) std::cout<<"No path found!\n";
	auto path = Backtrack(key1, key2, pred);
	std::cout<<"Path found:";
	for(auto iter : path) {
		std::cout<<iter<<",";
	}
	std::cout<<"\n";
}

std::list<int> Graph_Obj::Backtrack(int key1,int key2, std::unordered_map<int,int>& pred)
{
	int cur_node = key2;
	std::list<int> path;
	bool found_origin = false;
	while(!found_origin) {
		if(cur_node == key1) found_origin = true;
		path.push_front(cur_node);
		cur_node = pred[cur_node];
		std::cout<<"cur_node:"<<cur_node<<"\n";
	}
	return path;
}
