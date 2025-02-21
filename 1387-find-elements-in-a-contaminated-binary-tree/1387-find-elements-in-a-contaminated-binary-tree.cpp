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
class FindElements {
    unordered_set<int> node_count;

    void recoverBinaryTree(TreeNode*curr, int val){
        if(curr==NULL) return;

        node_count.insert(val);
        recoverBinaryTree(curr->left, 2*val+1);
        recoverBinaryTree(curr->right, 2*val+2);
    }

public:
    FindElements(TreeNode* root) {
        node_count.insert(0);
        recoverBinaryTree(root->left, 1);
        recoverBinaryTree(root->right,2);
    }
    
    bool find(int target) {
        return node_count.count(target)>0;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */