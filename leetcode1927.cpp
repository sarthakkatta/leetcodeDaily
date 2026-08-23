/*
Problem: LeetCode 1927 – Sum Game

Approach:
1. String ko do equal halves mein divide karte hain.
2. Har half ke liye:
   - `leftSum` / `rightSum` → known digits ka sum.
   - `leftQ` / `rightQ` → '?' ki count.
3. Alice aur Bob '?' ko digits se replace karte hain.
4. Game ka result compare karne ke liye:
      2 * (leftSum - rightSum)
   aur
      9 * (rightQ - leftQ)
   ke beech relation check karte hain.
5. Agar dono expressions equal hain, Bob game ko
   balance kar sakta hai.
6. Otherwise Alice winning position mein hoti hai.

Key Idea:
- Har '?' ki value 0 se 9 ke beech ho sakti hai.
- Ek '?' ke average contribution ko 4.5 maana ja sakta hai.
- Isliye 2 × sum difference aur 9 × question-mark
  difference ka comparison important hai.
- Agar:
      2 * (leftSum - rightSum) == 9 * (rightQ - leftQ)
  to game balanced hai.
- Otherwise result true hota hai.

Example:

num = "5023??"

Left half:
"502"
leftSum = 7
leftQ = 0

Right half:
"3??"
rightSum = 3
rightQ = 2

Expression:
2 * (7 - 3) = 8
9 * (2 - 0) = 18

Since they are not equal,
Alice wins.
Time Complexity: O(N)
Space Complexity: O(1)
*/
class Solution {
public:
    bool sumGame(string num) {
        int leftSum = 0, rightSum = 0;
        int leftQ = 0, rightQ = 0;
        int n = num.size();
        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?')
                leftQ++;
            else
                leftSum += num[i] - '0';
        }
        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?')
                rightQ++;
            else
                rightSum += num[i] - '0';
        }
        return 2 * (leftSum - rightSum) != 9 * (rightQ - leftQ);

    }

};
