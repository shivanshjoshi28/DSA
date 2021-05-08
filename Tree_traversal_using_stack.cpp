// C++ program to print inorder traversal 
// using stack. 
#include<bits/stdc++.h> 
#include<stack>
using namespace std; 

/* A binary tree Node has data, pointer to left child 
and a pointer to right child */
struct Node 
{ 
	int data; 
	struct Node* left; 
	struct Node* right; 
	Node (int data) 
	{ 
		this->data = data; 
		left = right = NULL; 
	} 
}; 

/* Iterative function for inorder tree 
traversal */
void inOrder(struct Node *root) 
{ 
	stack<Node *> s; 
	Node *curr = root; 

	while (curr != NULL || s.empty() == false) 
	{ 
		/* Reach the left most Node of the 
		curr Node */
		while (curr != NULL) 
		{ 
			/* place pointer to a tree node on 
			the stack before traversing 
			the node's left subtree */
			s.push(curr); 
			curr = curr->left; 
		} 

		/* Current must be NULL at this point */
		curr = s.top(); 
		s.pop(); 

		cout << curr->data << " "; 

		/* we have visited the node and its 
		left subtree. Now, it's right 
		subtree's turn */
		curr = curr->right; 

	} /* end of while */
} 
void preorder(struct Node * root)
{
    stack<Node *> s;
    s.push(NULL);
    Node * curr=root;
    while(curr!=NULL || s.empty()==false)
    {

        while (curr!=NULL)  // this will take the curr to the leftest node while printing the info through those node.
        {
            cout<<curr->data<<" ";
            if(curr->right!=NULL)
                s.push(curr->right);
            curr=curr->left;
        }
        curr=s.top();
        s.pop();
    }
}


void postOrder(struct Node * initialroot)
{
    struct Node * root=initialroot;
    if (root==NULL)
        return ;

    stack<Node *> s;
    do
    {
        while(root)
        {
            if(root->right)
                s.push(root->right);
            s.push(root);
            root=root->left;
        }

        root=s.top();
        s.pop();
        if(root->right!=NULL and  s.size()!=0 and s.top()==root->right )
        {
            s.pop();
            s.push(root);
            root=root->right;
        }
        else
        {
            cout<<root->data<<" ";
            root=NULL;
        }

    }while(s.empty()==false);
}
/* Driver program to test above functions*/
int main() 
{ 

	/* Constructed binary tree is 
			1 
			/ \ 
		2	 3 
		/ \ 
	4	 5 
	*/
	struct Node *root = new Node(1); 
	root->left	 = new Node(2); 
	root->right	 = new Node(3); 
	root->left->left = new Node(4); 
	root->left->right = new Node(5); 
    cout<<"The inOrder Traversal of tree is : ";
	inOrder(root); 
    cout<<endl;
    cout<<"The PreOrder Traversal of tree is : ";
    preorder(root);
    cout<<endl;
    cout<<"The PostOrder Traversal of tree is : ";
    postOrder(root);
	return 0; 
} 
