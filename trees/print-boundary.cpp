#include <iostream>
#include <queue>
using namespace std;

class BinaryTree 
{
public:	
	int data;
	BinaryTree* left;
	BinaryTree* right;

	BinaryTree()
	{	
		left=NULL;
		right=NULL;
	}
	~BinaryTree()
	{/*what we want here is that if we delete root,recursively its children get deleted!*/
		if(left)
			delete left;
		if(right)
			delete right;
	}
};


BinaryTree* takeInput()
{
	BinaryTree* root=new BinaryTree;
	int data;
	//cout<<"Enter the root's data"<<endl;
	cin>>data;

	root->data=data;
	queue<BinaryTree*> q;
	q.push(root);

	while(!q.empty())
	{
		BinaryTree* temp=q.front();
		q.pop();
		//cout<<"Enter left child of "<<temp->data<<" or enter -1"<<endl;
		int leftData;
		cin>>leftData;

		if(leftData!=-1)
		{
			temp->left=new BinaryTree;
			temp->left->data=leftData;
			q.push(temp->left);

		}	
		else
		{
			temp->left=NULL;
		}	
		//cout<<"Enter right child of "<<temp->data<<" or enter -1"<<endl;
		int rightData;
		cin>>rightData;

		if(rightData!=-1)
		{
			temp->right=new BinaryTree;
			temp->right->data=rightData;
			q.push(temp->right);
		}	
		else
		{
			temp->right=NULL;
		}	
	}

	return root;	
}


void printTree(BinaryTree* root)
{
	if(root==NULL)
		return;
	queue<BinaryTree*> q;
	q.push(root);

	while(!q.empty())
	{
		BinaryTree* temp=q.front();
		q.pop();
		cout<<temp->data<<" ";
		if(temp->left)
		{
			q.push(temp->left);
		}	

		if(temp->right)
		{
			q.push(temp->right);
		}	
	}	
	cout<<endl;
}

int height(BinaryTree* root)
{
	if(root==NULL)
		return 0;
	return 1+max(height(root->left),height(root->right));
}
 

void printBoundaryLeft(BinaryTree* root)
{
	if (root==NULL)
	{
		return;
	}

	if (root->left)
	{
		cout<<root->data<<" ";
	    printBoundaryLeft(root->left);
	}
	else if (root->right)
	{
		cout<<root->data<<" ";
		printBoundaryLeft(root->right);	
	}	
	
} 

void printLeaves(BinaryTree* root)
{
	if (root==NULL)
	{
		return;
	}

	if (root->left==NULL && root->right==NULL)
	{
		cout<<root->data<<" ";
	}
	
	printLeaves(root->left);
  	printLeaves(root->right);
}


void printBoundaryRight(BinaryTree* root)
{
	if (root==NULL)
	{
		return;
	}

	if (root->right)
	{
		printBoundaryRight(root->right);
		 cout<<root->data<<" ";
	}
	else if(root->left)
	{
		printBoundaryRight(root->left);
		 cout<<root->data<<" ";
	}
	
}

void boundaryTraversal(BinaryTree* root)
{
	if (root)
	{
		printBoundaryLeft(root);
		printLeaves(root);
		printBoundaryRight(root->right);
	}
}

int main()
{
	BinaryTree* root=takeInput();
	//printTree(root);
	//printBoundaryRight(root); 
	//printLeaves(root->left);
	boundaryTraversal(root);
	return 0;
}