#include "graph.h"

void GraphImpl::AddEdge(int key1, int key2) {
	_graph[key1].insert(key2);
}

void GraphImpl::PrintBFSTraversal() {
    while (!_bfs_traversal_result.empty())
    {
        std::cout<<_bfs_traversal_result.front()<<" -> ";
        _bfs_traversal_result.pop();
    }
    std::cout<<"end"<<std::endl;
}

void GraphImpl::BFS(int start_node) {
	_query_queue.push(start_node);
	_visited.resize(_graph.size(), 0);
	int node_idx;
    _visited[start_node] = 1;
	while (!_query_queue.empty()) {
        node_idx = _query_queue.front();
		for(auto neighbour: _graph[node_idx]) {
			if (!_visited[neighbour])
			{
				_query_queue.push(neighbour);
                _visited[neighbour] = 1;
			}
		}
		_bfs_traversal_result.push(node_idx);
		_query_queue.pop();
    }
    PrintBFSTraversal();
}

void GraphImpl::PrintEdges() {
	std::cout<<"Printing all edges"<<std::endl;
	for (const auto &element : _graph) {
	    std::cout << element.first << ": ";
	    for(const auto &edge_elem : element.second)
	    {
	    	std::cout<<edge_elem<<" ";
	    }
	    std::cout<<std::endl;
	}

}