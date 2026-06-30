/*
Problem: LeetCode 1358 – Number of Substrings Containing All Three Characters

Approach:
1. Maintain the last seen index of:
   - 'a'
   - 'b'
   - 'c'
2. Initialize:
   - lastSeen = {-1, -1, -1}
3. Traverse the string:
   - Update the last seen position of
     the current character.
4. At each index i:
   - If all three characters have appeared:
       lastSeen[0] != -1
       lastSeen[1] != -1
       lastSeen[2] != -1
5. Find the earliest among the three
   last seen positions:
       min(lastSeen[0], lastSeen[1], lastSeen[2])
6. Every starting index from:
       0 to minimum last seen index
   forms a valid substring ending at i.
7. Number of such substrings:
       1 + min(lastSeen)
8. Add this value to the answer.
9. Return the total count.

Key Idea:
- For every ending index, the earliest
  occurrence among the latest 'a', 'b', and 'c'
  determines how many valid starting positions exist.

Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> lastSeen(3, -1);

        int count = 0;

        for (int i = 0; i < s.size(); i++) {
            lastSeen[s[i] - 'a'] = i;

            if (lastSeen[0] != -1 &&
                lastSeen[1] != -1 &&
                lastSeen[2] != -1) {

                count += 1 + min({
                    lastSeen[0],
                    lastSeen[1],
                    lastSeen[2]
                });
            }
        }

        return count;
    }
};
