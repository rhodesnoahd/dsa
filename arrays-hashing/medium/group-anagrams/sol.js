// https://leetcode.com/problems/group-anagrams/

/**
 * @param {string[]} strs
 * @return {string[][]}
 */
var groupAnagrams = function (strs) {
  a = {};

  for (let s of strs) {
    freq = new Array(26).fill(0);
    for (let c of s) {
      freq[c.charCodeAt(0) - "a".charCodeAt(0)] += 1;
    }
    const key = freq.join(",");
    a[key] = a[key] ?? [];
    a[key].push(s);
  }

  return Object.values(a);
};
