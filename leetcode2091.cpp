/*
Problem: LeetCode 2091 – Removing Minimum and Maximum From Array

Approach:
1. First find the indices of the minimum and maximum elements.
2. Let:
   - minidx = index of minimum element
   - maxidx = index of maximum element
3. Arrange their positions:
   - left = smaller index
   - right = larger index
4. To remove both elements, there are 3 possible ways:
   - Remove both from the front.
   - Remove both from the back.
   - Remove one from the front and the other from the back.
5. Calculate the number of deletions for all 3 cases:
   - `front = right + 1`
     → Remove everything from index 0 to right.
   - `back = n - left`
     → Remove everything from left to n-1.
   - `both = (left + 1) + (n - right)`
     → Remove left part up to `left` and right part
       starting from `right`.
6. Return the minimum among these three possibilities.

Key Idea:
- Minimum and maximum can be removed from either end
  of the array.
- We only need to consider the 3 possible strategies
  that remove both elements.
- Choose the strategy requiring the fewest deletions.

Example:

nums = [2, 10, 7, 5, 4, 1, 8, 6]

Minimum = 1 → index 5
Maximum = 10 → index 1

left = 1
right = 5

front = 5 + 1 = 6
back = 8 - 1 = 7
both = (1 + 1) + (8 - 5) = 5

Minimum = 5

Answer:
5

Time Complexity: O(N)

Space Complexity: O(1)
*/

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minidx = 0, maxidx = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] < nums[minidx])
                minidx = i;

            if(nums[i] > nums[maxidx])
                maxidx = i;
        }
        int left = min(minidx, maxidx);
        int right = max(minidx, maxidx);

        int front = right + 1;
        int back = n - left;
        int both = (left + 1) + (n - right);
        return min({front, back, both});
    }
};
