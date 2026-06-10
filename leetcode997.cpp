/*
Problem: LeetCode 997 – Find the Town Judge

Approach:
1. Create an array `soln` of size n+1.
2. For every trust relationship [a, b]:
   - Person a trusts someone:
       → soln[a]--
   - Person b is trusted:
       → soln[b]++
3. Properties of Town Judge:
   - Trusts nobody.
   - Trusted by all other (n-1) people.
4. Therefore:
   - Judge will have score = n - 1.
5. Traverse score array:
   - If soln[i] == n - 1
       → return i.
6. If no such person exists:
   - Return -1.

Key Idea:
- Outgoing trust decreases score.
- Incoming trust increases score.
- Judge ends up with net score = n - 1.

Time Complexity: O(N + T)
  where T = trust.size()

Space Complexity: O(N)
*/

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> soln(n+1, 0);

        if(n == 1) return 1;

        for(auto n : trust){
            soln[n[0]]--;
            soln[n[1]]++;
        }

        for(int i = 0; i < soln.size(); i++){
            if(soln[i] == n -1){
                return i;
            }
        }

        return -1;
    }
};
