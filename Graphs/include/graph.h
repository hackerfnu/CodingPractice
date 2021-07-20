#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <list>


class Graph_Obj
{
        private:
          std::unordered_map<int, std::unordered_set<int> > graph_;

        public:
           Graph_Obj();
           void add_edge(int key1, int key2);
           void print_edges();
           void Search(int key1,int key2, std::string mode = "BFS");
           std::list<int> Backtrack(int key1, int key2, std::unordered_map<int,int> &pred);
};
