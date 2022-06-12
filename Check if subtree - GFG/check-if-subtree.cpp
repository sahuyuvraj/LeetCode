// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution
{
  public:
    //Function to check if S is a subtree of tree T.
    // void mapping(Node*root,unordered_map<int,int>&mp){
    //     if(!root)return;
    //     mp[root->data]++;
    //     mapping(root->left,mp);
    //     mapping(root->right,mp);
    // }
    
    // bool check(Node*root,unordered_map<int,int>&mp){
    //     if(!root)return true;
    //     if(!mp[root->data])return false;
    //     mp[root->data]--;
    //     return check(root->left,mp) and check(root->right,mp);
    // }
    
    bool isSub(Node*T,Node*S){
        if(!S and !T)return true;
        if(!S or !T)return false;
        return (T->data==S->data) 
            and isSub(T->left,S->left) 
            and isSub(T->right,S->right);
    }
    
    bool isSubTree(Node* T, Node* S) 
    {
        // Your code here
        if(!S)return true;
        if(!T)return false;
        if(isSub(T,S))return true;
        return isSubTree(T->left,S) or isSubTree(T->right,S);
        
        // unordered_map<int,int>mp;
        // mapping(T,mp);
        // return check(S,mp);
    }
}; 
// 10 4 6 N 30 2
// 10 4 6 N 30

// { Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string strT, strS;
        getline(cin, strT);
        Node *rootT = buildTree(strT);
        getline(cin, strS);
        Solution obj;
        Node *rootS = buildTree(strS);
        cout << obj.isSubTree(rootT, rootS) << "\n";

    }
    return 0;
}  // } Driver Code Ends