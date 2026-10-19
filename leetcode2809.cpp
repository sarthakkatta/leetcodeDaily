/*
Problem:
---------
LeetCode 2089 - Find Target Indices After Sorting Array


Approach:
---------
First, we sort the input array in ascending order using `sort()`.

After sorting, we traverse the entire array and compare every element
with the given `target`.

Whenever an element matches the target:
- Its index is added to the result vector `res`.

Since the array is sorted, all occurrences of the target appear together.
Their indices are automatically stored in increasing order.

Finally, we return the result vector containing all target indices.


Key Idea:
---------
The important observation is that the problem asks for the indices of
the target after sorting the array, not its original positions.

For example:

    Original array = [1, 2, 5, 2, 3]

After sorting:

    [1, 2, 2, 3, 5]

If the target is `2`, its indices are:

    1, 2

Therefore, the result is:

    [1, 2]

Sorting places all equal elements together, making it easy to collect
their indices in ascending order.


Example:
--------
Input:
nums = [1, 2, 5, 2, 3]
target = 2

Step 1: Sort the array.

    [1, 2, 2, 3, 5]

Step 2: Traverse the sorted array.

    Index 0 -> 1 != 2
    Index 1 -> 2 == 2 -> Store 1
    Index 2 -> 2 == 2 -> Store 2
    Index 3 -> 3 != 2
    Index 4 -> 5 != 2

Final answer:

    [1, 2]


Time Complexity:
----------------
O(n log n)

Sorting the array takes O(n log n), and traversing it to find the target
indices takes O(n).

Therefore, sorting dominates the overall time complexity.


Space Complexity:
-----------------
O(n) auxiliary space in the worst case for the result vector.

The result vector may store up to n indices if every element equals
the target. The sorting algorithm may also use implementation-dependent
additional space.
*/

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == target){
                res.push_back(i);
            }
        }
        return res;
    }
};
