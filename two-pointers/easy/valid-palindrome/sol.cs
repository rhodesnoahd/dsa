// https://leetcode.com/problems/valid-palindrome/

public class Solution
{
  public bool IsPalindrome(string s)
  {
    int l = 0, r = s.Length - 1;

    while (l < r)
    {
      while (l < r && !an(s[l]))
      {
        l++;
      }
      while (r > l && !an(s[r]))
      {
        r--;
      }
      if (Char.ToLower(s[l]) != Char.ToLower(s[r]))
      {
        return false;
      }
      l++; r--;
    }

    return true;

    static bool an(char c)
    {
      return (
          ('a' <= c && c <= 'z')
          || ('A' <= c && c <= 'Z')
          || ('0' <= c && c <= '9')
      );
    }
  }
}