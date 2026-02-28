/*
Problem: LeetCode 1680 – Concatenation of Consecutive Binary Numbers


Approach 1:
1. Iterate from 1 to n.
2. Find number of binary digits using log2(i) + 1.
3. Left shift result by number of digits.
4. Add current number.
5. Take modulo (1e9 + 7).

Time Complexity: O(N)
Space Complexity: O(1)


Approach 2:
1. Iterate from 1 to n.
2. Increase digit count only when i is a power of 2.
3. Left shift result by current digit count.
4. Add current number.
5. Take modulo (1e9 + 7).

Time Complexity: O(N)
Space Complexity: O(1)
*/


// APPROACH 1:
class Solution {
public:
    int M = 1e9 + 7;

    int concatenatedBinary(int n) {
        long res = 0;
        for(int i = 1; i <= n; i++){
            int digits = log2(i) + 1;
            res = ((res << digits) % M + i) % M;
        }
        return res;
    }
};


// APPROACH 2:
class Solution2 {
public:
    int M = 1e9 + 7;

    int concatenatedBinary(int n) {
        long res = 0;
        int digit = 0;
        for(int i = 1; i <= n; i++){
            if((i & (i - 1)) == 0){
                digit++;
            }
            res = ((res << digit) % M + i) % M;
        }
        return res;
    }
};
