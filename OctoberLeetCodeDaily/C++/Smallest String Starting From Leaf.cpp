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
    vector<string>ans;
    void makeStr(TreeNode*root,string temp){
        if(!root)
            return;
        temp.push_back('a'+root->val);
        makeStr(root->left,temp);
        makeStr(root->right,temp);
        if(!root->left&&!root->right){
            string temp2=temp;
            reverse(temp2.begin(),temp2.end());
            ans.push_back(temp2);
        }
    }
    string smallestFromLeaf(TreeNode* root) {
        makeStr(root,"");
        sort(ans.begin(),ans.end());
        return ans[0];
    }
};
