#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <utility>
#include <cmath>
#include <cstdlib>

using Pose = std::pair<int, int>;

struct NodeInfo {
  int g_cost = INT_MAX;
  int h_cost = 0;
  Pose pred = {-1, -1};
  bool is_closed = false;
};

struct HashPair {
  template <class T1, class T2>
  std::size_t operator()(const std::pair<T1, T2>& p) const {
    auto h1 = std::hash<T1>{}(p.first);
    auto h2 = std::hash<T2>{}(p.second);

    // Mainly for demonstration purposes, i.e. works but is overly simple
    // In the real world, use sth. like boost.hash_combine
    return h1 ^ h2;
  }
};

class GeneralPlanner
{
        private:
          int* map_;
          int num_row_;
          int num_col_;
          int num_of_dir_;
          int* dx_;
          int* dy_;

         public:
          GeneralPlanner(int* map, int row, int col, int num_of_dir, int* dx,
                         int* dy);

          // Searc Algorithms
          void search(Pose src, Pose dst, std::string algo_name);
          std::deque<Pose> AStarSearch(Pose src, Pose dst);
          std::deque<Pose> DjikstraSearch(Pose src, Pose dst);
          std::deque<Pose> BellmanFordSearch(Pose src, Pose dst);
          std::deque<Pose> Backtrack(
              Pose src, Pose dst,
              std::unordered_map<Pose, NodeInfo, HashPair>& node_map);

          // Util Functions
          void MapPrinter();
          int GetCoordValue(Pose pose);
          bool isValidPose(Pose pose);
          Pose GetCoord(int ind);
};