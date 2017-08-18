// rbtree.cpp 

#include <iostream>
#include <iomanip>
#include "rbtree.h"

using std::cout;
using std::setw;
using std::endl;

/**************************************************
Description:- Given Print function
input:- NA
output:-NA

***************************/
void RBTree::reverseInOrderPrint(Node *x, int depth) {
   if ( x != nil ) {
      reverseInOrderPrint(x->right, depth+1);
      cout << setw(depth*4+4) << x->color << " ";
      cout << *(x->key) << " " << *(x->value) << endl;
      reverseInOrderPrint(x->left, depth+1);
   }
}
/**************************************************
Description:- Constructer of the RBTree class, use to 
			initialize nil node and root node
input:-NA
output:-NA

***************************/


RBTree::RBTree()
{
	nil= new Node();
	root = nil;
	
}

/**************************************************
Description:- Destructor of the RBTree class, use to 
			initialize nil node and root node
input:-NA
output:-NA

***************************/

RBTree::~RBTree()
{
	postOrderWalk(root);
}


/**********************************************
Description :- Constructor of NOde class use to initialize 
			parent left and right to  nil and color to Red

***************************/

RBTree::Node::Node(const string& k, const string& s, Node* nil)
{	key = new string(k);
	value= new string(s);
	parent= nil;
	left=nil;
	right=nil;
	color = 'R';
}
/**************************************************
Description :- Constructor of NOde class use to initialize 
			parent, left and right to  null and color to black

***************************/
RBTree::Node::Node()
{
	color = 'B';
	parent= NULL;
	left=NULL;
	right=NULL;
	key = NULL;
	value = NULL;
}	
/**************************************************
Description :- Destructor of NOde class use to initialize 
			parent left and right to  nil and color to Red


***************************/
RBTree::Node::~Node()
{
	delete key;
	delete value;

}

/**************************************************
Description:- This function is used to process the input 
recieved from the processinsert function
input:- const string& key, const string& value
output:- NA

***************************/
void RBTree::rbInsert(const string& key, const string& value)
{
	Node *insert = new Node (key,value,nil);
	rbInsert(insert);
}



/**************************************************
Description:- This function is used to rotate the function 
		towards left ie making the right child as the root
input:- node *x
output:- NA

***************************/

void RBTree::leftRotate(Node* x)
{
	Node *y;
	y=x->right;
	x->right=y->left;
	if (y->left!=nil)
	{
		y->left->parent=x;
	}
	y->parent=x->parent;
	if (x->parent==nil)
	{
		root=y;
	}
	else if (x == x->parent->left)
	{
		x->parent->left=y;
	}
	else
	{
		x->parent->right=y;
	}
	y->left=x;
	x->parent=y;
}
/**************************************************
Description:- This function is used to rotate the function 
		towards right ie making the left child as the root
input:- Node *x
output:- NA

***************************/

void RBTree::rightRotate(Node* x)
{
	Node *y;
	y=x->left;
	x->left=y->right;
	if (y->right!=nil)
	{
		y->right->parent=x;
	}
	y->parent=x->parent;
	if (x->parent==nil)
	{
		root=y;
	}
	else if (x == x->parent->right)
	{
		x->parent->right=y;
	}
	else
	{
		x->parent->left=y;
	}
	y->right=x;
	x->parent=y;
}
/**************************************************
Description:- This is used to insert the node recieved 
			from the rbInsert() and process INsert function
input:- Node *z
output:- NA

***************************/

void RBTree::rbInsert(Node* z)
{
	Node *y;
	Node *x;
	y= nil;
	x=root;
	while(x!=nil)
	{
		y=x;
		if (*(z->key) < *(x->key))
		{
			x=x->left;
		}
		else
		{
			x=x->right;
		}
	}
	
	z->parent= y;
	if (y == nil)
	{
		root=z;
	}
	else if (*(z->key) < *(y->key))
	{
		y->left=z;
	}
	else
	{
		y->right= z;
	}
	z->left=nil;
	z->right= nil;
	z->color= 'R';
	rbInsertFixup(z);
}

/**************************************************
Description:- This function is used to arrange the tree, 
			satisfying the conditions of the Red Black Tree
input:- Node *z
output:-

***************************/

