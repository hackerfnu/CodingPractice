#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <utility>
#include <cmath>
#include <cstdlib>
#include "planner.h"

#define ROW 9
#define COL 10
#define GETMAPINDEX(X, Y, XSIZE, YSIZE) ((Y-1)*XSIZE + (X-1))

// Driver program to test above function
int main()
{
    /* Description of the Grid-
     1--> The cell is not blocked
     0--> The cell is blocked    */
    int grid[ROW*COL]
        = { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1,
            1, 1, 1, 0, 1, 1, 1, 0, 1, 1,
            1, 1, 1, 0, 1, 1, 0, 1, 0, 1,
            0, 0, 1, 0, 1, 0, 0, 0, 0, 1,
            1, 1, 1, 0, 1, 1, 1, 0, 1, 0,
            1, 0, 1, 1, 1, 1, 0, 1, 0, 0,
            1, 0, 0, 0, 0, 1, 0, 0, 0, 1,
            1, 0, 1, 1, 1, 1, 0, 1, 1, 1,
            1, 1, 1, 0, 0, 0, 1, 0, 0, 1 };

    // Source is the left-most bottom-most corner
    std::pair<int,int> src = std::make_pair(8, 0);
    // Destination is the left-most top-most corner
    std::pair<int,int> dest = std::make_pair(0, 0);
	GeneralPlanner planner(grid,ROW,COL);
    planner.search(src, dest, "AStar");
    return (0);
}