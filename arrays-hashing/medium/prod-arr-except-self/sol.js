// # https://leetcode.com/problems/product-of-array-except-self/

/**
 * @param {number[]} nums
 * @return {number[]}
 */
var productExceptSelf = function (nums) {
  const n = nums.length;
  const ans = new Array(n).fill(1);

  let t = 1;
  for (let i = 0; i < n; i++) {
    ans[i] = t;
    t *= nums[i];
  }

  t = 1;
  for (let i = n - 1; i > -1; i--) {
    ans[i] *= t;
    t *= nums[i];
  }

  return ans;
};
