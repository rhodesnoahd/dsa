# https://leetcode.com/problems/number-of-islands/

from typing import List


class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        ans = 0
        visited = set()
        m, n = len(grid), len(grid[0])

        def dfs(i, j):
            if (
                i not in range(m)
                or j not in range(n)
                or grid[i][j] == "0"
                or (i, j) in visited
            ):
                return
            else:
                visited.add((i, j))
                dfs(i, j + 1)
                dfs(i + 1, j)
                dfs(i, j - 1)
                dfs(i - 1, j)

        for i in range(m):
            for j in range(n):
                if grid[i][j] == "1" and (i, j) not in visited:
                    ans += 1
                    dfs(i, j)

        return ans
