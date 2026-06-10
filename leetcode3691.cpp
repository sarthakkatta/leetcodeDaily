/*
Problem: Maximum Total Subarray Value II

Approach:
1. Build a Segment Tree:
   - Stores minimum and maximum value for every range.
   - Supports range query:
       get(l, r) → {minimum, maximum}
2. For every starting index l:
   - Consider subarray [l, n-1].
   - Compute:
       diff = max(subarray) - min(subarray)
   - Push into max heap.
3. Max Heap stores:
   - Left index (l)
   - Right index (r)
   - Current difference
4. Repeat k times:
   - Extract subarray with maximum difference.
   - Add its difference to answer.
   - Shrink subarray from right:
       r = r - 1
   - Recompute difference using segment tree.
   - Push updated state back into heap.
5. Return accumulated answer.

Key Idea:
- Segment Tree provides fast min/max queries.
- Priority Queue always selects the currently
  most valuable subarray.

Time Complexity:
- Segment Tree Build : O(N)
- Each Query         : O(log N)
- Heap Operations    : O(K log N)

Overall: O((N + K) log N)

Space Complexity: O(N)
*/

class Solution {
    struct State {
        int l;
        int r;
        long long diff;

        State(int l, int r, long long diff) {
            this->l = l;
            this->r = r;
            this->diff = diff;
        }
    };

    struct Compare {
        bool operator()(const State& a, const State& b) const {
            return a.diff < b.diff; // Max Heap
        }
    };

    class SegmentTree {
        struct Node {
            int s;
            int e;
            int mini;
            int maxi;

            Node* left;
            Node* right;

            Node(int s, int e) {
                this->s = s;
                this->e = e;
                mini = INT_MAX;
                maxi = INT_MIN;
                left = nullptr;
                right = nullptr;
            }
        };

        Node* root;

        Node* build(vector<int>& nums, int s, int e) {
            Node* node = new Node(s, e);

            if (s == e) {
                node->mini = nums[s];
                node->maxi = nums[s];
                return node;
            }

            int mid = (s + e) / 2;

            node->left = build(nums, s, mid);
            node->right = build(nums, mid + 1, e);

            node->mini = min(node->left->mini, node->right->mini);
            node->maxi = max(node->left->maxi, node->right->maxi);

            return node;
        }

        pair<int, int> get(Node* node, int l, int r) {
            if (node == nullptr) {
                return {INT_MAX, INT_MIN};
            }

            if (l <= node->s && node->e <= r) {
                return {node->mini, node->maxi};
            }

            if (node->e < l || r < node->s) {
                return {INT_MAX, INT_MIN};
            }

            auto leftAns = get(node->left, l, r);
            auto rightAns = get(node->right, l, r);

            int mini = min(leftAns.first, rightAns.first);
            int maxi = max(leftAns.second, rightAns.second);

            return {mini, maxi};
        }

    public:
        SegmentTree(vector<int>& nums) {
            root = build(nums, 0, nums.size() - 1);
        }

        pair<int, int> get(int l, int r) {
            return get(root, l, r);
        }
    };

public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();

        SegmentTree seg(nums);

        priority_queue<State, vector<State>, Compare> pq;

        for (int l = 0; l < n; l++) {
            int r = n - 1;

            auto p = seg.get(l, r);

            long long diff = (long long)p.second - p.first;

            pq.push(State(l, r, diff));
        }

        long long sum = 0;

        while (k-- > 0) {
            State cur = pq.top();
            pq.pop();

            sum += cur.diff;

            int l = cur.l;
            int r = cur.r - 1;

            if (l <= r) {
                auto p = seg.get(l, r);

                long long diff = (long long)p.second - p.first;

                pq.push(State(l, r, diff));
            }
        }

        return sum;
    }
};
