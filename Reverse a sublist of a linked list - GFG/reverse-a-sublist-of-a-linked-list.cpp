// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};


 // } Driver Code Ends
//User function Template for C++

/*Link list node 
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

class Solution
{
    public:
    Node* reverseBetween(Node* head, int m, int n)
    {
        //code here
        if(!head or m==n)return head;
        
        int count=0;
        Node*temp=head,*ptr1=NULL,*ptr2=NULL;
    
        while(temp){
            count++;
            if(count==m-1)ptr1=temp;
            if(count==n+1)ptr2=temp;
            temp=temp->next;
        }
        
       Node*prev=NULL,*curr,*nextnode,*tmp;
       if(ptr1)curr=ptr1->next;
       else curr=head;  //m==head
       tmp=curr;
       
       while(curr!=ptr2){
           nextnode=curr->next;
           curr->next=prev;
           prev=curr;
           curr=nextnode;
       }       
       
       if(!ptr1 and !ptr2)return prev;
       else if(!ptr1){
           tmp->next=ptr2;
           return prev;
       }
       
       ptr1->next=prev;
       tmp->next=ptr2;
       
       return head;
    }
};

// { Driver Code Starts.

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}



// Driver program to test above functions
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int N, m, n;
		cin >> N>>m>>n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < N; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

		

        Solution ob;

		Node* newhead = ob.reverseBetween(head, m, n);
		printList(newhead);

		cout << "\n";



	}
	return 0;
}
  // } Driver Code Ends