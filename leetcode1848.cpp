/*
Problem: LeetCode 1848 – Minimum Distance to the Target Element

Approach:
1. Traverse the array.
2. For every index i where nums[i] == target:
   - Compute distance = |i - start|.
3. Track the minimum distance among all such occurrences.
4. Return the minimum distance.

Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int ans = 0;
        int mindist = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == target){
                ans = abs(i - start);
                mindist = min(mindist, ans);
            }
        }
        return mindist;
    }
};
