// https://leetcode.com/problems/top-k-frequent-elements/

public class Solution
{
    public int[] TopKFrequent(int[] nums, int k)
    {
        var count = new Dictionary<int, int>();
        foreach (int n in nums)
        {
            if (count.ContainsKey(n))
            {
                count[n]++;
            }
            else
            {
                count.Add(n, 1);
            }
        }

        List<int>[] freq = new List<int>[nums.Length + 1];
        for (int i = 0; i < freq.Length; i++)
        {
            freq[i] = new List<int>();
        }
        foreach (var item in count)
        {
            freq[item.Value].Add(item.Key);
        }

        int[] ans = new int[k];
        int idx = 0;
        for (int i = freq.Length - 1; i > 0 && idx < k; i--)
        {
            foreach (int n in freq[i])
            {
                ans[idx++] = n;
                if (idx == k)
                {
                    return ans;
                }
            }
        }
        return ans;
    }
}
