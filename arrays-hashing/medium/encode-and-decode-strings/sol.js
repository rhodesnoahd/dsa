// https://leetcode.com/problems/encode-and-decode-strings/description/

class Solution {
  /**
   * @param {string[]} strs
   * @returns {string}
   */
  encode(strs) {
    let res = "";
    for (const s of strs) {
      res += String(s.length) + "#" + s;
    }
    return res;
  }

  /**
   * @param {string} str
   * @returns {string[]}
   */
  decode(str) {
    let res = [];
    let i = 0;

    while (str[i] < str.length) {
      let j = i;
      while (str[j] !== "#") {
        j++;
      }
      const length = parseInt(str.substring(i, j));
      i = j + 1;
      j = i + length;
      res.push(str.substring(i, j));
      i = j;
    }

    return res;
  }
}
