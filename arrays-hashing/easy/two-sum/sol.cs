// https://leetcode.com/problems/two-sum/description/

public class Solution
{
    public int[] TwoSum(int[] nums, int target)
    {
        Dictionary<int, int> seen = new Dictionary<int, int>();

        for (int i = 0; i < nums.Length; i++)
        {
            int c = target - nums[i];
            if (seen.ContainsKey(c))
            {
                return new int[] { seen[c], i };
            }
            seen[nums[i]] = i;
        }
        return null;
    }
}
