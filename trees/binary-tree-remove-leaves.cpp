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
	//	cout<<"Enter left child of "<<temp->data<<" or enter -1"<<endl;
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
	//	cout<<"Enter right child of "<<temp->data<<" or enter -1"<<endl;
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
	{
		cout<<"-1"<<endl;	
		return;
	}	

	queue<BinaryTree*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty())
	{
		BinaryTree* temp=q.front();
		q.pop();

		if(q.empty())
		{
			break;
		}	
		else if(temp==NULL)
		{
			cout<<endl;
			q.push(NULL);
		}	
		else
		{	
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
	}
	cout<<endl;	
}

int height(BinaryTree* root)
{
	if(root==NULL)
		return 0;
	return 1+max(height(root->left),height(root->right));
}
 
void removeLeaves(BinaryTree* root)
{
	if(root==NULL)
	{
		return;
	}	

	if(root->left)
	{
		if( (root->left->left==NULL && root->left->right==NULL) )
		{
			BinaryTree* temp=root->left;
			root->left=NULL;
			delete temp;
		}
	}
			
	if(root->right)
	{	
		if((root->right->left==NULL && root->right->right==NULL))
		{
			BinaryTree* temp=root->right;
			root->right=NULL;
			delete temp;
		}	
	}	

	removeLeaves(root->left);
	removeLeaves(root->right);
} 

 
 
int main()
{
	BinaryTree* root=takeInput();
	if(root->left==NULL && root->right==NULL)
	{
		cout<<"-1"<<endl;
	}
	else
	{	
		removeLeaves(root);
		printTree(root);
	}
	printTree(root);	
	return 0;
}