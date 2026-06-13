/*
Problem: Map Word Weights (Custom)

Approach:
1. Traverse each word in the words array.
2. For every word:
   - Compute the total weight of its characters.
3. Character weight:
   - weights[ch - 'a']
4. Calculate:
   - sum % 26
5. Map result to a character:
   - 'z' - (sum % 26)
6. Append generated character to answer string.
7. Return final string.

Key Idea:
- Each word is converted into a single character
  based on the modulo of its total weight.

Time Complexity: O(T)
  where T = total number of characters across all words

Space Complexity: O(1)
  (excluding output string)
*/

class Solution {
public: 
    string mapWordWeights(vector<string>& words, vector<int>& weights) { 
        string ans;

        for (string& word : words) {
            long long sum = 0;

            for (char ch : word) { 
                sum += weights[ch - 'a']; 
            }

            ans.push_back('z' - (sum % 26));
        }

        return ans;
    } 
};
