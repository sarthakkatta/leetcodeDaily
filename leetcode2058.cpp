/*
Problem: LeetCode 2058 – Find the Minimum and Maximum Number of Nodes Between Critical Points

Approach:
1. A critical point woh node hai jo apne previous aur next
   node dono se either:
   - strictly greater ho (local maximum), or
   - strictly smaller ho (local minimum).
2. Linked List ko traverse karte hue har middle node ko check
   karte hain.
3. `idx` current node ka index maintain karta hai.
4. Jab pehla critical point milta hai:
   - `first` mein uska index store karte hain.
   - `last` bhi usi index par set karte hain.
5. Har next critical point ke liye:
   - Current index aur previous critical point ke index
     ka difference minimum distance ho sakta hai.
   - Isliye:
        minDist = min(minDist, idx - last)
   - Phir `last = idx` update karte hain.
6. Traversal ke end mein:
   - Agar sirf ek critical point mila hai,
     to minimum aur maximum distance possible nahi hai.
     Return {-1, -1}.
7. Otherwise:
   - Minimum distance = `minDist`
   - Maximum distance = first aur last critical point ke
     beech ka distance:
        last - first

Key Idea:
- Minimum distance ke liye sirf consecutive critical points
  ke beech ka distance check karna enough hai.
- Maximum distance hamesha first critical point aur
  last critical point ke beech hota hai.

Critical Point Example:

Linked List:
1 → 3 → 2 → 2 → 3 → 2

Indices:
0    1    2    3    4    5

Index 1:
3 > 1 and 3 > 2
→ Local maximum → Critical Point

Index 4:
3 > 2 and 3 > 2
→ Local maximum → Critical Point

Critical Points:
1, 4

Minimum distance:
4 - 1 = 3

Maximum distance:
4 - 1 = 3

Answer:
[3, 3]

Variables:

first:
- First critical point ka index.

last:
- Most recent critical point ka index.

minDist:
- Consecutive critical points ke beech minimum distance.

idx:
- Current node ka index.

Time Complexity: O(N)

Space Complexity: O(1)
*/
