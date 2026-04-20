/*
Problem: LeetCode 2078 – Two Furthest Houses With Different Colors

Approach:
1. Goal: Find maximum distance |i - j| such that colors[i] != colors[j].
2. Optimized idea:
   - Compare from left with last element:
       → Find first index where A[i] != A[n-1]
   - Compare from right with first element:
       → Find last index where A[i] != A[0]
3. Compute two possible distances:
   - n - 1 - left
   - right
4. Return maximum of both.

Key Idea:
- Only need to compare with boundary elements for max distance.

Time Complexity: O(N)
Space Complexity: O(1)
*/

// class Solution {
// public:
//     int maxDistance(vector<int>& colors) {
//         int n = colors.size();
//         int ans = INT_MIN;
//         for(int i = 0; i < n; i++){
//             for(int j = 0; j < n; j++){
//                 if(colors[i]!=colors[j]){
//                     ans = max(ans,abs(i - j));
//                 }
//             }
//         }
//         return ans;
//     }
// };


class Solution {
public:
    int maxDistance(vector<int>& A) {
        int n = A.size();
        int left = 0, right = 0;
        for (int i = 0; i < n; i++)
            if (A[i] != A[n - 1]) {
                left = i;
                break;
            }

        for (int i = n - 1; i >= 0; i--)
            if (A[i] != A[0]) {
                right = i;
                break;
            }
        return max(n - 1 - left, right);
    }
};
