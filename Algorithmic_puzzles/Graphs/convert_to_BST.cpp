#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node* next;
	Node(int x):data(x), next(NULL) {}  //initializer list
};

class BST_Node
{
public:
	int data;
	BST_Node* left;
	BST_Node* right;
	BST_Node(int x)
	{
		data = x;
		left = right = NULL;
	}
};

void print_list(Node* head)
{
	Node* temp = head;
	while(temp)
	{
		cout << temp -> data << " ";
		temp = temp -> next;
	}
	cout << endl;
}


BST_Node* convert_to_BST(Node* head, int start, int end)
{
	if(start > end) return NULL;

	int mid = start + (end - start)/2;
	if((end - start)%2) mid += 1;

	Node* temp = head;
	int count = 0;

	while(temp && count!=mid)
	{
		temp = temp -> next;
		count++;
	}

	BST_Node* root = new BST_Node(temp->data);
	root -> left = convert_to_BST(head, 0, mid-1);
	root -> right = convert_to_BST(temp -> next, 0, end - (mid+1));
	return root;
}

/* ver2
BST_Node* convert_to_BST(Node** head, int n) //leaf to root
{
	if(n<=0) return NULL;

	BST_Node* left = convert_to_BST(head, n/2);

	BST_Node* root = new BST_Node((*head) -> data);
	(*head) = (*head)->next;

	root->left = left;

	root-> right = convert_to_BST(head, n-(n/2)-1);
}
*/
void inorder_util(const BST_Node* root)
{
	if(root != NULL)
	{
		inorder_util(root -> left);
		cout << root -> data << " ";
		inorder_util(root -> right);
	}
}

void inorder(const BST_Node* root)
{
	inorder_util(root);
	cout << endl;
}
int main()
{
	Node* head = new Node(7);
	head -> next = new Node(10);
	head -> next -> next= new Node(12);
	head -> next -> next -> next= new Node(14);
	// head -> next -> next -> next -> next= new Node(20);

	int len = 4;
	BST_Node* root = convert_to_BST(head, 0, len-1);

	inorder(root);
}