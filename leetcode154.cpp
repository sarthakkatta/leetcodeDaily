/*
Problem: LeetCode 154 – Find Minimum in Rotated Sorted Array II

Approach:
1. Use Binary Search to find minimum element.
2. Maintain:
   - low → start index
   - high → end index
3. If current segment is already sorted:
   - nums[low] is the minimum.
4. Handle duplicates:
   - If nums[low] == nums[mid] == nums[high]:
       → shrink search space from both ends.
5. If left half is sorted:
   - Minimum may exist in right half.
6. Else:
   - Minimum lies in left half including mid.
7. Keep updating answer with smallest value found.

Key Idea:
- Rotation breaks sorted order at pivot point.
- Binary search helps locate minimum efficiently even with duplicates.

Time Complexity:
- Average: O(log N)
- Worst Case: O(N) (due to duplicates)

Space Complexity: O(1)
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        int ans = INT_MAX;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // If current segment is sorted
            if (nums[low] < nums[high]) {
                ans = min(ans, nums[low]);
                break;
            }
            // When duplicates are present
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                ans = min(ans, nums[low]);
                low++;
                high--;
            }
            else if (nums[low] <= nums[mid]) { 
                // Left half is sorted
                ans = min(ans, nums[low]);
                low = mid + 1;
            }
            else { 
                // Right half is sorted
                ans = min(ans, nums[mid]);
                high = mid - 1;
            }
        }
        return ans;
    }
};
