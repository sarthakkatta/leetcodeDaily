/*
Problem:
---------
LeetCode 2333 - Minimum Sum of Squared Difference


Approach:
---------
For every index, we first calculate the absolute difference between
`nums1[i]` and `nums2[i]`.

We store the frequency of every difference in the `dist` array.

For example, if the differences are:

    [5, 5, 3, 2, 2]

then:

    dist[5] = 2
    dist[3] = 1
    dist[2] = 2

We also calculate:
- `sum` = total sum of all differences.
- `mx` = maximum difference.
- `k` = total number of operations available from `k1 + k2`.

If the total difference is already less than or equal to the available
operations, we can reduce every difference to zero, so the answer is 0.

Otherwise, we need to use our operations in the most efficient way.

Since the final answer contains squared differences, reducing a larger
difference gives more benefit than reducing a smaller difference.

Therefore, we start from the maximum difference and reduce the largest
differences first.

For every difference `i`:
- `dist[i]` tells us how many elements currently have difference `i`.
- We can move some of them from difference `i` to difference `i - 1`.
- The number of elements we can move is:

    min(k, dist[i])

Each such move uses one operation.

We continue from the largest difference toward smaller differences until
we run out of operations.

Finally, we calculate the sum of squared differences using:

    i * i * dist[i]

for every possible difference.


Key Idea:
---------
The key observation is that we should always reduce the largest
differences first.

Suppose we have:

    differences = [5, 2]

and one operation is available.

If we reduce `5 -> 4`:

    5² + 2² = 25 + 4 = 29
    4² + 2² = 16 + 4 = 20

Reduction = 9.

But if we reduce `2 -> 1`:

    5² + 2² = 29
    5² + 1² = 26

Reduction = 3.

So reducing the larger difference gives a bigger improvement.

The frequency array allows us to process all equal differences together
instead of processing every element separately.

The total available operations are:

    k = k1 + k2

because both `k1` and `k2` can independently reduce the differences.


Example:
--------
Input:
nums1 = [1, 4, 10]
nums2 = [3, 1, 5]
k1 = 2
k2 = 1

Differences:

    |1 - 3| = 2
    |4 - 1| = 3
    |10 - 5| = 5

So:

    differences = [2, 3, 5]

Total operations:

    k = 2 + 1 = 3

We start reducing the largest difference:

    5 -> 4
    4 -> 3
    3 -> 2

Now the differences become:

    [2, 2, 2]

The final squared sum is:

    2² + 2² + 2²
    = 4 + 4 + 4
    = 12


Time Complexity:
----------------
O(n + D)

where:
- `n` = size of the input arrays.
- `D` = maximum possible difference.

Since the values are bounded by 100000, the frequency array has a
fixed maximum size.


Space Complexity:
-----------------
O(D)

The `dist` frequency array stores the count of every possible difference.
Here `D` is at most 100000.
*/

class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<int> dist(100001, 0);
        long long k = (long long)k1 + k2, sum = 0;
        int mx = 0;
        //count the differences and maximum difference
        for (int i = 0; i < nums1.size(); i++) {
            int x = abs(nums1[i] - nums2[i]);
            dist[x]++;
            sum += x;
            mx = max(mx, x);
        }
        // Enough budget -> every difference becomes 0
        if (sum <= k) return 0;
        // Step 2: shave the biggest differences, level by level
        for (int i = mx; i > 0 && k > 0; i--) {
            long long move = min(k, (long long)dist[i]);
            dist[i] -= move;
            dist[i - 1] += move;
            k -= move;
        }
        // Step 3: add up the squares
        long long ans = 0;
        for (int i = 0; i <= mx; i++)
            ans += (long long)i * i * dist[i];

        return ans;
    }
};
