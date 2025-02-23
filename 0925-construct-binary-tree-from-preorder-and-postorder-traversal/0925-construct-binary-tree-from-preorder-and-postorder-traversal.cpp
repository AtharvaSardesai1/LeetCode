/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int, int> postIndexMap;
    int preIndex = 0;
    
    TreeNode* constructTree(vector<int>& preorder, vector<int>& postorder, int left, int right) {
        if (left > right || preIndex >= preorder.size()) return nullptr;

        TreeNode* root = new TreeNode(preorder[preIndex++]);

        if (left == right) return root; 

        int leftChildIndex = postIndexMap[preorder[preIndex]]; 

        root->left = constructTree(preorder, postorder, left, leftChildIndex);
        root->right = constructTree(preorder, postorder, leftChildIndex + 1, right - 1);

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        for (int i = 0; i < n; i++) {
            postIndexMap[postorder[i]] = i; 
        }
        return constructTree(preorder, postorder, 0, n - 1);
    }
};

