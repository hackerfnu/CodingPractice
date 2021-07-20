#include <iostream>
#include <unordered_map> 
#include <unordered_set> 
#include <vector> 
#include <queue>

class GraphImpl {
  private:
    std::unordered_map<int, std::unordered_set<int>> _graph;
    std::queue<int> _bfs_traversal_result;
    std::queue<int> _query_queue;
    std::vector<bool> _visited;
  public:
    GraphImpl() {};
    void AddEdge(int node1, int node2);
    void PrintBFSTraversal();
    void BFS(int start_node);
    void PrintEdges();
};
