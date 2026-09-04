/*
Problem: 3903. Smallest Stable Index I

For every index i, we calculate:

    score = max(nums[0...i]) - min(nums[i...n-1])

If score <= k, then index i is considered stable.
We need to return the smallest such index.
If no such index exists, return -1.

Approach:
---------
1. Create a prefix maximum array `maxi`:
   - maxi[i] stores the maximum value from nums[0] to nums[i].
   - This lets us get the maximum of the left part in O(1).

2. Create a suffix minimum array `mini`:
   - mini[i] stores the minimum value from nums[i] to nums[n-1].
   - This lets us get the minimum of the right part in O(1).

3. For every index i:
   - `maxi[i]` gives the maximum element from the left side.
   - `mini[i]` gives the minimum element from the right side.
   - Calculate:
       score = maxi[i] - mini[i]

4. If `score <= k`:
   - Index i satisfies the required condition.
   - Store the smallest valid index using `min(idx, i)`.

5. After checking all indices:
   - If no valid index was found, return -1.
   - Otherwise, return the smallest valid index.

Key Idea:
---------
The main problem is that for every index i we need:

    maximum of nums[0...i]
    minimum of nums[i...n-1]

Calculating these directly for every index would take O(n^2).

So we precompute:
- Prefix maximum -> maximum value up to every index.
- Suffix minimum -> minimum value from every index onward.

After that, each index can be checked in O(1).

Example:
--------
nums = [3, 5, 2, 6]
k = 3

Prefix maximum:
maxi = [3, 5, 5, 6]

Suffix minimum:
mini = [2, 2, 2, 6]

Now check each index:

i = 0:
score = 3 - 2 = 1 <= 3
So index 0 is valid.

Since we need the FIRST stable index, the answer is 0.

Example 2:
----------
nums = [5, 8, 10]
k = 1

Prefix maximum:
maxi = [5, 8, 10]

Suffix minimum:
mini = [5, 8, 10]

i = 0:
score = 5 - 5 = 0 <= 1

So index 0 is valid and is the smallest possible index.

Answer = 0.

Time Complexity:
----------------
O(n)

- Building prefix maximum array: O(n)
- Building suffix minimum array: O(n)
- Checking every index: O(n)

Total = O(n)

Space Complexity:
-----------------
O(n)

We use two additional arrays:
- `maxi`
- `mini`
*/

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> maxi(n,INT_MIN);
        vector<int> mini(n,INT_MAX);
        maxi[0] = nums[0];
        mini[n-1] = nums[n-1];
        for(int i = 1; i < n; i++){
                maxi[i] = max(nums[i],maxi[i-1]);
        }
        for(int i = n-2; i >= 0; i--){
                mini[i] = min(nums[i],mini[i+1]);
        }
        int idx = n;
        for(int i = 0; i < n; i++){
                int score = maxi[i] - mini[i];
                if(score <= k){
                    idx = min(idx,i);
                }
        }
        return idx == n? -1 : idx;
    }
};
