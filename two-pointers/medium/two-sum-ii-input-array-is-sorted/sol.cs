// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/

public class Solution
{
  public int[] TwoSum(int[] numbers, int target)
  {
    int l = 0, r = numbers.Length - 1;

    while (l < r)
    {
      if (numbers[l] + numbers[r] < target)
      {
        l++;
      }
      else if (numbers[l] + numbers[r] > target)
      {
        r--;
      }
      else
      {
        break;
      }
    }

    return [l + 1, r + 1];
  }
}