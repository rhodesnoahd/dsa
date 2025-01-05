// https://leetcode.com/problems/valid-sudoku/description/

public class Solution
{
    public bool IsValidSudoku(char[][] board)
    {
        Dictionary<int, HashSet<char>> row = new Dictionary<int, HashSet<char>>();
        Dictionary<int, HashSet<char>> col = new Dictionary<int, HashSet<char>>();
        Dictionary<string, HashSet<char>> box = new Dictionary<string, HashSet<char>>();

        for (int i = 0; i < board.Length; i++)
        {
            for (int j = 0; j < board[i].Length; j++)
            {
                char v = board[i][j];

                if (v == '.')
                    continue;

                string boxKey = $"{i / 3}{j / 3}";

                if (
                    (row.ContainsKey(i) && row[i].Contains(v))
                    || (col.ContainsKey(j) && col[j].Contains(v))
                    || (box.ContainsKey(boxKey) && box[boxKey].Contains(v))
                )
                {
                    return false;
                }

                if (!row.ContainsKey(i))
                    row[i] = new HashSet<char>();
                if (!col.ContainsKey(j))
                    col[j] = new HashSet<char>();
                if (!box.ContainsKey(boxKey))
                    box[boxKey] = new HashSet<char>();

                row[(char)i].Add(v);
                col[(char)j].Add(v);
                box[boxKey].Add(v);
            }
        }

        return true;
    }
}
