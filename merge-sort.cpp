#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int sz = nums.size();
        mergeSort(nums, 0, sz - 1);
        return nums;
    }
private:
    void mergeSort(vector<int>& nums, int start, int end)
    {
        int sz = end - start + 1;
        if (sz <= 1)
        {
            return;
        }
        int mid = (start + end) >> 1;
        mergeSort(nums, start, mid);
        mergeSort(nums, mid + 1, end);
        merge(nums, start, mid, end);
    }
    void merge(vector<int>& nums, int start, int mid, int end)
    {
        int sz = end - start + 1;
        int a = start;
        int b = mid + 1;
        vector<int> tmp(sz);
        for (int i = 0; i < sz; ++i)
        {
            if (a > mid)
            {
                tmp[i] = nums[b];
                ++b;
            }
            else if (b > end)
            {
                tmp[i] = nums[a];
                ++a;
            }
            else if (nums[a] <= nums[b])
            {
                tmp[i] = nums[a];
                ++a;
            }
            else
            {
                tmp[i] = nums[b];
                ++b;
            }
        }
        for (int i = 0; i < sz; ++i)
        {
            nums[i + start] = tmp[i];
        }
    }
};

int main(void) {
    Solution solution;
    vector<int> A;

    A = {3, 2, 1, 4, 5};
    solution.sortArray(A);
    for (const auto & i : A) {
        cout << i << '\t';
    }
    cout << '\n';

    return 0;
}