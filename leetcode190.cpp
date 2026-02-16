/*
Problem: LeetCode 190 – Reverse Bits


Approach:
1. Traverse all 32 bits of the number.
2. Shift result left to make space.
3. Extract current bit from n using shift and AND.
4. Add extracted bit to result using OR.
5. Final result is reversed bits number.

Time Complexity: O(32)
Space Complexity: O(1)
*/


class Solution {
public:
    int reverseBits(int n) {
        int rev = 0;
        for(int i = 0; i < 32; i++) {
            rev = rev << 1;
            // Shift rev to the left by 1 position.
            // This creates space at the right to insert the new bit.
            // Example: rev = 101 → becomes 1010
            int bit = (n >> i) & 1;
            // Shift n right by i positions to bring the desired bit to the last position.
            // AND with 1 extracts only that last bit.
            // Example:
            // n = 1011
            // i = 2 → (1011 >> 2) = 10 → 10 & 1 = 0
            rev = rev | bit;
            // Insert the extracted bit into rev.
            // OR operation puts the bit in the empty space created earlier.
            // Example: rev = 1010, bit = 1 → rev becomes 1011
        }
        return rev;
    }
};
