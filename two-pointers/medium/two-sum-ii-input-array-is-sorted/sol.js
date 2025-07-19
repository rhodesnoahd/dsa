// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/

/**
 * @param {number[]} numbers
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function (numbers, target) {
  let l = 0,
    r = numbers.length - 1;

  while (l < r) {
    if (numbers[l] + numbers[r] < target) {
      l++;
    } else if (numbers[l] + numbers[r] > target) {
      r--;
    } else {
      return [l + 1, r + 1];
    }
  }
};
