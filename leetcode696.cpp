/*
Problem: LeetCode 696 – Count Binary Substrings

Approach:
1. Count length of consecutive groups of same characters.
2. For each new group → add min(previous group length, current group length).
3. This ensures equal number of 0s and 1s.
4. Sum all valid counts.

Time Complexity: O(N)
Space Complexity: O(1)
*/


class Solution {
public:

    int countBinarySubstrings(string s) {

        int res = 0;

        int prevC = 0;

        int currC = 1;

        for(int i = 1;
            i < s.length();
            i++){

            if(s[i] == s[i-1]){

                currC++;
            }
            else{

                res += min(currC, prevC);

                prevC = currC;

                currC = 1;
            }
        }

        return res + min(currC, prevC);
    }
};
