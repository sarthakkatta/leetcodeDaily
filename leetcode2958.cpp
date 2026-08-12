/*
Problem: LeetCode 2958 – Length of Longest Subarray With
Each Element Appearing at Most K Times

Approach:
1. Use a sliding window with two pointers:
   - left → start of the current window
   - right → end of the current window
2. Maintain a frequency map `mpp` to store the
   frequency of every number inside the window.
3. Expand the window by moving `right`.
4. Increment the frequency of nums[right].
5. If the frequency of nums[right] becomes greater
   than k:
   - The current window is invalid.
   - Move `left` forward.
   - Decrease the frequency of nums[left].
6. Continue shrinking until the frequency becomes
   at most k.
7. At every valid window, calculate its length:
      right - left + 1
8. Keep the maximum length in `ans`.

Key Idea:
- The window always contains elements whose frequency
  is at most k.
- Whenever a number exceeds k occurrences, move the
  left pointer until the window becomes valid again.

Example:
nums = [1,2,1,2,1,2]
k = 2

A valid longest window can be:
[1,2,1,2]

Length = 4

Answer:
4

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {

        unordered_map<int,int> mpp;

        int left = 0;
        int ans = 0;

        for(int right = 0; right < nums.size(); right++) {

            // Add current element to the window
            mpp[nums[right]]++;

            // Shrink the window if the current
            // element appears more than k times
            while(mpp[nums[right]] > k) {
                mpp[nums[left]]--;
                left++;
            }

            // Update maximum window length
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
