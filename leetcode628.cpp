/*
Problem: LeetCode 628 – Maximum Product of Three Numbers

Approach:
1. Maintain:
   - Three largest numbers:
       max1, max2, max3
   - Two smallest numbers:
       min1, min2
2. Traverse the array once.
3. For every number:
   a) Update the three largest values.
   b) Update the two smallest values.
4. After traversal, two possible maximum products exist:
   a) Product of the three largest numbers:
      max1 × max2 × max3
   b) Product of the two smallest numbers
      and the largest number:
      min1 × min2 × max1
5. Return the maximum of the two products.

Key Idea:
- Two negative numbers produce a positive product.
- Therefore, the answer is either:
   - The three largest positive numbers, or
   - The two smallest (most negative) numbers
     together with the largest positive number.

Example:
Input:
[-10, -10, 5, 2]

Products:
5 × 2 × (-10) = -100
(-10) × (-10) × 5 = 500

Answer:
500

Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int max1 = INT_MIN;
        int max2 = INT_MIN;
        int max3 = INT_MIN;

        int min1 = INT_MAX;
        int min2 = INT_MAX;

        for (int num : nums) {

            // Update three largest numbers
            if (num > max1) {
                max3 = max2;
                max2 = max1;
                max1 = num;
            }
            else if (num > max2) {
                max3 = max2;
                max2 = num;
            }
            else if (num > max3) {
                max3 = num;
            }

            // Update two smallest numbers
            if (num < min1) {
                min2 = min1;
                min1 = num;
            }
            else if (num < min2) {
                min2 = num;
            }
        }

        return max(
            max1 * max2 * max3,
            min1 * min2 * max1
        );
    }
};
