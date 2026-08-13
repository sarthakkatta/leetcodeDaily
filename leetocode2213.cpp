/*
Problem: LeetCode 2213 – Longest Substring of One Repeating Character

Approach:
1. Use a Segment Tree to maintain information about
   consecutive equal characters in every range.
2. Each Segment Tree node stores:
   - pre       → longest same-character prefix
   - suf       → longest same-character suffix
   - maxLen    → longest repeating substring in the range
   - leftChar  → first character of the range
   - rightChar → last character of the range
3. For two child nodes L and R:
   - Combine their prefix and suffix when their
     boundary characters are equal.
   - The longest repeating substring can either be:
       a) Completely inside L
       b) Completely inside R
       c) Crossing the boundary:
            L.suf + R.pre
4. Build the Segment Tree initially from the string.
5. For every query:
   - Change the character at the given index.
   - Update only the path from that index to the root.
6. The root represents the complete string, so:
      segTree[0].maxLen
   gives the longest repeating substring after
   each update.

Key Idea:
- A Segment Tree allows each character update
  to be processed in O(log N).
- The root always contains the answer for the
  entire string.

Node Information:

For a range:
"aaabb"

pre = 3
suf = 2
maxLen = 3
leftChar = 'a'
rightChar = 'b'

Merge:
If L.rightChar == R.leftChar,
the suffix of L and prefix of R can be joined.

Time Complexity:
- Build: O(N)
- Each update: O(log N)
- K queries: O(K log N)

Overall: O(N + K log N)

Space Complexity: O(N)
*/

class Solution {
public:
    struct Node {
        int pre = 0; 
        int suf = 0;
        int maxLen = 0;
        char leftChar = 0;
        char rightChar = 0;
    };

    int n;
    vector<Node> segTree; //segmen tree size 4*n
    Node merge(const Node& L, const Node& R, int leftLen, int rightLen) {
        Node res;
        res.leftChar  = L.leftChar;
        res.rightChar = R.rightChar;

        res.pre = L.pre;
        if (L.pre == leftLen && L.rightChar == R.leftChar) {
            res.pre = L.pre + R.pre;
        }

        res.suf = R.suf;
        if (R.suf == rightLen && L.rightChar == R.leftChar) {
            res.suf = R.suf + L.suf;
        }

        res.maxLen = max(L.maxLen, R.maxLen);
        if (L.rightChar == R.leftChar) {
            res.maxLen = max(res.maxLen, L.suf + R.pre);
        }
        return res;
    }

    void buildSegmentTree(int i, int l, int r, string& s) {
        if (l == r) {
            segTree[i] = { 1, 1, 1, s[l], s[l] };
            return;
        }
        int mid = l + (r - l) / 2;
        buildSegmentTree(2 * i + 1, l, mid, s);
        buildSegmentTree(2 * i + 2, mid + 1, r, s);
        segTree[i] = merge(segTree[2 * i + 1], segTree[2 * i + 2], mid - l + 1, r - mid);
    }

    void update(int i, int l, int r, int pos, char ch) {
        if (l == r) { //l == r == pos
            segTree[i] = { 1, 1, 1, ch, ch };
            return;
        }
        int mid = l + (r - l) / 2;
        if (pos <= mid) {
            update(2 * i + 1, l, mid, pos, ch);
        } else {
            update(2 * i + 2, mid + 1, r, pos, ch);
        }
        segTree[i] = merge(segTree[2 * i + 1], segTree[2 * i + 2], mid - l + 1, r - mid);
    }

    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        n = s.size();
        segTree.assign(4 * n, Node()); //segmen tree size 4*n

        buildSegmentTree(0, 0, n - 1, s);

        int k = queryIndices.size();

        vector<int> result(k);
        for (int i = 0; i < k; i++) {
            int pos = queryIndices[i];
            char ch = queryCharacters[i];
            update(0, 0, n - 1, pos, ch);
            
            result[i] = segTree[0].maxLen; //root node covers entire string
        }
        return result;
    }
};
