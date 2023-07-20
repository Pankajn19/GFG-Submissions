//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
     Node* reverse(Node* head){
      if(!head || !head->next) return head;
      Node* rest = reverse(head->next);
      head->next->next = head;
      head->next = NULL;
      return rest;
    }
    Node *compute(Node *head)
    {
        if(!head->next) return head;
        Node* rev = reverse(head);
      int maxi = rev->data;
      Node* temp1  = rev;
      Node* temp2 = rev->next;
      while(temp2 && temp2->next){
        if(temp2->data<maxi) temp1->next = temp2->next;
        else temp1 = temp1->next;
        temp2 = temp2->next;
        maxi = max(maxi , temp1->data);
      }
      if(temp2->data<maxi) temp1->next = NULL;
      Node* x = reverse(rev);
      return x;
    }
    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends