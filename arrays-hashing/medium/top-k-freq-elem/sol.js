// https://leetcode.com/problems/top-k-frequent-elements/

/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
var topKFrequent = function (nums, k) {
  count = {};
  for (const n of nums) {
    count[n] = (count[n] || 0) + 1;
  }

  freq = Array.from({ length: nums.length + 1 }, () => []);
  for (const [n, c] of Object.entries(count)) {
    freq[c].push(parseInt(n));
  }

  ans = [];
  for (let i = freq.length - 1; i > 0; i--) {
    for (const n of freq[i]) {
      ans.push(n);
      if (ans.length == k) {
        return ans;
      }
    }
  }
};
