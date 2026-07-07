/*
Problem: Concatenate Non-Zero Digits and Multiply by Sum I

Approach:
1. Traverse the digits of the given number.
2. Maintain:
   - sum → sum of all non-zero digits.
   - x   → number formed using only non-zero digits.
   - pos → current place value (1, 10, 100, ...).
3. Extract the last digit:
   - digit = n % 10
4. If digit is non-zero:
   - Add it to the digit sum.
   - Append it to x using the current place value.
   - Update place value.
5. Remove the last digit:
   - n /= 10
6. After processing all digits:
   - Return x × sum.

Key Idea:
- Ignore all zero digits.
- Simultaneously build:
   - The number containing only non-zero digits.
   - The sum of those non-zero digits.
- Multiply the two values.

Example:
Input:
10203

Process:
Non-zero number = 123
Sum of digits = 1 + 2 + 3 = 6

Answer:
123 × 6 = 738

Time Complexity: O(log₁₀N)
Space Complexity: O(1)
*/

class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0;
        long long x = 0;
        long long pos = 1;

        while(n > 0) {
            int l = n % 10;

            if(l != 0) {
                x = l * pos + x;
                pos *= 10;
                sum += l;
            }

            n /= 10;
        }

        return x * sum;
    }
};
