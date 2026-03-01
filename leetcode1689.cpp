/*
Problem: LeetCode 1689 – Partitioning Into Minimum Number Of Deci-Binary Numbers


Approach:
1. A deci-binary number contains only digits 0 or 1.
2. The minimum number of such numbers required equals
   the maximum digit present in the string.
3. Traverse the string and track the maximum digit.
4. Return that maximum digit.

Time Complexity: O(N)
Space Complexity: O(1)
*/


class Solution{
public:
    int minPartitions(string n){
        int maxi = 0;
        for(char c : n)
            maxi = max(maxi, c - '0');
        return maxi;
    }
};
