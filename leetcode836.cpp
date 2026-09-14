/*
Problem:
---------
LeetCode 836 - Rectangle Overlap

Approach:
---------
1. Check whether the two rectangles are completely separated.

2. There are four possible ways in which the rectangles do NOT overlap:
   - rec1 is completely to the left of rec2.
   - rec2 is completely to the left of rec1.
   - rec1 is completely below rec2.
   - rec2 is completely below rec1.

3. Check these conditions using the rectangle coordinates:
   - `rec[0]` -> left x-coordinate
   - `rec[1]` -> bottom y-coordinate
   - `rec[2]` -> right x-coordinate
   - `rec[3]` -> top y-coordinate

4. If any separation condition is true:
   - The rectangles do not overlap.
   - Return false.

5. If none of the separation conditions is true:
   - The rectangles must have a positive-area overlap.
   - Return true.

Key Idea:
---------
Instead of directly checking whether the rectangles overlap, we check
when they DON'T overlap.

Two rectangles do not overlap if:

    rec1 right <= rec2 left
    OR
    rec2 right <= rec1 left
    OR
    rec1 top <= rec2 bottom
    OR
    rec2 top <= rec1 bottom

The `<=` is important.

If one rectangle's edge is exactly touching the other rectangle's edge,
there is no overlapping area, so the answer should be false.

Example:
--------
rec1 = [0, 0, 2, 2]
rec2 = [1, 1, 3, 3]

Coordinates:

    rec1: left=0, bottom=0, right=2, top=2
    rec2: left=1, bottom=1, right=3, top=3

None of the four separation conditions is true.

Therefore, the rectangles have a positive-area intersection.

Answer = true.

Example 2:
----------
rec1 = [0, 0, 2, 2]
rec2 = [2, 0, 4, 2]

Here:

    rec1 right = 2
    rec2 left  = 2

Since:

    rec1[2] <= rec2[0]

is true, the rectangles only touch at their boundary.

There is no overlapping area.

Answer = false.

Time Complexity:
----------------
O(1)

Only four constant-time comparisons are performed.

Space Complexity:
-----------------
O(1)

No extra data structures are used.
*/

class Solution { 
public: 
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) { 
        if (rec1[2] <= rec2[0] ||   // rec1 completely left 
            rec2[2] <= rec1[0] ||   // rec2 completely left 
            rec1[3] <= rec2[1] ||   // rec1 completely below 
            rec2[3] <= rec1[1])     // rec2 completely below 
            return false; 
 
        return true; 
    } 
};
