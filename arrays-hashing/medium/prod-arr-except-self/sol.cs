// # https://leetcode.com/problems/product-of-array-except-self/

public class Solution
{
    public int[] ProductExceptSelf(int[] nums)
    {
        int n = nums.Length;
        int[] ans = new int[n];
        Array.Fill(ans, 1);

        int t = 1;
        for (int i = 0; i < n; i++)
        {
            ans[i] = t;
            t *= nums[i];
        }

        t = 1;
        for (int i = n - 1; i > -1; i--)
        {
            ans[i] *= t;
            t *= nums[i];
        }

        return ans;
    }
}
