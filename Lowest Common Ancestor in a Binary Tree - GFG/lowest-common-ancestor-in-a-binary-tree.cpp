//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(){
        data = 0;
        left = right = NULL;
    }
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

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
      unordered_map<Node*, Node*> mp;
      
    void nodeMap(Node* root){
      if(!root) return;
      if(root->left) mp[root->left]  = root;
      if(root->right) mp[root->right] = root;
      nodeMap(root->left);
      nodeMap(root->right);
    }
    
    
    void find(int n, Node* temp, Node*& p){
        if(!temp) return;
        if(temp->data==n){
            p = temp;
            return;
        } 
        find(n,temp->left,p);
        find(n,temp->right,p);
    }
    
    
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       Node* q,*p;
       find(n1,root,p);
       find(n2,root,q);
       nodeMap(root);
      unordered_set<Node*> st1,st2;
       Node* temp1 = p, *temp2 = q;
       while(temp1!=root){
        st1.insert(temp1);
        temp1 = mp[temp1];
      } 

      while(temp2!=root){
        st2.insert(temp2);
        temp2 = mp[temp2];
      }    
      while(p!=root){
        if(st2.find(p)!=st2.end()) return p;
        p = mp[p];
      }
      while(q!=root){
        if(st1.find(q)!=st1.end()) return q;
        q = mp[q];
      }
      return root;
       
    }
};


//{ Driver Code Starts.

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // for(string i:ip)
    //     cout<<i<<" ";
    // cout<<endl;
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// Function for Inorder Traversal
void printInorder(Node* root)
{
    if(!root)
        return;

    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b;
        scanf("%d %d ",&a,&b);
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        Solution ob;
        cout<<ob.lca(root,a,b)->data<<endl;
    }
    return 0;
}

// } Driver Code Ends