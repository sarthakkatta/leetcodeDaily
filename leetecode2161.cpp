/*
Problem: LeetCode 2161 – Partition Array According to Given Pivot

Approach:
1. Create three separate arrays:
   - small → elements less than pivot
   - equal → elements equal to pivot
   - large → elements greater than pivot
2. Traverse the original array:
   - Place each element into its appropriate group.
3. Create answer array.
4. Append:
   - all elements from small
   - all elements from equal
   - all elements from large
5. Return final partitioned array.

Key Idea:
- Maintain relative ordering within each group
  while partitioning around the pivot.

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> small;
        vector<int> equal;
        vector<int> large;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < pivot){
                small.push_back(nums[i]);
            }else if(nums[i] == pivot){
                equal.push_back(nums[i]);
            }else{
                large.push_back(nums[i]);
            }
        }

        vector<int> ans;

        for(int n : small){
            ans.push_back(n);
        }

        for(int n : equal){
            ans.push_back(n);
        }

        for(int n : large){
            ans.push_back(n);
        }

        return ans;
    }
};
