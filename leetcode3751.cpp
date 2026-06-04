/*
Problem: Total Waviness of Numbers in Range I

Approach:
1. Create helper function waviness(num):
   - Convert number to string.
   - Traverse all middle digits.
2. A digit contributes to waviness if:
   - It is greater than both neighbors (peak), OR
   - It is smaller than both neighbors (valley).
3. Count all such positions and return count.
4. In totalWaviness():
   - Iterate through all numbers from num1 to num2.
   - Compute waviness of each number.
   - Add to overall answer.
5. Return total waviness.

Key Idea:
- A waviness point is a local maximum or local minimum
  among its adjacent digits.

Time Complexity: O((num2 - num1 + 1) × D)
  where D = number of digits
Space Complexity: O(D)
*/

class Solution {
public:
    int waviness(int num){
        string s = to_string(num);
        int cnt = 0;

        for(int i = 1; i < (int)s.size() - 1; i++){
            if((s[i] > s[i- 1] && s[i] > s[i + 1]) ||
            (s[i] < s[i - 1] && s[i] < s[i + 1])){
                cnt++;
            }
        }
        return cnt;
    }

    int totalWaviness(int num1, int num2) {
        int ans = 0;
        for(int i = num1; i <= num2; i++){
            ans += waviness(i);
        }
        return ans;
    }
};
