/*
Problem:
---------
LeetCode 2409 - Count Days Spent Together


Approach:
---------
First, we create an array `days` that stores the number of days in each
month. Since the problem uses dates from the same non-leap year, February
has 28 days.

Next, we define a lambda function `totaldays` that converts a date in
"MM-DD" format into its day number within the year.

For example:
    "01-01" -> 1
    "02-01" -> 32
    "03-01" -> 60

Inside `totaldays`:
- Extract the month using `s.substr(0, 2)`.
- Extract the day using `s.substr(3, 2)`.
- Add the number of days in all the months before the given month.

Then, we calculate the beginning of the common period:

    start = max(arriveAlice, arriveBob)

We use `max()` because they can only be together starting when both
people have arrived.

Next, we calculate the end of the common period:

    end = min(leaveAlice, leaveBob)

We use `min()` because the common period ends as soon as either person
leaves.

Finally, the number of overlapping days is:

    end - start + 1

We add 1 because both the starting and ending dates are inclusive.

If there is no overlap, the result is negative or zero, so we use
`max(0, end - start + 1)` to return 0 instead.


Key Idea:
---------
The main idea is to convert all dates into comparable integer day numbers
and then calculate the intersection of the two date intervals.

Alice's interval:
    [arriveAlice, leaveAlice]

Bob's interval:
    [arriveBob, leaveBob]

The common interval is:

    [max(arrival dates), min(leaving dates)]

If the common interval is valid, its length is:

    end - start + 1

Otherwise, the answer is 0.

The `totaldays()` function makes comparing dates easier because we no
longer need to compare month and day separately.


Example:
--------
Input:
arriveAlice = "08-15"
leaveAlice  = "08-18"
arriveBob   = "08-16"
leaveBob    = "08-19"

Step 1: Convert dates into day numbers.

    Alice arrives: 227
    Alice leaves:  230

    Bob arrives:   228
    Bob leaves:    231

Step 2: Find the common interval.

    start = max(227, 228) = 228
    end   = min(230, 231) = 230

Step 3: Calculate the number of overlapping days.

    end - start + 1
    = 230 - 228 + 1
    = 3

Output:
    3

They spend August 16, 17, and 18 together.


Time Complexity:
----------------
O(1)

The date strings have a fixed length, and the lambda function checks at
most 11 preceding months. The number of operations is bounded by a
constant.


Space Complexity:
-----------------
O(1)

The `days` array and all other variables use a constant amount of space.
*/

class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        auto totaldays = [&](string s) {
            int m = stoi(s.substr(0, 2));
            int d = stoi(s.substr(3, 2));
            for (int i = 0; i < m - 1; i++) {
                d += days[i];
            }
            return d;
        };
        int start = max(totaldays(arriveAlice), totaldays(arriveBob));
        int end = min(totaldays(leaveAlice), totaldays(leaveBob));

        return max(0, end - start + 1);
    }
};
