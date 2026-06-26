/*
Problem: 3739. Count Subarrays With Majority Element II

Approach:
1. Transform the array:
   - target      → +1
   - non-target  → -1
2. Maintain:
   - currsum → running transformed prefix sum.
   - mp      → frequency of prefix sums.
3. Observation:
   - A subarray has target as majority if its
     transformed sum is positive.
4. Track:
   - validleftpoint → number of valid starting
     positions for current ending index.
5. For each element:
   a) If nums[j] == target:
      - Existing prefix sums equal to currsum
        become valid.
      - Add mp[currsum] to validleftpoint.
      - Increase currsum.
   b) Otherwise:
      - Decrease currsum.
      - Remove invalid contributions:
        validleftpoint -= mp[currsum].
6. Update frequency of current prefix sum.
7. Add validleftpoint to answer.
8. Return total count.

Key Idea:
- Convert majority condition into
  positive subarray sum condition.
- Use prefix sums + hashmap to count
  valid subarrays efficiently.

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        unordered_map<int, int> mp;

        int n = nums.size();

        mp[0] = 1;

        int currsum = 0;
        long long validleftpoint = 0;
        long long res = 0;

        for(int j = 0; j < n; j++) {

            if(nums[j] == target) {
                validleftpoint += mp[currsum];
                currsum += 1;
            }
            else {
                currsum -= 1;
                validleftpoint -= mp[currsum];
            }

            mp[currsum] += 1;

            res += validleftpoint;
        }

        return res;
    }
};
