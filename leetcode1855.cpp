/*
Problem: LeetCode 1855 – Maximum Distance Between a Pair of Values

Approach:
1. Use two pointers:
   - i → index for nums1
   - j → index for nums2
2. Traverse while both pointers are in bounds:
   - If nums1[i] <= nums2[j]:
       → valid pair → update ans = max(ans, j - i)
       → move j forward to maximize distance
   - Else:
       → move i forward (to find smaller value)
       → ensure j >= i (reset j if needed)
3. Return maximum distance found.

Key Idea:
- Since arrays are non-increasing, two-pointer approach works efficiently.

Time Complexity: O(N + M)
Space Complexity: O(1)
*/

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        int ans = 0;
        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] <= nums2[j]){
                ans = max(ans, j - i);
                j++;
            }else{
                i++;
                if(i > j) j = i;
            }
        }
        return ans;

    }
};
