/*
Problem: LeetCode 33 – Search in Rotated Sorted Array

Approach:
1. Use Binary Search on rotated sorted array.
2. At every step:
   - Compute mid index.
   - If arr[mid] == target → return mid.
3. Determine which half is sorted:
   - If arr[low] <= arr[mid]:
       → Left half is sorted
   - Else:
       → Right half is sorted
4. Check if target lies within sorted half:
   - If yes → search there
   - Else → search opposite half
5. If target not found → return -1.

Key Idea:
- In rotated sorted array, at least one half is always sorted.

Time Complexity: O(log N)
Space Complexity: O(1)
*/

class Solution {
public:
    int search(vector<int>& arr, int k) {
        int n = arr.size();
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] == k) return mid;
            // Left part is sorted
            if (arr[low] <= arr[mid]) {
                if (arr[low] <= k && k < arr[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            // Right part is sorted
            else {
                if (arr[mid] < k && k <= arr[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};
