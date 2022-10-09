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
        string ans="";
        if(!root)return ans;
        return to_string(root->val)+"("+serialize(root->left)+")"+"("+serialize(root->right)+")";
    }

    // Decodes your encoded data to tree.
    TreeNode*decode(string &s,int &i){
        if(i<s.size() and s[i]=='(')i++;
        if(i>=s.size() or s[i]==')')return NULL;
        
        int num=0;
        while(s[i]<='9' and s[i]>='0'){
            num=num*10+(s[i]-'0');
            i++;
        }
        
        TreeNode*root=new TreeNode(num);
        
        root->left=decode(s,i);
        i++;
        root->right=decode(s,i);
        i++;
        return root;
        
    }
    
    TreeNode* deserialize(string data) {
        int i=0;
        return decode(data,i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;