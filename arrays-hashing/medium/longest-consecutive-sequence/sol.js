// https://leetcode.com/problems/longest-consecutive-sequence/description/

/**
 * @param {number[]} nums
 * @return {number}
 */
var longestConsecutive = function (nums) {
  const mySet = new Set(nums);
  let ans = 0;

  for (const n of mySet) {
    // check start of sequence
    if (!mySet.has(n - 1)) {
      let length = 1;

      while (mySet.has(n + length)) {
        length += 1;
      }

      ans = Math.max(ans, length);
    }
  }

  return ans;
};
