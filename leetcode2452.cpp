/*
Problem: LeetCode 2452 – Words Within Two Edits of Dictionary

Approach:
1. For each query word:
   - Compare it with every word in the dictionary.
2. Count character differences between query and dictionary word:
   - If difference > 2 → stop checking that pair.
3. If any dictionary word has ≤ 2 differences:
   - Add query word to result and break.
4. Return all such query words.

Key Idea:
- Early stopping when differences exceed 2 improves efficiency.

Time Complexity: O(Q * D * L)
  (Q = queries, D = dictionary size, L = word length)
Space Complexity: O(1) (excluding output)
*/

class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        for(string &q : queries){
            for(string &d : dictionary){
                int diff = 0;
                for(int i=0;i<q.size();i++){
                    if(q[i] != d[i]) diff++;
                    if(diff > 2) break;
                }
                if(diff <= 2){
                    ans.push_back(q);
                    break;
                }
            }
        }
        return ans;
    }
};
