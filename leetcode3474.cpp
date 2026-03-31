/*
Problem: Lexicographically Smallest Generated String

Approach:
1. Initialize result string with '?' of length (n + m - 1).
2. For 'T' positions:
   - Ensure substring equals t by filling characters.
   - If conflict occurs, return "".
3. Replace remaining '?' with 'a'.
4. For 'F' positions:
   - If substring equals t, modify one position (prefer last '?') to break match.
   - If not possible, return "".
5. Return the constructed string.

Time Complexity: O(N * M)
Space Complexity: O(N)
*/

class Solution {
public:
    string generateString(string s, string t) {
        int n = s.size(), m = t.size();
        string ans(n + m - 1, '?');

        // Process T
        for (int i = 0; i < n; i++) {
            if (s[i] != 'T') {
                continue;
            }
            for (int j = 0; j < m; j++) {
                char v = ans[i + j];
                if (v != '?' && v != t[j]) {
                    return "";
                }
                ans[i + j] = t[j];
            }
        }

        string old_ans = ans;
        for (char& c : ans) {
            if (c == '?') {
                c = 'a';
            }
        }

        // Process F
        for (int i = 0; i < n; i++) {
            if (s[i] != 'F') {
                continue;
            }
            if (string(ans.begin() + i, ans.begin() + i + m) != t) {
                continue;
            }
            bool ok = false;
            for (int j = i + m - 1; j >= i; j--) {
                if (old_ans[j] == '?') {
                    ans[j] = 'b';
                    ok = true;
                    break;
                }
            }
            if (!ok) {
                return "";
            }
        }

        return ans;
    }
};
