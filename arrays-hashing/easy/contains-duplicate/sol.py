# https://leetcode.com/problems/contains-duplicate/description/

from typing import List


class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        return len(set(nums)) < len(nums)