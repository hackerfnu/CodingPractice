#include "planner.h"

GeneralPlanner::GeneralPlanner(int* map, int row, int col)
{
	map_ = map;
	map_row_ = row;
	map_col_ = row;
	MapPrinter(); //Can remove the printer if you want
}

// Helper function to print map
void GeneralPlanner::MapPrinter() {
	std::cout<<"MAP:"<<"\n";
	for(int i = 0; i < map_row_*map_col_; i++) {
		std::cout<<*(map_+i)<<",";
		if((i+1)%map_col_ == 0) std::cout<<"\n";
	}
}

// Search landing function that lead to main search algos
// Don't need to modify this function, but always welcome to :)
void GeneralPlanner::search(std::pair<int,int> src, std::pair<int,int> dst, std::string algo_name) {
	std::vector< std::pair<int,int> > path;
	if (algo_name == "AStar") {
		path = AStarSearch(src, dst);
	}
	else if (algo_name == "Djikstra") {
		path = DjikstraSearch(src, dst);
	} else if (algo_name == "BellmanFord") {
		path = GeneralPlanner::BellmanFordSearch(src, dst);
	}

	if(path.empty()) {
		std::cout<<"Cannot find path!\n";
		return;
	}
	std::cout<<"path:";
	for(auto &node : path) {
		std::cout<<node.first<<","<<node.second<<"\n";
	}
}
std::vector< std::pair<int,int> > GeneralPlanner::AStarSearch(std::pair<int,int> src, std::pair<int,int> dst) {
	// TODO: Implement A Star and return the shortest path from src -> dst as vector< std::pair<int,int> >
	return std::vector< std::pair<int,int> >{};
}
std::vector< std::pair<int,int> > GeneralPlanner::DjikstraSearch(std::pair<int,int> src, std::pair<int,int> dst) {
	// TODO: Implement Djikstra and return the shortest path from src -> dst as vector< std::pair<int,int> >
	return std::vector< std::pair<int,int> >{};
}
std::vector< std::pair<int,int> > GeneralPlanner::BellmanFordSearch(std::pair<int,int> src, std::pair<int,int> dst) {
	// TODO: Implement Bellman-ford and return the shortest path from src -> dst as vector< std::pair<int,int> >
	return std::vector< std::pair<int,int> >{};
}