
// Include necessary headers and import namespace
#include <string>
#include "BST.h"
using namespace std;

// Declare helper function prototypes
string to_string_helper(Node* root);
int num_constans_counter_helper(Node* root);
void deleteTree(Node* root);


// Constructor, initialize root to null
BST::BST()
{
	this->root = nullptr;
}

// Recursive copy constructor, creates a new tree that is an exact copy of the input tree
Node* copyTree(Node* rhs)
{
	if (rhs == nullptr)
	{
		return nullptr;
	}

	////Creating a new root Node for a tree
	Node* newNode = new Node();
	newNode->left = nullptr;
	newNode->right = nullptr;
	newNode->name = rhs->name;
	newNode->value = rhs->value;

	//Copying left nodes and right nodes
	if (rhs->left != nullptr)
	{
		newNode->left = copyTree(rhs->left);
	}
	if (rhs->right != nullptr)
	{
		newNode->right = copyTree(rhs->right);
	}
	return newNode;
}

// Copy constructor that creates a new tree that is an exact copy of the input tree
BST::BST(const BST& other)
{
	// TODO: Implement the copy constructor
	this->root = copyTree((&other)->root);
}

// Helper function that recursively deletes all nodes in the tree
void deleteTree(Node* root)
{
	if (root == nullptr)
	{
		return;
	}

	if (root->left != nullptr)
	{
		deleteTree(root->left);
	}
	if (root->right != nullptr)
	{
		deleteTree(root->right);
	}
	delete root;
}

// Destructor, deletes all nodes in the tree
BST::~BST()
{
	// TODO: Implement the destructor
	deleteTree(this->root);

}

// Helper function for to_string() method that recursively traverses the tree and returns a string representation
string to_string_helper(Node* root)
{
	if (root == nullptr)
	{
		return "";
	}
	else
	{
		return to_string_helper(root->left) +
			root->name + "=" + root->value + " " +
			to_string_helper(root->right);
	}
}

// Method that returns a string representation of the tree
string BST::to_string() const
{
	string ret = to_string_helper(this->root);
	if (ret.length() > 1)
	{
		ret.pop_back(); // remove final space
	}

	return ret;
}

// Method that inserts a new node with a value and a name into the tree
void BST::insert_constant(string name, string value)
{
	// TODO: Implement the insert_constant method
	if (this->root == nullptr)
	{
		// Create new node
		Node* roott = new Node;
		// Set new value
		roott->value = value;
		// Set new name
		roott->name = name;
		// Set branches to nullptr
		roott->left = nullptr;
		roott->right = nullptr;
		this->root = roott;
		return;
	}

	Node* currentNode = this->root;


	while (true)
	{
		if (name < currentNode->name)
		{
			if (currentNode->left == nullptr)
			{
				Node* nullptrNode = new Node;
				nullptrNode->left = nullptr;
				nullptrNode->right = nullptr;
				nullptrNode->value = value;
				nullptrNode->name = name;
				currentNode->left = nullptrNode;
				return;
			}

			currentNode = currentNode->left;
			/*value = currentNode->value;
			name = currentNode->name;*/
		}
		else
		{
			if (currentNode->right == nullptr)
			{
				Node* nullptrNode = new Node;
				nullptrNode->left = nullptr;
				nullptrNode->right = nullptr;
				nullptrNode->value = value;
				nullptrNode->name = name;
				currentNode->right = nullptrNode;
				return;
			}

			currentNode = currentNode->right;
			/*value = currentNode->value;
			name = currentNode->name;*/
		}
	}
}

//Getting value function
string BST::get_value(string name) const
{
	// TODO: Change this to implement the get_value() method

	Node* currentNode = this->root;

	if (currentNode == nullptr)
	{
		return "";
	}

	while (true)
	{
		if (currentNode->name == name)
		{
			return currentNode->value;
		}
		else if (name < currentNode->name)
		{
			if (currentNode->left == nullptr)
			{
				return "";
			}
			currentNode = currentNode->left;

		}
		else
		{
			if (currentNode->right == nullptr)
			{
				return "";
			}
			currentNode = currentNode->right;
		}

	}
}

//A helper recursion function for num_constans
int num_constans_counter_helper(Node* root)
{
	if (root == nullptr)
	{
		return 0;
	}

	return 1 + num_constans_counter_helper(root->left) + num_constans_counter_helper(root->right);
}

//A function where we count number of constants in our tree
int BST::num_constants() const
{
	// TODO: Change this to implement the num_constants() method

	return num_constans_counter_helper(this->root);
}

BST& BST::operator=(const BST& rhs)
{
	// TODO: Add code here to implement the = operator
	deleteTree(this->root);
	this->root = copyTree((&rhs)->root);
	return *this;
}