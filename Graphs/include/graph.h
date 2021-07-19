#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <utility>
#include <boost/functional/hash.hpp>
#include <cmath>
#include <cstdlib>

class Graph_Obj
{
        private:
          std::unordered_map<int,std::unordered_set<int>> _graph;
          std::unordered_map<int,int> _pred;
          std::unordered_map<int,bool> _visited;
          std::list<int> _open_list;

        public:
           Graph_Obj();
           void add_vertex(int key1, int key2);
           void add_edge(int key1, int key2);
           void print_edges();
           bool DFS(int key1,int key2);
           bool BFS(int key1,int key2);
           void BackTrack(int key1, int key2);
           void ForwardBFS(int key1,int key2);
           void ForwardDFS(int key1,int key2);
};
