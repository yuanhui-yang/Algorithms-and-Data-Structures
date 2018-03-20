#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void sortIntegers2(vector<int> & A) {
        heap_sort(A);
    }
private:
    void heap_sort(vector<int> & A) {
        make_maxheap(A);
        int sz = A.size();
        for (int i = sz - 1; i >= 0; --i) {
            swap(A[0], A[i]);
            max_heapify(A, 0, i);
        }
    }
    void make_maxheap(vector<int> & A) {
        int sz = A.size();
        for (int i = sz / 2 - 1; i >= 0; --i) {
            max_heapify(A, i, sz);
        }
    }
    void max_heapify(vector<int> & A, int i, int N) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int top = i;
        if (left < N and A[top] < A[left]) {
            top = left;
        }
        if (right < N and A[top] < A[right]) {
            top = right;
        }
        if (top != i) {
            swap(A[top], A[i]);
            max_heapify(A, top, N);
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