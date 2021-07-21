#include "planner.h"

GeneralPlanner::GeneralPlanner(int* map, int row, int col, int num_of_dir,
                               int* dx, int* dy)
    : map_(map),
      num_row_(row),
      num_col_(col),
      num_of_dir_(num_of_dir),
      dx_(dx),
      dy_(dy) {
  MapPrinter();  // Can remove the printer if you want
}

// Helper function to print map
void GeneralPlanner::MapPrinter() {
  std::cout << "MAP:"
            << "\n";
  for (int i = 0; i < num_row_ * num_col_; i++) {
    std::cout << *(map_ + i) << ",";
    if ((i + 1) % num_col_ == 0) std::cout << "\n";
  }
}

int GeneralPlanner::GetCoordValue(Pose pose) {
  return *(map_ + pose.second * num_col_ + pose.first);
}

Pose GeneralPlanner::GetCoord(int ind) {
  int x = ind % num_col_;
  int y = ind / num_col_;
  return std::make_pair(x, y);
}

bool GeneralPlanner::isValidPose(Pose pose) {
  // Check pose is on map
  if (pose.first > num_col_ - 1 || pose.first < 0) return false;
  if (pose.second > num_row_ - 1 || pose.second < 0) return false;
  // Check pose is not obstacle
  if (GetCoordValue(pose) == 0) return false;
  return true;
}

// Search landing function that lead to main search algos
// Don't need to modify this function, but always welcome to :)
void GeneralPlanner::search(Pose src, Pose dst, std::string algo_name) {
  std::deque<Pose> path;
  if (algo_name == "AStar") {
    path = AStarSearch(src, dst);
  } else if (algo_name == "Djikstra") {
    path = DjikstraSearch(src, dst);
  } else if (algo_name == "BellmanFord") {
    path = GeneralPlanner::BellmanFordSearch(src, dst);
  }

  if (path.empty()) {
    std::cout << "Cannot find path!\n";
    return;
  }
  std::cout << "path:\n";
  for (auto& node : path) {
    std::cout << node.first << "," << node.second << "\n";
  }
}

std::deque<Pose> GeneralPlanner::Backtrack(
    Pose src, Pose dst,
    std::unordered_map<Pose, NodeInfo, HashPair>& node_map) {
  std::deque<Pose> path;
  Pose cur_node = dst;
  path.push_front(cur_node);
  while (cur_node != src) {
    cur_node = node_map[cur_node].pred;
    if (cur_node.first == -1 && cur_node.second == -1)
      return std::deque<Pose>{};
    path.push_front(cur_node);
  }
  return path;
}

float diagonal_distance(Pose src, Pose dst) {
  // Remember that heuristic needs to be consistent and admissable
  float dist_x = abs(src.first - dst.first);
  float dist_y = abs(src.second - dst.second);
  return std::max(dist_x, dist_y) - std::min(dist_x, dist_y) +
         std::sqrt(2) * std::min(dist_x, dist_y);
}

std::deque<Pose> GeneralPlanner::AStarSearch(Pose src, Pose dst) {
  // Implement A Star and return the shortest path from src -> dst
  // 1.Initialize open list as prio queue with g_cost(ensure shortest
  // path)+h_cost(guide search for faster reach) as priority
  //   then set start point to open_list and set cost as 0 while setting all
  //   other points with value of INT_MAX
  // 2.Repeat until open_list empty:
  //    a.Explore top of open_list and put in closed list
  //    b.Check all successor that is valid point and not closed
  //    c.If found shorter path/cost update with new cost and pred(relaxation)
  //    d.If expanding current goal node break
  std::unordered_map<Pose, NodeInfo, HashPair> node_map;
  auto cmp = [&](Pose left, Pose right) {
    return (node_map[left].g_cost + node_map[left].h_cost) >
           (node_map[right].g_cost + node_map[right].h_cost);
  };
  std::priority_queue<Pose, std::vector<Pose>, decltype(cmp)> open_list(cmp);
  open_list.push(src);
  Pose cur_pose = src;
  bool goal_found = false;
  node_map[cur_pose].g_cost = 0;
  while (!open_list.empty() && !goal_found) {
    open_list.pop();
    node_map[cur_pose].is_closed = true;
    for (int i = 0; i < num_of_dir_; i++) {
      int x_new = cur_pose.first + dx_[i];
      int y_new = cur_pose.second + dy_[i];
      Pose new_pose = std::make_pair(x_new, y_new);
      if (isValidPose(new_pose) && !node_map[new_pose].is_closed) {
        int new_xy_g_cost = node_map[cur_pose].g_cost + GetCoordValue(new_pose);
        if (new_xy_g_cost < node_map[new_pose].g_cost) {
          node_map[new_pose].pred = cur_pose;
          node_map[new_pose].g_cost = new_xy_g_cost;
          if (node_map[new_pose].h_cost == 0)
            node_map[new_pose].h_cost = diagonal_distance(new_pose, dst);
          open_list.push(new_pose);
        }  // Found better pred
      }    // validity of pose
    }      // direction
    cur_pose = open_list.top();
    if (cur_pose == dst) goal_found = true;
  }  // open_list.empty()
  if (open_list.empty() && !goal_found) {
    std::cout << "Cannot find target!\n";
    return std::deque<Pose>{};
  }
  if (goal_found) {
    std::cout << "Found target!\n";
    return Backtrack(src, dst, node_map);
  }
  return std::deque<Pose>{};
}

