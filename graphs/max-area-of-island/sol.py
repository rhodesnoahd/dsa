from typing import List


class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        ans = 0
        visited = set()
        m, n = len(grid), len(grid[0])

        def dfs(i, j):
            if (
                i not in range(m)
                or j not in range(n)
                or grid[i][j] == 0
                or (i, j) in visited
            ):
                return 0
            else:
                visited.add((i, j))
                return 1 + dfs(i, j + 1) + dfs(i + 1, j) + dfs(i, j - 1) + dfs(i - 1, j)

        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1 and (i, j) not in visited:
                    ans = max(ans, dfs(i, j))

        return ans
