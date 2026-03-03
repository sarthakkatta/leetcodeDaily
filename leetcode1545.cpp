/*
Problem: LeetCode 1545 – Find Kth Bit in Nth Binary String


Approach:
1. Base case: if n == 1, return '0'.
2. Length of nth string = (2^n) - 1.
3. Middle position is always '1'.
4. If k is in left half, recurse on (n-1, k).
5. If k is in right half, find mirrored position
   and invert the result.
6. Return final character.

Time Complexity: O(N)
Space Complexity: O(N)
*/


class Solution{
public:
    char findKthBit(int n, int k){
        if(n == 1) return '0';
        int len = (1 << n) - 1;
        int mid = (len + 1) / 2;
        if(k == mid) return '1';
        if(k < mid) return findKthBit(n - 1, k);
        char c = findKthBit(n - 1, len - k + 1);
        return c == '0' ? '1' : '0';
    }
};
