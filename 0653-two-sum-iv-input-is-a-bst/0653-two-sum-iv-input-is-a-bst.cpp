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
   void inorder(TreeNode*root, vector<int> &store){
        
        if(root==NULL) return;
        inorder(root-> left, store);
        store.push_back(root-> val);
        inorder(root-> right, store);
    }
    
    
    bool findTarget(TreeNode* root, int k) {
        vector<int> store; 
        inorder(root, store);
        
        int left =0;
        int right = store.size()-1;
        
        while(left<right){
            if(store[left]+store[right]>k)
                right--;
            else if(store[left]+store[right]<k)
                left++;
            else
                return true;
        }
        return false;
    }
};