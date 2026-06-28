/*
Problem: LeetCode 1846 – Maximum Element After Decreasing and Rearranging

Approach:
1. Sort the array in non-decreasing order.
2. Set the first element to 1:
   - arr[0] = 1
3. Traverse the remaining elements:
   - The difference between adjacent elements
     must not exceed 1.
   - Make current element:
       min(arr[i], arr[i - 1] + 1)
4. This ensures:
   - arr[0] = 1
   - |arr[i] - arr[i-1]| <= 1
   - Maximum possible values are preserved.
5. The last element becomes the maximum
   achievable element.
6. Return arr.back().

Key Idea:
- After sorting, greedily keep each element
  as large as possible while maintaining
  the valid adjacent difference constraint.

Example:
arr = [2,2,1,2,1]

After sort:
[1,1,2,2,2]

Set first = 1:
[1,1,2,2,2]

Process:
[1,1,2,2,2]

Answer = 2

Time Complexity: O(N log N)
Space Complexity: O(1)
*/

// class Solution {
// public:
//     int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
//         int n = arr.size();
//         int maxi = INT_MIN;
//         sort(arr.begin(), arr.end());
//         arr[0] = 1;
//         for(int i = 1; i < n; i++){
//             if(arr[i] - arr[i - 1] <= 1){
//                 continue;
//             }else{
//                 arr[i] = arr[i - 1] + 1;
//             }
//         }
//         for(int i = 0; i < n; i++){
//             maxi = max(maxi, arr[i]);
//         }
//         return maxi;
//     }
// };

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        arr[0] = 1;

        for(int i = 1; i < arr.size(); i++) {
            arr[i] = min(arr[i], arr[i - 1] + 1);
        }

        return arr.back();
    }
};