std::deque<Pose> GeneralPlanner::DjikstraSearch(Pose src, Pose dst) {
  // Implement Djikstra and return the shortest path from src -> dst
  // 1.Initialize open list as prio queue using g_cost(ensure correctness of
  // shortest path)
  //   then add start point to open_list and set cost as 0 while setting all
  //   other points with value of INT_MAX
  // 2.Repeat until open_list empty:
  //    a.Explore top of open_list and put in closed list
  //    b.Check all successor that is valid point and not closed
  //    c.If found shorter path/cost update with new cost and pred(relaxation)
  //    d.If expanding current goal node break
  std::unordered_map<Pose, NodeInfo, HashPair> node_map;
  auto cmp = [&](Pose left, Pose right) {
    return node_map[left].g_cost > node_map[right].g_cost;
  };
  std::priority_queue<Pose, std::vector<Pose>, decltype(cmp)> open_list(cmp);
  open_list.push(src);
  Pose cur_pose = src;
  bool goal_found = false;
  node_map[cur_pose].g_cost = 0;
  while (!open_list.empty() && !goal_found) {
    open_list.pop();
    node_map[cur_pose].is_closed = true;
    for (int i = 0; i < num_of_dir_; i++) {
      int x_new = cur_pose.first + dx_[i];
      int y_new = cur_pose.second + dy_[i];
      Pose new_pose = std::make_pair(x_new, y_new);
      if (isValidPose(new_pose) && !node_map[new_pose].is_closed) {
        int new_xy_g_cost = node_map[cur_pose].g_cost + GetCoordValue(new_pose);
        if (new_xy_g_cost < node_map[new_pose].g_cost) {
          node_map[new_pose].pred = cur_pose;
          node_map[new_pose].g_cost = new_xy_g_cost;
          open_list.push(new_pose);
        }  // Found better pred
      }    // validity of pose
    }      // direction
    cur_pose = open_list.top();
    if (cur_pose == dst) goal_found = true;
  }  // open_list.empty()
  if (open_list.empty() && !goal_found) {
    std::cout << "Cannot find target!\n";
    return std::deque<Pose>{};
  }
  if (goal_found) {
    std::cout << "Found target!\n";
    return Backtrack(src, dst, node_map);
  }
  return std::deque<Pose>{};
}
std::deque<Pose> GeneralPlanner::BellmanFordSearch(Pose src, Pose dst) {
  // Implement Bellman-ford and return the shortest path from src -> dst
  // 3 Steps:
  // 1.Initialize start vertex at 0 and everything else at infinite
  // 2.Loop through pass kNumOfVertexBound times (guaranteed convergence then)
  // 3.Loop through all edges and relax(update if found pred with better cost)
  std::unordered_map<Pose, NodeInfo, HashPair> node_map;
  const int kNumOfVertexBound = num_row_ * num_col_;
  node_map[src].g_cost = 0;
  for (int v_iter = 0; v_iter < kNumOfVertexBound; v_iter++) {
    for (int it = 0; it < kNumOfVertexBound; it++) {
      Pose cur_pose = GetCoord(it);
      if (*(map_ + it) == 0 || node_map[cur_pose].g_cost == INT_MAX) continue;
      for (int i = 0; i < num_of_dir_; i++) {
        int x_new = cur_pose.first + dx_[i];
        int y_new = cur_pose.second + dy_[i];
        Pose new_pose = std::make_pair(x_new, y_new);
        if (!isValidPose(new_pose) || node_map[new_pose].pred == cur_pose)
          continue;
        int new_xy_g_cost = node_map[cur_pose].g_cost + GetCoordValue(new_pose);
        if (new_xy_g_cost < node_map[new_pose].g_cost) {
          node_map[new_pose].pred = cur_pose;
          node_map[new_pose].g_cost = new_xy_g_cost;
        }  // Found better pred and relax
      }    // Relaxing all edge connected to current pose
    }      // Relaxation all the edges in the graph
  }        // Loop through V-1 times
  return Backtrack(src, dst, node_map);
}