/*
Problem: LeetCode 3302 – Find the Lexicographically Smallest Valid Sequence

Approach:
1. We need to select indices from word1 to form word2.
2. At most one character is allowed to be different
   from the corresponding character in word2.
3. First, traverse word1 from right to left:
   - Match word2 from its last character.
   - Store in `last[j]` the earliest index from the right
     where word2[j] can be matched.
4. This `last` array helps us decide whether we can safely
   use our one allowed mismatch at the current position.
5. Traverse word1 from left to right:
   - If current character matches word2[j],
     select the index normally.
   - Otherwise, use the mismatch only if:
       a) We have not used it yet.
       b) There are enough characters remaining to
          complete the rest of word2.
6. When a mismatch is used:
   - Set `skip = 1`.
7. Continue until all characters of word2 are matched.
8. If all m characters are matched:
   - Return their indices.
9. Otherwise:
   - Return an empty vector.

Key Idea:
- `last[j]` tells us how far we can go from the right
  while still matching the remaining part of word2.
- The greedy left-to-right traversal gives the earliest
  possible indices while allowing at most one mismatch.

Example:
word1 = "abcde"
word2 = "abd"

Possible selection:
a → index 0
b → index 1
d → index 3

The selected sequence forms "abd", so:
[0, 1, 3]

Time Complexity: O(N + M)

Space Complexity: O(M)
*/

class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> last(m, -1);

        int j = m - 1;

        // Find matching positions from right to left
        for (int i = n - 1; i >= 0; --i) {
            if (j >= 0 && word1[i] == word2[j]) {
                last[j] = i;
                j--;
            }
        }

        vector<int> ans;

        int skip = 0;
        j = 0;

        // Build the answer from left to right
        for (int i = 0; i < n; i++) {

            if (j == m) {
                break;
            }

            if (word1[i] == word2[j] ||
                (skip == 0 &&
                 (j == m - 1 || i < last[j + 1]))) {

                // Use the one allowed mismatch
                if(word1[i] != word2[j]) {
                    skip = 1;
                }

                ans.push_back(i);
                j++;
            }
        }

        if(j != m) {
            return {};
        }

        return ans;
    }
};
