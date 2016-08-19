// 103
// Binary Tree Zigzag Level Order Traversal
// https://leetcode.com//problems/binary-tree-zigzag-level-order-traversal/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        if(!root) return vector<vector<int>>();
        vector<vector<int> > ret;
        vector<int> lv;
        vector<TreeNode*> q;
        q.push_back(root);
        TreeNode * endOfLevel= root;
        int level =0;
        while(!q.empty())
        {
            TreeNode* root = q.front();
            q.erase(q.begin());
            lv.push_back(root->val);
            
            if(root->left)
                q.push_back(root->left);
            if(root->right)
                q.push_back(root->right);
            
           
            if(root==endOfLevel)
            {
                level++;
                endOfLevel=q.back();
                if((level&1)==0)
                    reverse(lv);
                ret.push_back(lv);  
                lv.clear();
            }
        }
        return ret;
    }
    void reverse(vector<int> &v)
    {
        int i= 0, j=v.size()-1;
        while(i<j)
        {
            swap(v[i],v[j]);
            i++;
            j--;
        }
    }
};