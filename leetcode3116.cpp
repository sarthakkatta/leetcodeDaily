/*
Problem: LeetCode 3116 – Kth Smallest Amount With Single Denomination Combination

Approach:
1. Humein kth smallest number find karna hai jo given
   coins me se kisi ek coin se divisible ho.
2. Directly numbers generate karna expensive ho sakta hai,
   isliye Binary Search on Answer use karte hain.
3. `countNumbers(x)` function batata hai:
      1 se x tak kitne valid numbers hain.
4. Kisi number ko valid tab maana jaata hai jab woh
   at least ek coin se divisible ho.
5. Multiple coins ke overlap ko handle karne ke liye
   Inclusion-Exclusion Principle use karte hain.
6. Har subset of coins ke liye:
   - Unka LCM calculate karte hain.
   - x / LCM batata hai ki kitne numbers us LCM
     se divisible hain.
7. Agar selected coins ki count odd hai:
      count += numbers
8. Agar selected coins ki count even hai:
      count -= numbers
9. Ab Binary Search:
   - Agar mid tak k ya usse zyada valid numbers hain,
     answer mid ya usse chhota ho sakta hai.
   - Otherwise answer mid se bada hoga.
10. Finally left hi kth smallest valid number hoga.

Key Idea:
- Inclusion-Exclusion overlapping multiples ko
  correctly count karta hai.
- Binary Search answer ko efficiently find karta hai.
- LCM se pata chalta hai ki multiple selected coins
  ke common multiples kya hain.

Example:

coins = [3, 5]
k = 5

Valid numbers:
3, 5, 6, 9, 10, 12, ...

5th smallest = 10

For x = 10:
Multiples of 3 = 3
Multiples of 5 = 2
Multiples of LCM(3,5) = 1

Count:
3 + 2 - 1 = 4

So 10 tak sirf 4 valid numbers hain.
Binary Search continue karega until count >= 5.

Time Complexity:
O(2^N × N × log(min(coins) × k))

Space Complexity: O(1)
*/

class Solution {
public:
    long long gcd(long long a, long long b) {
        while (b != 0) {
            long long temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }
    long long lcm(long long a, long long b) {
        return (a / gcd(a, b)) * b;
    }
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        // This function tells us:
        // "x tak kitne valid numbers hain?"
        auto countNumbers = [&](long long x) {
            long long count = 0;
            // Try every possible subset of coins
            for (int mask = 1; mask < (1 << n); mask++) {
                long long currentLCM = 1;
                // Number of selected coins in this mask
                int selectedCoins = 0;
                for (int i = 0; i < n; i++) {
                    // Is coin[i] selected?
                    if (mask & (1 << i)) {
                        selectedCoins++;

                        currentLCM = lcm(currentLCM,coins[i]);
                    }
                }
                // How many numbers <= x are divisible
                // by this LCM?
                long long numbers = x / currentLCM;
                // Odd number of coins selected
                // -> ADD
                if (selectedCoins % 2 == 1) {
                    count += numbers;
                }
                // Even number of coins selected
                // -> SUBTRACT
                else {
                    count -= numbers;
                }
            }
            return count;
        };
        // Binary Search
        long long left = 1;
        long long right = 1LL * (*min_element(coins.begin(), coins.end())) * k;
        while (left < right) {
            long long mid = left + (right - left) / 2;
            // Agar mid tak k ya usse zyada
            // valid numbers mil gaye
            if (countNumbers(mid) >= k) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return left;
    }
};
