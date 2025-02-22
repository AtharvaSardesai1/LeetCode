/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        stack<TreeNode*> st;
        int i = 0, n = traversal.size();

        while (i < n) {
            // Step 1: Determine depth by counting dashes
            int depth = 0;
            while (i < n && traversal[i] == '-') {
                depth++;
                i++;
            }

            // Step 2: Read the node value
            int value = 0;
            while (i < n && isdigit(traversal[i])) {
                value = value * 10 + (traversal[i] - '0');
                i++;
            }

            // Step 3: Create a new node
            TreeNode* node = new TreeNode(value);

            // Step 4: Adjust the stack to the correct depth
            while (st.size() > depth) {
                st.pop();
            }

            // Step 5: Attach the node as a left or right child
            if (!st.empty()) {
                if (!st.top()->left)
                    st.top()->left = node;
                else
                    st.top()->right = node;
            }

            // Step 6: Push the new node onto the stack
            st.push(node);
        }

        // The root node is at the bottom of the stack
        while (st.size() > 1) {
            st.pop();
        }
        return st.top();
    }
};
