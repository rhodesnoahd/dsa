// https://leetcode.com/problems/contains-duplicate/description/

class Solution {
  /**
   * @param {number[]} nums
   * @return {boolean}
   */
  hasDuplicate(nums) {
    return new Set(nums).size < nums.length;
  }
}
