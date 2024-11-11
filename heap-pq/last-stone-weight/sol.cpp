// https://leetcode.com/problems/last-stone-weight/

#include <vector>
#include <queue>

using std::vector;

class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        std::priority_queue<int, vector<int>> maxHeap;
        for (int s : stones)
        {
            maxHeap.push(s);
        }
        while (maxHeap.size() > 1)
        {
            int first = maxHeap.top();
            maxHeap.pop();
            int second = maxHeap.top();
            maxHeap.pop();
            if (second < first)
            {
                maxHeap.push(first - second);
            }
        }
        maxHeap.push(0);
        return maxHeap.top();
    }
};