void RBTree::rbInsertFixup(Node* z)
{
	Node* y;
	while (z->parent->color == 'R')
	{
		if (z->parent == z->parent->parent->left)
		{
			y=z->parent->parent->right;
			if(y->color == 'R')
			{
				z->parent->color = 'B';
				y->color='B';
				z->parent->parent->color='R';
				z = z->parent->parent;
			}
			else
			{
				if (z == z->parent->right)
				{
					z=z->parent;
					leftRotate(z);
				}
			else
			{
				z->parent->color= 'B';
				z->parent->parent->color='R';
				rightRotate(z->parent->parent);
			}
			}
		}
		else
		{
			y=z->parent->parent->left;
			if(y->color == 'R')
			{
				z->parent->color = 'B';
				y->color='B';
				z->parent->parent->color='R';
				z = z->parent->parent;
			}
			else 
				{
					if (z == z->parent->left)
				{
					z=z->parent;
					rightRotate(z);
				}
			else
			{			
				z->parent->color='B';
				z->parent->parent->color='R';
				leftRotate(z->parent->parent);
			}
		}
		}
	}
	root->color='B';
}


/**************************************************
Description:- This function is used to print the tree
input:-NA
output:-NA

***************************/

void RBTree::rbPrintTree()
{
	reverseInOrderPrint(root,0);
}


/**************************************************
Description:- This function is used to find the 
			Minimum node below a selected node
input:- Node * x;
output:-

***************************/

RBTree::Node* RBTree::rbTreeMinimum(Node * x)
{
	while(x->left!=nil)
	{
		x=x->left;
	}
	return x;
}

/**************************************************
Description:-This function is used to find the 
			Maximum node below a selected node
input:- Node* x.
output:-

***************************/
RBTree::Node* RBTree::rbTreeMaximum(Node* x)
{
	while( x->right!= nil)
	{
		x=x->right;
	}
	return  x;
}


/**************************************************
Description:- This function is used to find the 
			next immediate or equal value in the tree
input:- Node *x;
output:-NA

***************************/

RBTree::Node* RBTree::rbTreeSuccessor(Node* x)
{
	Node*  y;
	if (x->right!=nil)
	{
		return rbTreeMinimum(x->right);
	}
	y=x->parent;
	while (y!=nil && x==y->right)
	{
		x=y;
		y=y->parent;
	}
	return y;
}

/**************************************************
Description:-This function is used to find the 
			previous immediate or equal value in the tree
input:- NOde* x
output:-NA

***************************/

RBTree::Node* RBTree::rbTreePredecessor(Node *x)
{
	Node* y;
	if (x->left != nil)
	{
		return rbTreeMaximum(x->left);
	}
	y = x->parent;
	while(y!= nil && x==y->left)
	{
		x=y;
		y=y->parent;
	}
	return y;
}
/**************************************************
Description:- This function is used to find the node in the entire tree
input:- Node* x and key.
output:- Node *

***************************/

RBTree::Node* RBTree::rbTreeSearch(Node * x, const string& key)
{
	if (x==nil || key == *x->key)
	{
		return x;
	}

	if (key < *x->key)
	{
		return rbTreeSearch(x->left,key);
	}

	else
	{
		return rbTreeSearch(x->right,key);
	}
}




/**************************************************
Description:- This function is used to find given node in the tree, 
		this function gives output on both single and multiple files.
		This is stored in a vector
input:- string key
output:-vector

***************************/
vector<const string* > RBTree::rbFind(const string& key)
{
	Node *s;
	Node *successor;
	Node *predecessor;
	vector<const string*> data;

	s=rbTreeSearch(root,key);

	if (s != nil)
	{
		data.push_back(s->value);
		if ( rbTreeSuccessor(s) != nil && 
			*rbTreeSuccessor(s)->key == key)
		{
			successor = rbTreeSuccessor(s);
			while (successor!=nil)
			{ 
				if(*successor->key== key) 
					data.push_back(successor->value);
				successor=rbTreeSuccessor(successor);
			}
			
		}
		if (rbTreePredecessor(s) != nil && 
			*rbTreePredecessor(s)->key == key)
		{
			predecessor = rbTreePredecessor(s);
			while (predecessor != nil )
			{
				if (*predecessor->key == key)
					data.push_back(predecessor->value);
				predecessor=rbTreePredecessor(predecessor);
			}
		}
	}
	return data;
}
/**************************************************
Description:- This is a helper function to the delete function
input:- Node * u and Node* v
output:- NA

***************************/
void RBTree::rbTransplant(Node *u, Node *v)
{
	if (u->parent == nil)
	{
		root=v;
	}
	else if (u==u->parent->left)
	{
		u->parent->left=v;
	}
	else 
	{
		u->parent->right = v;
	}
	v->parent = u->parent;
}

