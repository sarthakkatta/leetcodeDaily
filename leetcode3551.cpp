/*
Problem:
---------
LeetCode 3551 - Minimum Swaps to Sort by Digit Sum


Approach:
---------
First, we define a `digitSum` lambda function that calculates the sum of
digits of a number.

For example:

    123 -> 1 + 2 + 3 = 6

Next, we create a copy of the original array called `sortedNums` and
sort it according to the problem's required order:

1. Numbers with smaller digit sums come first.
2. If two numbers have the same digit sum, the smaller number comes first.

After sorting, we create a map called `pos` that stores the target index
of each number in the sorted array.

For every index `i`:

    pos[sortedNums[i]] = i

This tells us where each number should be placed in the sorted array.

Next, we use a `visited` array to identify cycles in the permutation
created by mapping the original array to its sorted positions.

For every unvisited index:
- Increment `cycles`.
- Start traversing from that index.
- Mark each visited index as true.
- Move to the target position using `pos[nums[j]]`.
- Continue until the cycle is completely visited.

Finally, we calculate the minimum swaps using:

    n - cycles

This works because a cycle of length `k` requires `k - 1` swaps to put
all its elements in their correct positions.


Key Idea:
---------
The main idea is to convert the sorting problem into a cycle-counting
problem.

Suppose the original array is:

    [21, 12, 3]

Digit sums:

    21 -> 3
    12 -> 3
    3  -> 3

All digit sums are equal, so we sort by the actual values:

    [3, 12, 21]

The original elements must move to their target positions. These
movements form cycles.

For a cycle containing `k` elements, the minimum number of swaps needed
to correct that cycle is:

    k - 1

If there are `cycles` independent cycles across `n` elements, then:

    Minimum swaps = n - cycles

The `visited` array ensures that every cycle is counted exactly once.


Example:
--------
Input:
nums = [37, 100, 25, 10]

Step 1: Calculate digit sums.

    37  -> 3 + 7 = 10
    100 -> 1 + 0 + 0 = 1
    25  -> 2 + 5 = 7
    10  -> 1 + 0 = 1

Step 2: Sort by digit sum, then by numerical value.

    sortedNums = [10, 100, 25, 37]

Step 3: Determine the target positions.

    10  -> position 0
    100 -> position 1
    25  -> position 2
    37  -> position 3

The original array is:

    [37, 100, 25, 10]

The position mapping forms two cycles:
- One cycle involving indices 0 and 3.
- One cycle involving index 1.
- One cycle involving index 2.

Therefore:

    n = 4
    cycles = 3

Minimum swaps:

    4 - 3 = 1

Output:
    1


Time Complexity:
----------------
O(n log n + n * d)

where:
- `n` is the number of elements.
- `d` is the maximum number of digits in an element.

Sorting takes O(n log n) comparisons, and each comparison calculates
digit sums. Cycle detection takes O(n) expected time with the hash map.

More precisely, the sorting cost is O(n * d * log n), so the overall
time complexity is:

    O(n * d * log n)


Space Complexity:
-----------------
O(n)

The algorithm stores the sorted copy, the position map, and the visited
array, each requiring O(n) space.
*/

class Solution {\
public:\
&#x20;   int minSwaps(vector\<int>& nums) {\
&#x20;       auto digitSum = []\(int x) {\
&#x20;           int s = 0;\
&#x20;           while (x) {\
&#x20;               s += x % 10;\
&#x20;               x /= 10;\
&#x20;           }\
&#x20;           return s;\
&#x20;       };\
&#x20;       int n = nums.size();\
&#x20;       vector\<int> sortedNums = nums;\
&#x20;       sort(sortedNums.begin(), sortedNums.end(), [&]\(int a, int b) {\
&#x20;           int sa = digitSum(a), sb = digitSum(b);\
&#x20;           if (sa != sb) return sa < sb;\
&#x20;           return a < b;\
&#x20;       });\
&#x20;       unordered_map\<int, int> pos;\
&#x20;       for (int i = 0; i < n; i++) pos[sortedNums[i]] = i;\
&#x20;       vector\<bool> visited(n, false);\
&#x20;       int cycles = 0;\
&#x20;       for (int i = 0; i < n; i++) {\
&#x20;           if (!visited[i]) {\
&#x20;               cycles++;\
&#x20;               int j = i;\
&#x20;               while (!visited[j]) {\
&#x20;                   visited[j] = true;\
&#x20;                   j = pos[nums[j]];\
&#x20;               }\
&#x20;           }\
&#x20;       }\
&#x20;       return n - cycles;\
&#x20;   }\
};
