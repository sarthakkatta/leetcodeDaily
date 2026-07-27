/*
Problem: LeetCode 1464 – Maximum Product of Two Elements in an Array

Approach:
1. Traverse the array only once.
2. Maintain:
   - max  → Largest element found so far.
   - smax → Second largest element found so far.
3. For each element:
   a) If it is greater than or equal to max:
      - Update second largest with the old max.
      - Update max.
   b) Otherwise, if it is greater than smax:
      - Update smax.
4. After finding the two largest numbers,
   calculate:
      (max - 1) × (smax - 1)
5. Return the calculated product.

Key Idea:
- The maximum product always comes from the
  two largest elements in the array.
- Instead of checking every pair (O(N²)),
  keep track of only the largest and second
  largest elements while traversing once.

Example:
Input:
[3,4,5,2]

Largest = 5
Second Largest = 4

Answer:
(5 - 1) × (4 - 1)
= 4 × 3
= 12

Time Complexity: O(N)
Space Complexity: O(1)
*/

// Brute Force Approach
// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//         int n = nums.size();
//         int maxi = 0;
//
//         for(int i = 0; i < n; i++) {
//             for(int j = i + 1; j < n; j++) {
//                 maxi = max((nums[i] - 1) * (nums[j] - 1), maxi);
//             }
//         }
//
//         return maxi;
//     }
// };


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int max = -1;
        int smax = -1;

        for(int i = 0; i < n; i++) {

            if(nums[i] >= max) {
                smax = max;
                max = nums[i];
            }
            else if(nums[i] > smax && nums[i] < max) {
                smax = nums[i];
            }
        }

        int mul = (max - 1) * (smax - 1);

        return mul;
    }
};
