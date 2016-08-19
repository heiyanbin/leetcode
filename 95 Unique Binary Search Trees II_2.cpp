// 95
// Unique Binary Search Trees II
// https://leetcode.com//problems/unique-binary-search-trees-ii/
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
    vector<TreeNode *> generateTrees(int n) {
        vector<TreeNode*> v;
        if(n<=0) 
        {
            v.push_back(NULL);
            return v;
        }
        if(n==1)
        {
            v.push_back(new TreeNode(1));
            return v;
        }
        TreeNode *root = new TreeNode(1);
        root->right = new TreeNode(2);
        v.push_back(root);
        root = new TreeNode(2);
        root->left = new TreeNode(1);
        v.push_back(root);
        vector<TreeNode*> v2;
        for(int i=3;i<=n;i++)
        {
            for(int j=0;j<v.size();j++)
            {
                root = clone(v[j]);
                TreeNode *newRoot = new TreeNode(i);
                newRoot->left = root;
                v2.push_back(newRoot);
                
                TreeNode* p= v[j];
                while(p)
                {
                    newRoot = clone(v[j]);
                    TreeNode* q = newRoot;
                    while(q->val!=p->val)
                        q= q->right;
                    TreeNode* insert= new TreeNode(i);
                    insert->left=q->right;
                    q->right=insert;
                    v2.push_back(newRoot);
                    p=p->right;
                }
            }
            
            for(int j=0;j<v.size();j++)
            {
                removeTree(v[j]);
            }
            v=v2;
            v2.clear();
        }
        return v;
    }
    
    TreeNode* clone(TreeNode* root)
    {
        if(!root) return NULL;
        TreeNode * root2 = new TreeNode(root->val);
        root2->left=clone(root->left);
        root2->right=clone(root->right);
        return root2;
    }
    void insertBST(TreeNode * root, int val)
    {
        assert(root);
        while(root)
        {
            if(val< root->val)
            {
                if(root->left)
                    root=root->left;
                else
                {   
                    root->left = new TreeNode(val);
                    break;
                }
            }
            else
            {
                if(root->right)
                    root=root->right;
                else
                {    
                    root->right = new TreeNode(val);
                    break;
                }
            }
        }
    }
    void removeTree(TreeNode* root)
    {
        if(!root) return;
        TreeNode* left= root->left, *right = root->right;
        delete root;
        removeTree(left);
        removeTree(right);
    }
};