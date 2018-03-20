#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortIntegers2(vector<int> & A) {
        merge_sort(A);
    }
private:
    void merge_sort(vector<int> & A) {
        partial_sort(A, 0, A.size());
    }
    void partial_sort(vector<int> & A, int begin, int end) {
        if (end - begin <= 1) {
            return;
        }
        int mid = begin + (end - begin) / 2;
        partial_sort(A, begin, mid);
        partial_sort(A, mid, end);
        merge(A, begin, mid, end);

    }
    void merge(vector<int> & A, int begin, int mid, int end) {
        vector<int> B;
        int i = begin, j = mid;
        while (i < mid or j < end) {
            if (i >= mid) {
                B.push_back(A[j]);
                ++j;
            }
            else if (j >= end) {
                B.push_back(A[i]);
                ++i;
            }
            else if (A[i] < A[j]) {
                B.push_back(A[i]);
                ++i;
            }
            else {
                B.push_back(A[j]);
                ++j;
            }
        }
        i = begin, j = 0;
        while (i < end) {
            A[i] = B[j];
            ++i;
            ++j;
        }
    }
};

int main(void) {
    Solution solution;
    vector<int> A;

    A = {3, 2, 1, 4, 5};
    solution.sortIntegers2(A);
    for (const auto & i : A) {
        cout << i << '\t';
    }
    cout << '\n';

    return 0;
}