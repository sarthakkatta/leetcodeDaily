/*
Problem:
---------
LeetCode 3727. Maximum Alternating Sum of Squares


Approach:
---------
First, we square every element of the input array and store the squared
values back in `nums`.

Then, we sort the array in ascending order so that we can easily access
the smallest and largest squared values.

We use two pointers:
- `i` points to the smallest remaining element.
- `j` points to the largest remaining element.

While `i < j`, we add the largest element to `ans` first, followed by
the smallest element. This creates an alternating arrangement of large
and small values.

After adding both elements:
- Decrease `j` to move away from the largest element.
- Increase `i` to move away from the smallest element.

If the array has an odd number of elements, the middle element remains
after the two-pointer loop. We add it separately to `ans`.

Finally, we calculate the alternating sum:
- Add elements at even indices.
- Subtract elements at odd indices.

The resulting sum is returned.


Key Idea:
---------
The main idea is to maximize the alternating sum by arranging larger
squared values at positions that are added and smaller squared values
at positions that are subtracted.

For example, an arrangement like:

    [largest, smallest, second_largest, second_smallest, ...]

places large values at even indices and small values at odd indices.

The alternating sum is calculated as:

    ans[0] - ans[1] + ans[2] - ans[3] + ...

The two-pointer approach builds this alternating arrangement by
repeatedly selecting the largest and smallest remaining elements.

Note:
This explanation describes the strategy implemented by your code.
However, the greedy arrangement is not guaranteed to produce the
maximum alternating sum for every possible input.


Example:
--------
Input:
nums = [1, 2, 3]

Step 1: Square every element.

    [1, 4, 9]

Step 2: Sort the array.

    [1, 4, 9]

Step 3: Build the alternating arrangement.

    Take 9, then 1.
    The middle element 4 remains.

    ans = [9, 1, 4]

Step 4: Calculate the alternating sum.

    9 - 1 + 4 = 12

Output:
    12


Time Complexity:
----------------
O(n log n)

Squaring the elements takes O(n), sorting takes O(n log n), and building
and evaluating the resulting arrangement take O(n).


Space Complexity:
-----------------
O(n)

The `ans` vector stores the rearranged squared values. The sorting
algorithm may also use additional implementation-dependent space.
*/

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long n = nums.size(), sum = 0, i = 0, j = n - 1;
        for(int i = 0; i < n; i++){
            nums[i] = nums[i] * nums[i];
        }
        sort(nums.begin(), nums.end());
        vector<long long> ans;
        while(i < j){
            if(i == j) {
                ans.push_back(nums[i]);
                break;
            }
            ans.push_back(nums[j]);
            ans.push_back(nums[i]);
            j--;i++;
        }
        if(n % 2 != 0) ans.push_back(nums[n/2]); //agr n even h upar waala logic se aasaani se ho jaaega pr agr odd h j-- and i++ se ek beech ka rehe jaaega isliye uske liye yeh check h
        for(int i =0; i < ans.size(); i++){
            if(i % 2 == 0) sum += ans[i];
            else sum -= ans[i];
        } 
        return sum;
    }
};
