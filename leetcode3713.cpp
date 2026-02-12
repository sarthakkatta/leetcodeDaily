/*
Problem: Longest Balanced Substring

Approach:
1. Fix a starting index i.
2. Expand substring till j.
3. Maintain frequency array of 26 characters.
4. Track:
   - different → number of distinct characters
   - maxF → maximum frequency among characters
5. A substring is balanced if:
      length == maxF * different
6. Update maximum valid length.

Time Complexity: O(N²)
Space Complexity: O(1)
*/

class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 0;

        for(int i = 0; i < n ; i++){
            vector<int> freq(26,0);
            int different = 0;
            int maxF = 0;

            for(int j = i;j < n; j++){
                int idx = s[j] - 'a';

                if(freq[idx] == 0){
                    different++;
                }

                freq[idx]++;
                maxF = max(maxF, freq[idx]);

                int length = j - i + 1;

                if(length == maxF * different){
                    ans = max(ans, length);
                }
            }
        }

        return ans;
    }
};
