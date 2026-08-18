/*
Problem: LeetCode 3471 – Find the Largest Almost Missing Integer

Approach:
1. First count the frequency of every number using
   an unordered_map.
2. If k == n:
   - The selected subarray is the complete array.
   - Every element appears in that subarray.
   - Therefore return the maximum element.
3. If k == 1:
   - Every subarray contains only one element.
   - So an element is almost missing only when it
     appears exactly once in the complete array.
   - Find the largest element whose frequency is 1.
4. For k > 1 and k < n:
   - Only the first and last elements can appear
     in exactly one length-k subarray.
   - Check nums[0] and nums[n-1].
5. If both boundary elements are the same:
   - They cannot give a valid answer, so return -1.
6. If one or both boundary elements occur exactly once,
   choose the larger valid value.
7. If neither is unique, return -1.

Key Idea:
- For k between 2 and n-1, an element can be present
  in only one length-k subarray only when it is at
  one of the two boundaries.
- Frequency map tells us whether that boundary value
  occurs anywhere else in the array.

Example:

nums = [3, 5, 2, 3]
k = 2

First element = 3
Last element = 3

Since both are same:
3 cannot be almost missing.

Answer:
-1

Another Example:

nums = [5, 2, 3, 4]
k = 2

5 occurs only once.
4 occurs only once.

Largest valid value = 5

Answer:
5

Time Complexity: O(N)

Space Complexity: O(N)
*/

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }
        if(k == nums.size()) {
            return *max_element(nums.begin(), nums.end());
        }
        if(k == 1) {
            int maxValue = -1;

            for(int i = 0; i < n; i++) {
                if(mp[nums[i]] == 1 && nums[i] > maxValue) {
                    maxValue = nums[i];
                }
            }
            return maxValue;
        }
        n = n - 1;
        if (nums[0] == nums[n]) {
            return -1;
        }
        if (mp[nums[0]] == 1 && mp[nums[n]] == 1) {
            return max(nums[0], nums[n]);
        }
        if (mp[nums[0]] == 1 && mp[nums[n]] > 1) {
            return nums[0];
        }
        if (mp[nums[n]] == 1 && mp[nums[0]] > 1) {
            return nums[n];
        }
        return -1;
    }
};
