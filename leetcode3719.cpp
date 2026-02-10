/*
Problem: Longest Balanced Subarray

Approach:
1. Fix a starting index i and expand subarray to the right.
2. Maintain two sets to track distinct odd and even numbers.
3. For each extension, insert current number into odd/even set.
4. If count of distinct odd numbers equals distinct even numbers,
   update the maximum length.
5. Check all possible subarrays using two nested loops.

Time Complexity: O(N²)
Space Complexity: O(N)
*/

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        for(int i = 0; i < n; i++){
            unordered_set<int> odd, even;
            for(int j = i; j < n; j++){
                if(nums[j] & 1){
                    odd.insert(nums[j]);
                } else {
                    even.insert(nums[j]);
                }
                if(odd.size() == even.size())
                    maxi = max(maxi, j - i + 1);
            }
        }
        return maxi;
    }
};
