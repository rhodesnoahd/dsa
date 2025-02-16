// https://leetcode.com/problems/longest-consecutive-sequence/description/

public class Solution
{
    public int LongestConsecutive(int[] nums)
    {
        HashSet<int> mySet = new HashSet<int>(nums);
        int ans = 0;

        foreach (int n in mySet)
        {
            // check start of sequence
            if (!mySet.Contains(n - 1))
            {
                int length = 1;

                while (mySet.Contains(n + length))
                {
                    length += 1;
                }

                ans = Math.Max(ans, length);
            }
        }

        return ans;
    }
}
