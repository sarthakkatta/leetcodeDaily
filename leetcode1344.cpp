/*
Problem: LeetCode 1344 – Angle Between Hands of a Clock

Approach:
1. Calculate hour hand angle:
   - Each hour contributes 30°.
   - Each minute moves hour hand by 0.5°.
   - hourAngle = (hour % 12) * 30 + minutes * 0.5
2. Calculate minute hand angle:
   - Each minute contributes 6°.
   - minuteAngle = minutes * 6
3. Find absolute difference:
   - diff = |hourAngle - minuteAngle|
4. Return the smaller angle:
   - min(diff, 360 - diff)

Key Idea:
- Clock hands form two angles.
- We need the smaller of the two.

Time Complexity: O(1)
Space Complexity: O(1)
*/

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hourAngle = (hour % 12) * 30 + minutes * 0.5;
        double minuteAngle = minutes * 6;

        double diff = abs(hourAngle - minuteAngle);

        return min(diff, 360.0 - diff);
    }
};
