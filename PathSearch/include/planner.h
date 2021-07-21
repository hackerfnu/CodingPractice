#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <utility>
#include <cmath>
#include <cstdlib>

class GeneralPlanner
{
        private:
          int* map_;
          int map_row_;
          int map_col_;

        public:
           GeneralPlanner(int* map, int row, int col);
           void search(std::pair<int,int> src, std::pair<int,int> dst, std::string algo_name);
           std::vector< std::pair<int,int> > AStarSearch(std::pair<int,int> src, std::pair<int,int> dst);
           std::vector< std::pair<int,int> > DjikstraSearch(std::pair<int,int> src, std::pair<int,int> dst);
           std::vector< std::pair<int,int> > BellmanFordSearch(std::pair<int,int> src, std::pair<int,int> dst);
           void MapPrinter();
};
