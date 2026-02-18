/*
Problem: LeetCode 693 – Binary Number with Alternating Bits

Approach:
1. XOR number with its right shift.
2. If bits are alternating → result will be all 1s.
3. Check if result is power of 2 minus 1 using (res & (res+1)).
4. If true → alternating bits exist.

Time Complexity: O(1)
Space Complexity: O(1)
*/


class Solution {
public:
    bool hasAlternatingBits(int n) {
        unsigned int res = n ^ (n >> 1); // is se apna res pura 1 aana chahiye
        return (res & (res + 1)) == 0; // ab check krne ki liye sab set(1) h toh apn us no ko us se ek jyda number se and kr denge
    }
};
