/*
Problem: LeetCode 1189 – Maximum Number of Balloons

Approach:
1. Create a frequency array of size 26.
2. Count occurrences of each character in the string.
3. To form the word "balloon", we need:
   - b → 1
   - a → 1
   - l → 2
   - o → 2
   - n → 1
4. Calculate how many complete "balloon" words
   can be formed from each required character:
   - freq['b']
   - freq['a']
   - freq['l'] / 2
   - freq['o'] / 2
   - freq['n']
5. The answer is the minimum among these values.
6. Return the result.

Key Idea:
- The character with the smallest available
  required count limits the number of times
  "balloon" can be formed.
- 'l' and 'o' are needed twice, so divide
  their frequencies by 2.

Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> freq(26, 0);

        for(char ch : text) {
            freq[ch - 'a']++;
        }

        return min({
            freq['b' - 'a'],
            freq['a' - 'a'],
            freq['l' - 'a'] / 2,
            freq['o' - 'a'] / 2,
            freq['n' - 'a']
        });
    }
};
