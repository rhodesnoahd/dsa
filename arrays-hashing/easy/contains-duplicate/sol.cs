// https://leetcode.com/problems/contains-duplicate/description/

public class Solution {
  public bool hasDuplicate(int[] nums) {
    return new HashSet<int>(nums).Count < nums.Length;
  }
}