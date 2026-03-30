/*
Problem: Check if Strings Can be Made Equal With Operations II

Approach:
1. Count frequency of characters at even and odd indices separately for both strings.
2. If strings can be made equal, their even-indexed characters must match in frequency.
3. Similarly, odd-indexed character frequencies must also match.
4. Compare both frequency arrays to determine the result.

Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<int> even1(26, 0), odd1(26, 0);
        vector<int> even2(26, 0), odd2(26, 0);

        int n = s1.size();
        for(int i = 0; i < n; i++){
            if(i % 2 == 0){
                even1[s1[i] - 'a']++;
                even2[s2[i] - 'a']++;
            }else{
                odd1[s1[i] - 'a']++;
                odd2[s2[i] - 'a']++;
            }
        }
        return (even1 == even2 && odd1 == odd2);
    }
};
