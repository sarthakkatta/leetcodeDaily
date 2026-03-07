/*
Problem: LeetCode 1888 – Minimum Number of Flips to Make the Binary String Alternating


Approach:
1. Create two alternating patterns (s1 = "1010..." and s2 = "0101...") of length 2n.
2. Use sliding window of size n on circular string.
3. Count mismatches with both patterns.
4. Expand window by increasing j.
5. Shrink window if size exceeds n.
6. Track minimum flips required.

Time Complexity: O(N)
Space Complexity: O(N)
*/


class Solution{
public:
    int minFlips(string s){
        int n = s.size();

        string s1, s2;

        for(int i = 0; i < 2*n; i++){
            s1 += (i % 2 ? '0' : '1');
            s2 += (i % 2 ? '1' : '0');
        }

        int i = 0, j = 0;
        int result1 = 0, result2 = 0;
        int result = INT_MAX;

        while(j < 2*n){
            if(s[j % n] != s1[j]) 
                result1++;
            if(s[j % n] != s2[j]) 
                result2++;

            if(j - i + 1 > n){
                if(s[i % n] != s1[i]) 
                    result1--;
                if(s[i % n] != s2[i]) 
                    result2--;
                i++;
            }

            if(j - i + 1 == n)
                result = min({result, result1, result2});

            j++;
        }

        return result;
    }
};
