# https://leetcode.com/problems/longest-consecutive-sequence/description/

from typing import List


class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        mySet = set(nums)
        ans = 0

        for n in mySet:
            # check start of sequence
            if (n - 1) not in mySet:
                length = 1

                while (n + length) in mySet:
                    length += 1

                ans = max(ans, length)

        return ans
