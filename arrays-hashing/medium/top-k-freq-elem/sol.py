# https://leetcode.com/problems/top-k-frequent-elements/

from typing import List


class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count = {}
        for n in nums:
            count[n] = 1 + count.get(n, 0)

        freq = [[] for i in range(len(nums) + 1)]
        for n, c in count.items():
            freq[c].append(n)

        ans = []
        for i in range(len(freq) - 1, 0, -1):
            for n in freq[i]:
                ans.append(n)
                if len(ans) == k:
                    return ans