/**************************************************
Description:- This function is used to delete the key and 
the value received from process delete. This function works
for both in deleting a single node and multiple nodes.
input:- key and value
output:- NA

***************************/

void RBTree::rbDelete(const string&key,const string& value)
{
	Node * del;
	Node * successor;
	Node * predecessor;
	Node *temp1;
	Node *temp;
	Node *temp3;
	del=rbTreeSearch(root,key);
	if (del != nil)
	{
		if (*del->key == key)
		{
			temp1 = del;
			if (*del->value == value)
				rbDelete(del);
			if (rbTreeSuccessor(temp1) != nil &&
				*rbTreeSuccessor(temp1)->key == key)
			{

				successor = rbTreeSuccessor(temp1);
				while (successor != nil)
				{
					temp=successor;
					if (*successor->key == key )
					{
						if (*successor->value == value)
							rbDelete(temp);
					}
					successor = rbTreeSuccessor(successor);
				}
			}
			
			if (rbTreePredecessor(temp1) != nil && 
				*rbTreePredecessor(temp1)->key == key )
			{
				predecessor = rbTreePredecessor(temp1);
				
				while (predecessor != nil)
				{
					temp3=predecessor;
					if (*predecessor->key == key)
					{
						if (*predecessor->value == value)
						rbDelete(temp3);						
					}
					predecessor = rbTreePredecessor(predecessor);
				}		
			}
		}
	}
}


/**************************************************
Description:- This function is made from the pusedo-code 
				from the CLRS for the delete fucntion 
input:- Node *z;
output:-

***************************/

void RBTree::rbDelete(Node *z)
{
	Node *y;
	Node *x;
	y=z;
	char yOriginalColor ;
	yOriginalColor = y->color;
	if (z->left == nil)
	{
		x=z->right;
		rbTransplant(z,z->right);
	}
	else if (z->right == nil)
	{
		x= z->left;
		rbTransplant(z,z->left);
	}
	else 
	{
		y= rbTreeMaximum(z->left);
		yOriginalColor = y->color;
		x= y->left;
		if (y->parent==z)
		{
			x->parent=y;
		}
		else
		{
			rbTransplant(y,y->left);
			y->left = z->left;
			y->left->parent = y;
		}
		rbTransplant(z,y);
		y->right=z->right;
		y->right->parent= y;
		y->color = z->color;

	}
	if (yOriginalColor == 'B')
	{
		rbDeleteFixup(x);
	}
}

/**************************************************
Description:- This function is used to help the delete fucntion 
			in re-arrangeing itself to satisfy the 
			conditions of the RED black tree
input:-NA
output:-NA

***************************/

void RBTree::rbDeleteFixup(Node *x)
{
	Node *w;
	while(x != root && x->color == 'B')
	{
		if (x==x->parent->left)
		{
			w=x->parent->right;
			if (w->color =='R')
			{
				w->color='B';
				x->parent->color='R';
				leftRotate(x->parent);
				w= x->parent->right;

			}
			if(w->left->color =='B' && w->right->color == 'B' )
			{
				w->color= 'R';
				x=x->parent;
			}
			else if (w->right->color =='B')
			{
				w->left->color = 'B';
				w->color='R';
				rightRotate(w);
				w=x->parent->right;
			}
			else 
			{
				w->color=x->parent->color;
				x->parent->color = 'B';
				w->right->color='B';
				leftRotate(x->parent);
				x=root;
			}
		}
		else 
		{
			w=x->parent->left;
			if (w->color =='R')
			{
				w->color='B';
				x->parent->color='R';
				rightRotate(x->parent);
				w= x->parent->left;

			}
			if(w->right->color =='B' && w->left->color == 'B' )
			{
				w->color= 'R';
				x=x->parent;
			}
			else if (w->left->color =='B')
			{
				w->right->color = 'B';
				w->color='R';
				leftRotate(w);
				w=x->parent->left;
			}
			else 
			{
				w->color=x->parent->color;
				x->parent->color = 'B';
				w->left->color='B';
				rightRotate(x->parent);
				x=root;
			}
		}
	}

	x->color='B';
}

/***************************
DEscription:- This function is used to go through all the nodes 
			and delete the tree and free the space
input :- Node* x
output:- NA

****************/
void RBTree::postOrderWalk(Node* x )
{
	if (x != nil)
	{
		postOrderWalk(x->left);
		postOrderWalk(x->right);
		delete x;
	}
}