/*
Problem:
---------
LeetCode 3483. Unique 3-Digit Even Numbers

Approach:
---------
1. Use a frequency array `f[10]`:
   - `f[d]` stores how many times digit `d` appears in `digits`.
   - This allows us to check whether a digit is available without
     actually choosing and removing elements.

2. Count the frequency of every digit:
       f[d]++

3. Construct every possible 3-digit number:
   - First digit `i`:
       - It ranges from 1 to 9 because a 3-digit number cannot start
         with 0.
   - Second digit `j`:
       - It can range from 0 to 9.
   - Third digit `k`:
       - It must be even because the number has to be even.
       - Therefore, `k` takes values:
         0, 2, 4, 6, 8

4. Check whether the required digits are available:
   - `f[i] > 0`
       -> We need at least one occurrence of the first digit.

   - `f[j] > (i == j)`
       -> If `j` is the same as `i`, we need two copies of that digit.
       -> Otherwise, one copy is enough.

   - `f[k] > (i == k) + (j == k)`
       -> Count how many times digit `k` is already used by `i` and `j`.
       -> The frequency of `k` must be greater than that count.

5. If all three conditions are satisfied:
   - A valid 3-digit even number can be formed.
   - Increment `res`.

6. Return `res`.

Key Idea:
---------
We don't need to explicitly generate the numbers or use a set.

Since the number has exactly three positions:

    [hundreds] [tens] [ones]

We can directly try every possible digit combination.

Conditions:
- Hundreds digit cannot be 0.
- Ones digit must be even.
- The available frequency of each digit must be sufficient.

The expressions:

    (i == j)

and

    (i == k) + (j == k)

automatically handle repeated digits.

For example, if:

    i = 2, j = 2

then we need two copies of digit 2.

If:

    i = 2, j = 5, k = 2

then digit 2 is required twice, so:

    (i == k) + (j == k) = 1 + 0 = 1

Therefore, `f[2]` must be greater than 1.

Example:
--------
digits = [2, 1, 3, 0]

Possible valid numbers include:

    102
    120
    130
    132
    210
    230
    302
    310
    312
    320

The first digit is never 0, and the last digit is always even.

The frequency array ensures that every digit used in the number actually
exists in the input.

Time Complexity:
----------------
O(10 × 10 × 5)

The loops only consider:
- 9 possible first digits
- 10 possible second digits
- 5 possible even last digits

Since these are fixed constants, the overall complexity is:

    O(1)

Space Complexity:
-----------------
O(1)

The frequency array contains only 10 elements.
*/


// class Solution {
// public:
//     int totalNumbers(vector<int>& digits) {
//         unordered_set<int> set;
//         int n = digits.size();
//         for(int i = 0; i < n; i++) {
//             if(digits[i] == 0) {
//                 continue;
//             }
//             for(int j = 0; j < n; j++) {
//                 if(j == i) {
//                     continue;
//                 }
//                 for(int k = 0; k < n; k++) {
//                     if(k == i || k == j) {
//                         continue;
//                     }
//                     if(digits[k] % 2 == 0) {
//                         int num = digits[i] * 100 + digits[j] * 10 + digits[k];
//                         set.insert(num);
//                     }
//                 }
//             }
//         }
//         return set.size();
//     }
// };


class Solution {
public:
    int totalNumbers(auto& digits) {
        int f[10] = {0};
        int res = 0;
        for (auto& d : digits) f[d]++;
        for (int i = 1; i < 10; i++) 
            for (int j = 0; j < 10; j++) 
                for (int k = 0; k < 9; k += 2) 
                    res += f[i] > 0 &&
                           f[j] > (i == j) &&
                           f[k] > (i == k) + (j == k);
        
        return res;
    }
};
