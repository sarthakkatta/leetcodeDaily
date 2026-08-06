/*
Problem: LeetCode 3345 – Smallest Divisible Digit Product I

Approach:
1. Start checking from the given number n.
2. For the current number:
   - Calculate the product of all its digits.
3. If:
      product % t == 0
   then the current number satisfies the condition.
4. Return the current number.
5. Otherwise:
   - Increment n.
   - Repeat the process until a valid number is found.

Key Idea:
- Brute force every number starting from n.
- For each number, compute the product of its digits.
- The first number whose digit product is divisible
  by t is the required answer.

Example:
Input:
n = 10
t = 2

10:
Product = 1 × 0 = 0
0 % 2 = 0

Output:
10

Time Complexity:
O(K × D)

where:
- K = number of integers checked
- D = number of digits in each integer

Space Complexity: O(1)
*/

class Solution {
public:
    int smallestNumber(int n, int t) {

        while (true) {

            int product = 1;
            int x = n;

            while (x > 0) {
                product *= (x % 10);
                x /= 10;
            }

            if (product % t == 0)
                return n;

            n++;
        }
    }
};
