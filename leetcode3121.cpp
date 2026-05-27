/*
Problem: LeetCode 3121 – Count the Number of Special Characters II

Approach:
1. Store:
   - lastLower[i]  → last occurrence index of lowercase letter
   - firstUpper[i] → first occurrence index of uppercase letter
2. Traverse the string:
   - Update last position for lowercase letters.
   - Store first occurrence for uppercase letters.
3. For each character from a-z:
   - Character is special if:
       → lowercase exists
       → uppercase exists
       → last lowercase occurs before first uppercase
4. Count all such valid characters.
5. Return total count.

Key Idea:
- Lowercase character must appear before uppercase version.

Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lastLower(26, -1);
        vector<int> firstUpper(26, -1);
        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            if (islower(c)) {
                lastLower[c - 'a'] = i;
            } else {
                int idx = c - 'A';
                if (firstUpper[idx] == -1) {
                    firstUpper[idx] = i;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (lastLower[i] != -1 &&
                firstUpper[i] != -1 &&
                lastLower[i] < firstUpper[i]) {
                ans++;
            }
        }

        return ans;
    }
};
