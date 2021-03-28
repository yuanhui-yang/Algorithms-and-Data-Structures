#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums)
    {
        int sz = nums.size();
        quick_sort(nums, 0, sz - 1);
        return nums;
    }
private:
    void quick_sort(vector<int> & nums, int start, int end)
    {
        if (start < end)
        {
            int mid = quick_select(nums, start, end);
            quick_sort(nums, start, mid - 1);
            quick_sort(nums, mid + 1, end);
        }
    }
    int quick_select(vector<int> & nums, int start, int end)
    {
        int pivot = nums[end];
        int i = start;
        for (int j = start; j < end; ++j)
        {
            int val = nums[j];
            if (val < pivot)
            {
                swap(nums[j], nums[i]);
                ++i;
            }
        }
        swap(nums[i], nums[end]);
        return i;
    }
};

int main(void) {
    Solution solution;
    vector<int> nums;

    nums = {3, 2, 1, 4, 5};
    solution.sortArray(nums);
    for (const auto & i : nums) {
        cout << i << '\t';
    }
    cout << '\n';

    return 0;
}