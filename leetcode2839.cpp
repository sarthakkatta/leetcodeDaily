/*
Problem:Check if Strings Can be Made Equal With Operations I

Approach:
1. If both strings are already equal, return true.
2. Try swapping indices (0,2) and check.
3. Try swapping indices (1,3) and check.
4. Try performing both swaps.
5. If any configuration matches, return true, otherwise false.

Time Complexity: O(1)
Space Complexity: O(1)
*/

class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        if(s1 == s2) return true;
        
        //case 1: swap index 0 & 2
        swap(s1[0], s1[2]); 
        if(s1 == s2) return true; 
        swap(s1[0], s1[2]); //revert back

        //case 2: swap index 1 & 3
        swap(s1[1], s1[3]); 
        if(s1 == s2) return true;

        //case 3: swap both (0&2 and 1&3)
        swap(s1[0], s1[2]);

        return s1 == s2;
    }   
};
