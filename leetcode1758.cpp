/*
Problem: LeetCode 1758 – Minimum Changes To Make Alternating Binary String


Approach:
1. There are two possible alternating patterns:
   - "010101..."
   - "101010..."
2. Count changes needed to convert string to first pattern (cnt1).
3. Count changes needed to convert string to second pattern (cnt2).
4. Return minimum of cnt1 and cnt2.

Time Complexity: O(N)
Space Complexity: O(1)
*/


class Solution{
public:
    int minOperations(string s){
        int cnt1 = 0;
        int cnt2 = 0;

        for(int i = 0; i < s.length(); i++){
            if(i % 2 == 0){
                if(s[i] != '0') cnt1++;
            }
            else{
                if(s[i] != '1') cnt1++;
            }

            if(i % 2 == 0){
                if(s[i] != '1') cnt2++;
            }
            else{
                if(s[i] != '0') cnt2++;
            }
        }

        return min(cnt1, cnt2);
    }
};
