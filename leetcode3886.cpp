/*
Problem:
---------
Leetcode 3886 : Sum of Sortable Integers


Approach:
---------
The solution checks every possible block size `k` that divides the
length of the array.

First, we create a sorted copy of the original array. This represents
the target arrangement we want to achieve.

For every possible block size `k`:
- Skip it if `n % k != 0`, because the array cannot be divided into
  equal-sized blocks of length `k`.
- Divide both the original array and the sorted array into consecutive
  blocks of size `k`.
- For every corresponding pair of blocks, check whether the original
  block can be rotated to match the sorted block.
- If every block satisfies this condition, add `k` to `result`.

The helper function `isRotation()` performs the block validation.

It first sorts a copy of `vec1` and compares it with `vec2`. If they
contain different elements, the blocks cannot be rotations of each other.

Next, it counts how many times an element is greater than the next
element, considering the array circularly:

    vec1[i] > vec1[(i + 1) % n]

For a circularly sorted sequence, there can be at most one such
descending transition. Therefore, `count <= 1` is used to check whether
the block is a rotation of its sorted arrangement.

If all blocks are valid for a particular `k`, that block size is added
to the answer.


Key Idea:
---------
The main idea is to check whether each block is a cyclic rotation of
the corresponding sorted block.

For example:

    Original block = [3, 1, 2]
    Sorted block   = [1, 2, 3]

The original block is a rotation of the sorted block because:

    [1, 2, 3] -> [2, 3, 1] -> [3, 1, 2]

The circular comparison checks the number of descending transitions.

For:

    [3, 1, 2]

The circular comparisons are:
- 3 > 1 -> true
- 1 > 2 -> false
- 2 > 3 -> false

There is exactly one descending transition, so the block passes the
rotation check.

The algorithm then considers every divisor of the array length and adds
the block sizes for which all corresponding blocks are valid.


Example:
--------
Input:
nums = [3, 1, 2]

Sorted array:

    [1, 2, 3]

Possible block sizes:

    k = 1
    k = 3

For k = 1:
Each individual block contains one element. Every block is a valid
rotation of its corresponding sorted block.

So, result = 1.

For k = 3:
The entire array [3, 1, 2] is a rotation of [1, 2, 3].

So, result = 1 + 3 = 4.

Output:

    4


Time Complexity:
----------------
O(n^2 log n) in the worst case.

There are at most O(n) candidate block sizes.

For each candidate, constructing and checking the blocks takes O(n)
total elements. However, `isRotation()` sorts a copy of each block,
so the total sorting cost for a candidate is at most O(n log n).

Therefore, the overall worst-case time complexity is O(n^2 log n).


Space Complexity:
-----------------
O(n)

The algorithm stores the sorted copy of the array and temporary block
vectors. These require O(n) additional space overall.
*/

class Solution {
public:
    bool isRotation(vector<int>& vec1, vector<int>& vec2) {
        vector<int> temp = vec1;
        sort(temp.begin(), temp.end());
        if (temp != vec2) {
            return false;
        }
        int n = vec1.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (vec1[i] > vec1[(i + 1) % n]) {
                count++;
            }
        }
        return count <= 1;
    }
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        int result = 0;
        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;
            bool valid = true;
            for (int start = 0; start < n; start += k) {
                vector<int> vec1(nums.begin() + start, nums.begin() + start + k);
                vector<int> vec2( sorted.begin() + start, sorted.begin() + start + k);
                if (!isRotation(vec1, vec2)) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                result += k;
            }
        }
        return result;
    }
};
