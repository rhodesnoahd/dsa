// https://leetcode.com/problems/valid-sudoku/description/

/**
 * @param {character[][]} board
 * @return {boolean}
 */
var isValidSudoku = function (board) {
  const row = {};
  col = {};
  box = {};

  for (let i = 0; i < board.length; i++) {
    for (let j = 0; j < board[i].length; j++) {
      const v = board[i][j];

      if (v === ".") continue;

      const boxKey = `${Math.floor(i / 3)}${Math.floor(j / 3)}`;

      row[i] = row[i] ?? new Set();
      col[j] = col[j] ?? new Set();
      box[boxKey] = box[boxKey] ?? new Set();

      if (row[i].has(v) || col[j].has(v) || box[boxKey].has(v)) {
        return false;
      }

      row[i].add(v);
      col[j].add(v);
      box[boxKey].add(v);
    }
  }

  return true;
};
