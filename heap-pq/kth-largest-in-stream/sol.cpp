// https://leetcode.com/problems/kth-largest-element-in-a-stream/

#include <vector>
#include <queue>

using std::vector;

class KthLargest
{
public:
  KthLargest(int k, vector<int> &nums)
  {
    this->k = k;
    for (int n : nums)
    {
      minHeap.push(n);
      if (minHeap.size() > k)
        minHeap.pop();
    }
  }

  int add(int val)
  {
    minHeap.push(val);
    if (minHeap.size() > k)
      minHeap.pop();
    return minHeap.top();
  }

private:
  std::priority_queue<int, vector<int>, std::greater<int>> minHeap;
  int k;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */