# https://leetcode.com/problems/valid-sudoku/description/

from typing import List
from collections import defaultdict


class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        row = defaultdict(set)
        col = defaultdict(set)
        box = defaultdict(set)

        for i in range(len(board)):
            for j in range(len(board[i])):
                v = board[i][j]

                if v == ".":
                    continue

                if v in row[i] or v in col[j] or v in box[(i // 3, j // 3)]:
                    return False

                row[i].add(v)
                col[j].add(v)
                box[(i // 3, j // 3)].add(v)

        return True
