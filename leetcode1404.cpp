/*
Problem: LeetCode 1404 – Number of Steps to Reduce a Number in Binary Representation to One


Approach:
1. Traverse binary string from right to left.
2. Maintain carry to simulate addition when odd.
3. If current bit + carry is 1 → perform add and divide (2 operations).
4. Otherwise perform only divide (1 operation).
5. Return total operations including final carry if present.

Time Complexity: O(N)
Space Complexity: O(1)
*/


class Solution{
public:
    int numSteps(string s){
        int op = 0, carry = 0;
        for(int i = s.length() - 1; i > 0; i--){
            if((s[i] - '0') + carry == 1){
                op += 2;
                carry = 1;
            }
            else{
                op += 1;
            }
        }
        return op + carry;
    }
};
