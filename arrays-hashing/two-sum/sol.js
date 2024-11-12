// https://leetcode.com/problems/two-sum/description/

/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function (nums, target) {
  const seen = {};

  for (let i = 0; i < nums.length; i++) {
    const c = target - nums[i];

    if (c in seen) {
      return [seen[c], i];
    }
    seen[nums[i]] = i;
  }
};
