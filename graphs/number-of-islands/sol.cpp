// https://leetcode.com/problems/number-of-islands/

#include <vector>

using std::vector;

class Solution
{
public:
  int numIslands(vector<vector<char>> &grid)
  {
    int ans = 0;
    int m = grid.size();
    int n = grid.at(0).size();

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (grid.at(i).at(j) == '1')
        {
          dfs(grid, i, j, m, n);
          ans++;
        }
      }
    }

    return ans;
  }

private:
  void dfs(vector<vector<char>> &grid, int i, int j, int m, int n)
  {
    if (i < 0 || i >= m || j < 0 || j >= n || grid.at(i).at(j) == '0')
    {
      return;
    }
    else
    {
      grid.at(i).at(j) = '0'; // mark visited
      dfs(grid, i, j + 1, m, n);
      dfs(grid, i + 1, j, m, n);
      dfs(grid, i, j - 1, m, n);
      dfs(grid, i - 1, j, m, n);
    }
  }
};