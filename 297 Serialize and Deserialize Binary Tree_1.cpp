// 297
// Serialize and Deserialize Binary Tree
// https://leetcode.com//problems/serialize-and-deserialize-binary-tree/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        function<void(TreeNode*)> preOrder = [&](TreeNode* node) {
            if (!ans.empty()) ans.push_back(',');
            ans.append(node ? to_string(node->val) : "#");
            if (!node) return;
            preOrder(node->left);
            preOrder(node->right);
        };
        preOrder(root);
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i = 0;
        function<TreeNode*()> buildFromSeqence = [&]() -> TreeNode* {
            if (i >= data.size()) return nullptr;
            int j = i;
            for (; j < data.size() && data[j] != ','; ++j);
            string val = data.substr(i, j - i);
            i = j + 1;
            if (val == "#") return nullptr;
            auto root = new TreeNode(stoi(val));
            root->left = buildFromSeqence();
            root->right = buildFromSeqence();
            return root;
        };
        return buildFromSeqence();
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));