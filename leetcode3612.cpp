/*
Problem: Process String with Special Operations I

Approach:
1. Maintain a result string `res`.
2. Traverse each character of the input string.
3. Apply operations based on character:
   - '*' :
       Remove the last character from res
       (if res is not empty).
   - '#' :
       Duplicate the current string.
       Example: "ab" → "abab"
   - '%' :
       Reverse the current string.
   - 'a' to 'z' :
       Append the character to res.
4. Continue processing until the end.
5. Return the final string.

Key Idea:
- Treat special symbols as commands that
  modify the current result string.

Time Complexity:
- O(N + total operations on res)
- Worst Case: O(N²)
  (due to repeated duplication and reversals)

Space Complexity: O(N)
*/

class Solution {
public:
    string processStr(string s) {
        string res;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            char ch = s[i];

            if (ch == '*') {
                if (res.length() != 0) {
                    res.pop_back();
                }
            } 
            else if (ch == '#') {
                res += res;
            } 
            else if (ch == '%') {
                reverse(res.begin(), res.end());
            } 
            else if (ch >= 'a' && ch <= 'z') {
                res.push_back(ch);
            }
        }

        return res;
    }
};
