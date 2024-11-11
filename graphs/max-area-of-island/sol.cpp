// https://leetcode.com/problems/max-area-of-island/description/

#include <vector>

using std::max;
using std::vector;

class Solution
{
public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int ans = 0;
        int m = grid.size();
        int n = grid.at(0).size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid.at(i).at(j) == 1)
                {
                    ans = max(ans, dfs(grid, i, j, m, n));
                }
            }
        }

        return ans;
    }

private:
    int dfs(vector<vector<int>> &grid, int i, int j, int m, int n)
    {
        if (i < 0 || i >= m || j < 0 || j >= n || grid.at(i).at(j) == 0)
        {
            return 0;
        }
        grid.at(i).at(j) = 0; // mark as visited
        return (1 + dfs(grid, i, j + 1, m, n) +
                dfs(grid, i + 1, j, m, n) +
                dfs(grid, i, j - 1, m, n) +
                dfs(grid, i - 1, j, m, n));
    }
};