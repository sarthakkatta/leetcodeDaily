/*
Problem: 3876. Construct Uniform Parity Array II

Approach:
---------
1. Count the number of odd elements in the array.

2. If there are no odd elements:
   - The array is already completely EVEN.
   - So return true.

3. Find the smallest element of the array.

4. If the smallest element is ODD:
   - Any even number can subtract this smaller odd number.
   - EVEN - ODD = ODD.
   - Therefore, we can convert every even element into an odd element.
   - So the entire array can become ODD.
   - Return true.

5. If the smallest element is EVEN and there is at least one odd:
   - The smallest element cannot become ODD because there is no smaller
     odd element available to subtract from it.
   - Therefore, this smallest even element will always remain even.
   - Since there is already an odd element, making the entire array
     uniform is impossible.
   - Return false.

Key Idea:
---------
The smallest element is the deciding factor.

- If the smallest element is ODD, we can make all elements ODD.
- If the smallest element is EVEN and any odd element exists, we cannot
  make all elements have the same parity.
- If there are no odd elements, the array is already all EVEN.

Example:
--------
nums1 = [4, 7, 10]

oddCount = 1
smallest = 4 (EVEN)

Since the smallest element is even and an odd element exists,
the smallest element cannot be changed into odd.

Therefore, the array cannot become uniform.
Answer = false.

Example 2:
----------
nums1 = [3, 6, 10]

smallest = 3 (ODD)

We can use 3 to change:
6 - 3 = 3  -> ODD
10 - 3 = 7 -> ODD

So all elements can become ODD.
Answer = true.

Time Complexity:
----------------
O(n), because we traverse the array once to count odd elements
and use min_element(), which also takes O(n).

Space Complexity:
-----------------
O(1), because only a few integer variables are used.
*/

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int oddCount = 0;
        for (int x : nums1) {
            if (x % 2 == 1)
                oddCount++;
        }
        // Already all even
        if (oddCount == 0)
            return true;

        // If smallest element is odd,
        // every even number can subtract it and become odd.
        int smallest = *min_element(nums1.begin(), nums1.end());

        if (smallest % 2 == 1)
            return true;

        // Smallest is even and there is at least one odd.
        // That smallest even number cannot become odd,
        // because there is no smaller odd number.
        return false;
    }
};
