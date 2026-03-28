/*
Problem: LeetCode 2573 – Find the String with LCP

Approach:
1. Initialize a string with placeholder characters.
2. Assign characters greedily from left to right using 'a', 'b', ...
3. If lcp[i][j] > 0, assign same character to positions i and j.
4. Ensure no more than 26 distinct characters are used.
5. Validate the constructed string using LCP rules:
   - If characters differ, lcp[i][j] must be 0.
   - If characters match, lcp[i][j] = lcp[i+1][j+1] + 1.
6. If validation fails, return empty string.

Time Complexity: O(N^2)
Space Complexity: O(N)
*/

class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        string word(n, '\0');
        char current = 'a';

        for (int i = 0; i < n; i++) {
            if (word[i] == '\0') {
                if (current > 'z') {
                    return "";
                }
                word[i] = current;
                for (int j = i + 1; j < n; j++) {
                    if (lcp[i][j] > 0) {
                        word[j] = word[i];
                    }
                }
                current++;
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (word[i] != word[j]) {
                    if (lcp[i][j]) {
                        return "";
                    }
                } else {
                    if (i == n - 1 || j == n - 1) {
                        if (lcp[i][j] != 1) {
                            return "";
                        }
                    } else {
                        if (lcp[i][j] != lcp[i + 1][j + 1] + 1) {
                            return "";
                        }
                    }
                }
            }
        }

        return word;
    }
};
