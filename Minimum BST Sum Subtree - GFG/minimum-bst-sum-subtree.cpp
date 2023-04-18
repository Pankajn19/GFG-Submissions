//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }

    Node *buildTree(string s) {
        if (s.length() == 0 || s[0] == 'N') return NULL;

        // Create the root of the tree
        vector<string> str;
        istringstream iss(s);
        for (string s; iss >> s;) str.push_back(s);
        Node *root = new Node(stoi(str[0]));

        // Push the root to the queue
        queue<Node*> q;
        q.push(root);

        // Starting from the second element
        int i = 1;
        while (q.size() > 0 && i < str.size()) {

            // Get and remove the front of the queue
            Node *currNode = q.front();
            q.pop();

            // Get the current node's value from the string
            string currVal = str[i];

            // If the left child is not null
            if (currVal != "N") {

                // Create the left child for the current node
                currNode->left = new Node(stoi(currVal));
                // Push it to the queue
                q.push(currNode->left);
            }

            // For the right child
            i++;
            if (i >= str.size()) break;

            currVal = str[i];

            // If the right child is not null
            if (currVal != "N") {

                // Create the right child for the current node
                currNode->right = new Node(stoi(currVal));

                // Push it to the queue
                q.push(currNode->right);
            }
            i++;
        }

        return root;
    }

    void inorder(Node *root) {
        if (root == NULL) return;
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
};


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int sum(Node* root){
        if(!root) return 0;
        return root->data + sum(root->left) + sum(root->right);
    }
    int len(Node* root){
        if(!root) return 0;
        return 1 + len(root->left) + len(root->right);
    }
    void final(Node* root, int& ans,int target){
        if(!root) return;
        if(sum(root)==target && isbst(root)) ans = min(ans,len(root));
        final(root->left,ans,target);
        final(root->right,ans,target);
        
    }
    bool isvalid(Node* root, int x, int y){
        if(!root) return true;
        if(root->data<=x || root->data>=y) return false;
        return isvalid(root->left,x,root->data) && isvalid(root->right,root->data,y);
        
    }
    bool isbst(Node* root){
        int x = INT_MIN;
        int y = INT_MAX;
        if(!root) return true;
        return isvalid(root,x,y);
    }
    
    int minSubtreeSumBST(int target, Node *root) {
        int ans = INT_MAX;
        final(root,ans,target);
        if(ans==INT_MAX) return -1;
        return ans;
        
        
    }
};

//{ Driver Code Starts.


int main(){
    
    int t;
    cin>>t;
    while(t--){
        int target;
        cin>>target;
        string str;
        getline(cin,str);
        getline(cin,str);
        Node node(0);
        Node *root = node.buildTree(str);
        Solution ob;
        int res = ob.minSubtreeSumBST(target, root);
        cout<<res<<endl;
    }
    return 0;
}
// } Driver Code Ends