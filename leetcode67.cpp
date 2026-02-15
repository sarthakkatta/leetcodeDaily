/*
Problem: LeetCode 67 – Add Binary

Approach:
1. Traverse both strings from right to left.
2. Add digits along with carry.
3. Store (sum % 2) as result digit.
4. Update carry = sum / 2.
5. Reverse result at end.

Time Complexity: O(N)
Space Complexity: O(N)
*/


class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        string res = "";
        while(i >= 0 || j >= 0 || carry){
            int sum = carry;
            if(i >= 0){
                sum += a[i] - '0';
                i--;
            }
            if(j >= 0){
                sum += b[j] - '0';
                j--;
            }

            res += (sum % 2) + '0';
            carry = sum / 2;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
