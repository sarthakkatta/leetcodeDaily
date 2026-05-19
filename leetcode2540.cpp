/*
Problem: LeetCode 2540 – Minimum Common Value

Approach:
1. Use two pointers:
   - i for nums1
   - j for nums2
2. Traverse both sorted arrays:
   - If nums1[i] == nums2[j]:
       → common value found → return it.
   - If nums1[i] < nums2[j]:
       → move i forward.
   - Else:
       → move j forward.
3. If no common element exists → return -1.

Key Idea:
- Since arrays are sorted, two-pointer technique efficiently finds smallest common value.

Time Complexity: O(N + M)
Space Complexity: O(1)
*/

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i =0, j = 0;
        
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i] == nums2[j]){
                return nums1[i];
            }

            if(nums1[i] < nums2[j]){
                i++;
            }else{
                j++;
            }
        }
        return -1;
    }
};
