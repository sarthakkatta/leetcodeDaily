/*
Problem: Process String with Special Operations II

Approach:
1. First Pass:
   - Compute final length L of the processed string
     without actually building it.
   - Operations:
       '*' → remove one character if possible
       '#' → double current length
       '%' → reverse (length unchanged)
       letter → increase length by 1
2. If k >= L:
   - Requested position does not exist.
   - Return '.'.
3. Second Pass (Reverse Traversal):
   - Undo operations from right to left.
4. Reverse handling:
   - '%' :
       k = L - k - 1
5. Duplication handling:
   - '#' :
       Original length = L / 2
       If k lies in second half,
       map it back to first half.
6. Deletion handling:
   - '*' :
       Increase length by 1 while reversing.
7. Character handling:
   - Decrease length.
   - If k equals current length,
     this character is the answer.
8. Return the found character.

Key Idea:
- Avoid constructing the potentially huge string.
- Work backward from the final string to locate
  the original character at position k.

Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.length();

        long long L = 0;

        for(char &ch : s) {
            if(ch == '*') {
                if(L > 0)
                    L--;
            }
            else if(ch == '#') {
                L *= 2;
            }
            else if(ch == '%') {
                // reverse → length unchanged
                continue;
            }
            else { // 'a' to 'z'
                L++;
            }
        }

        if(k >= L) {
            return '.';
        }

        for(int i = n - 1; i >= 0; i--) {

            if(s[i] == '*') {
                L++; // undo deletion
            }
            else if(s[i] == '%') {
                k = L - k - 1;
            }
            else if(s[i] == '#') {
                L = L / 2;

                k = (k >= L) ? k - L : k;
            }
            else { // letter
                L--;

                if(k == L) {
                    return s[i];
                }
            }
        }

        return '.';
    }
};
