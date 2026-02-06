/*
Problem: Minimum Removals to Make Array K-Special

Approach:
1. Sort the array.
2. Use two pointers to maintain a valid window.
3. For each right pointer j, move left pointer i until nums[j] <= nums[i] * k.
4. Current window size = j - i + 1 (elements we can keep).
5. Removals = total elements - window size.
6. Track minimum removals over all windows.

Time Complexity: O(N log N)
Space Complexity: O(1)
*/

class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int i = 0; 
        int count = n; 

        for(int j = 0; j < n; j++){
            while ((long long)nums[j] > (long long)nums[i] * k) {
                i++;
            }

            int keep = j - i + 1;
            count = min(count, n - keep);
        }

        return count;
    }
};
