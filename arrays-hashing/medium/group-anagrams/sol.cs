// https://leetcode.com/problems/group-anagrams/

public class Solution
{
    public IList<IList<string>> GroupAnagrams(string[] strs)
    {
        var a = new Dictionary<string, List<string>>();

        foreach (string s in strs)
        {
            int[] freq = new int[26];
            foreach (char c in s)
            {
                freq[c - 'a']++;
            }
            string key = string.Join(',', freq);
            if (!a.ContainsKey(key))
            {
                a[key] = new List<string>();
            }
            a[key].Add(s);
        }

        return a.Values.ToList<IList<string>>();
    }
}
