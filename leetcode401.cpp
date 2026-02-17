/*
Problem: LeetCode 401 – Binary Watch

Approach:
1. Try all possible hours (0–11) and minutes (0–59).
2. Count number of set bits using __builtin_popcount().
3. If total set bits == turnedOn → valid time.
4. Format time properly and store result.
5. Return all valid times.

Time Complexity: O(12 * 60)
Space Complexity: O(1)
*/


class Solution {
public:

    vector<string> readBinaryWatch(int turnedOn) {

        vector<string> res;

        for(int hour = 0; hour < 12; hour++){

            for(int min = 0; min < 60; min++){

                if(__builtin_popcount(hour) +
                   __builtin_popcount(min)
                   == turnedOn){

                    string time =
                        to_string(hour) + ":";

                    if (min < 10) {
                        time += "0";
                    }

                    time += to_string(min);

                    res.push_back(time);
                }
            }
        }

        return res;
    }
};
