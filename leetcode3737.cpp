/*
Problem: Count Subarrays With Majority Element I

Approach:
1. Convert the array into:
   - +1 if nums[i] == target
   - -1 otherwise
2. Build a prefix sum array:
   - pref[i+1] = pref[i] + transformed value
3. For every subarray [l, r]:
   - Compute transformed sum:
       pref[r+1] - pref[l]
4. Observation:
   - Sum > 0
       ⇒ target appears more times than all
          other elements combined.
       ⇒ target is the majority element.
5. Count all subarrays whose transformed sum
   is positive.
6. Return the count.

Key Idea:
- Replace target with +1 and others with -1.
- A positive subarray sum directly implies
  target frequency > subarray length / 2.

Time Complexity: O(N²)
Space Complexity: O(N)
*/

// class Solution {
// public:
//     int countMajoritySubarrays(vector<int>& nums, int target) {
//         int n = nums.size();
//         int ans = 0;
//         for(int l = 0; l < n; l++){
//             int targetcount = 0;
//             for(int r = l; r < n; r++){
//                 if(nums[r] == target){
//                     targetcount++;
//                 }
//                 int len = r - l + 1;
//                 if(targetcount > len/2){
//                     ans++;
//                 }
//             } 
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + (nums[i] == target ? 1 : -1);
        }
        int ans = 0;
        for (int l = 0; l < n; l++) {
            for (int r = l; r < n; r++) {
                if (prefix[r + 1] - prefix[l] > 0) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
