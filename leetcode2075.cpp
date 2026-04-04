/*
Problem: LeetCode 2075 – Decode the Slanted Ciphertext

Approach:
1. Compute number of columns using total length and given rows.
2. Traverse diagonally starting from each column of the first row.
3. Move in steps of (columns + 1) to simulate diagonal movement.
4. Append characters to the result string.
5. Remove trailing spaces from the final string.

Time Complexity: O(N)
Space Complexity: O(1) (excluding output)
*/

class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int l = encodedText.length();
        int columns = l / rows;

        string originalText;
        for(int col = 0; col < columns; col++) {
            for(int j = col; j < l; j += (columns + 1)) {
                originalText += encodedText[j];
            }
        }

        while(!originalText.empty() && originalText.back() == ' ') {
            originalText.pop_back();
        }

        return originalText;
    }
};
