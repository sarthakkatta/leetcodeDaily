/*
Problem: LeetCode 1009 – Complement of Base 10 Integer

Approach:
1. The complement of a number is obtained by flipping all bits in its binary representation.
2. If n = 0, return 1 as its complement.
3. Create a mask containing all 1s with the same number of bits as n.
4. Keep expanding the mask using left shift until it covers n.
5. XOR the mask with n to flip all bits.

Time Complexity: O(log N)
Space Complexity: O(1)
*/

class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;

        int mask = 1;

        while(mask < n){
            mask = (mask << 1) | 1;
        }

        return mask ^ n;
    }
};
