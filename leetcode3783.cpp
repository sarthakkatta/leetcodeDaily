/*
Problem: 3783. Mirror Distance of an Integer

Approach:
1. Define helper function:
   - Reverse the digits of given number.
2. Compute reversed number.
3. Calculate absolute difference:
   - |n - reversed(n)|
4. Return the result.

Key Idea:
- Mirror distance is difference between number and its reverse.

Time Complexity: O(D) (D = number of digits)
Space Complexity: O(1)
*/

class Solution {
public:
    int reversenum(int n){
        int rev = 0;
        while(n > 0){
            rev = rev * 10 + (n % 10);
            n /= 10;
        }
        return rev;
    }
    int mirrorDistance(int n) {
        int reverse = reversenum(n);
        return abs(n - reverse);
    }
};
