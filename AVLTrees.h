#ifndef AVLTREES_H
#define AVLTREES_H

#include <algorithm> //for 'max' usage
#include <iostream> //basic i/o
#include <string> //string manipulation
#include <iomanip> //basic i/o formatting
#include <queue> //for level-order functionality
#include <stack> //for stack usage in display method
using namespace std;

typedef char elemType; //char data type, with name elemType

class binaryTree {
protected:
    // Definition of TreeNode structure representing a node in the binary tree
    struct TreeNode {
        elemType data;          // Data stored in the node
        TreeNode* left;         // Pointer to the left child node
        TreeNode* right;        // Pointer to the right child node
        int balance_factor;     // Balance factor of the node for AVL tree
        
        // Constructor for the TreeNode structure
        // Input: Data to be stored in the node, pointers to the left and right child nodes (default to nullptr)
        // Output: None
        // Description: Initializes a TreeNode object with the given data, left and right child pointers, and sets the balance factor to 0.
        TreeNode(elemType x, TreeNode* l = nullptr, TreeNode* r = nullptr)
            : data(x), left(l), right(r), balance_factor(0) {}
    };

    TreeNode * root;    // Pointer to the root node of the binary tree

    // Helper method for calculating the height of the binary tree
    // Input: TreeNode pointer representing the current node
    // Output: Integer representing the height of the subtree rooted at the given node
    // Description: Recursively calculates the height of the subtree rooted at the given node.
    int getHeight(TreeNode* node) const;

    // Helper method to recursively display the balance factors of nodes in the binary tree
    // Input: TreeNode pointer representing the current node
    // Output: None (prints the balance factors)
    // Description: Recursively displays the balance factors of nodes in the binary tree.
    void printBalanceFactors(TreeNode* node) const;
    
    // Helper method to recursively display the binary tree in a vertical format
    // Input: String representing the indentation order, TreeNode pointer representing the current node, boolean indicating if the node is left child
    // Output: None (prints the tree structure)
    // Description: Recursively displays the binary tree in a vertical format, showing the hierarchical relationship between nodes.
    void display_computation(string order, TreeNode * node, bool isLeft) const;

    // ** BROKEN METHOD, unused **
    // --> If you would like to use, remove comments on this declaration, the definition, and
    // .. the usage in the display() method. 
    // ---> Major issues with output formatting, could not resolve. Here for clarity. 
    //
    // Method to display the binary tree in a vertical format 
    // Input: TreeNode pointer representing the root node, integer representing the current indentation level
    // Output: None (prints the tree structure)
    // Description: Displays the binary tree in a vertical format, indicating the hierarchical relationship between nodes.
    
    // void display_vertical(TreeNode* node, int indent) const;

    // Helper method to recursively perform an in-order traversal of the binary tree
    // Input: TreeNode pointer representing the current node
    // Output: None (prints the traversed nodes)
    // Description: Recursively performs an in-order traversal of the binary tree.
    void in_order (TreeNode *) const; 

    // Helper method to recursively perform a pre-order traversal of the binary tree
    // Input: TreeNode pointer representing the current node
    // Output: None (prints the traversed nodes)
    // Description: Recursively performs a pre-order traversal of the binary tree.
    void pre_order (TreeNode *) const;  

    // Helper method to recursively perform a post-order traversal of the binary tree
    // Input: TreeNode pointer representing the current node
    // Output: None (prints the traversed nodes)
    // Description: Recursively performs a post-order traversal of the binary tree.  
    void post_order (TreeNode *) const; 

    // Helper method to perform a level-order traversal of the binary tree
    // Input: TreeNode pointer representing the root node
    // Output: None (prints the traversed nodes)
    // Description: Performs a level-order traversal of the binary tree, visiting nodes level by level.
    void level_order(TreeNode *) const;

    // Method to calculate the size of the binary tree
    // Input: TreeNode pointer representing the root node
    // Output: Integer representing the size of the tree
    // Description: Calculates the number of nodes in the binary tree.
    int size (TreeNode *) const;

    // Method to generate a string representing the level-order traversal of the binary tree
    // Input: TreeNode pointer representing the root node
    // Output: String representing the level-order traversal
    // Description: Generates a string representing the level-order traversal of the binary tree.
    string level_order_string(TreeNode *) const;



public:
    // Constructor for the binaryTree class
    // Input: None
    // Output: None
    // Description: Initializes the root pointer to nullptr, creating an empty binary tree.
    binaryTree () {root = NULL;};

    // Method to calculate the height of the binary tree
    // Input: None
    // Output: Integer representing the height of the tree
    // Description: Recursively calculates the height of the binary tree starting from the root node.
    int height() const;

    // Method to display the binary tree in various formats
    // Input: None
    // Output: None (prints the tree structure)
    // Description: Displays the binary tree using different traversal techniques, such as level order and vertical display.
    void display() const; // Implement as per project specification

    // Method to perform a post-order traversal of the binary tree
    // Input: None
    // Output: None (prints the traversed nodes)
    // Description: Performs a post-order traversal of the binary tree, visiting left subtree, right subtree, and then the root.
    void post_orderTraversal() const; 

    // Method to perform an in-order traversal of the binary tree
    // Input: None
    // Output: None (prints the traversed nodes)
    // Description: Performs an in-order traversal of the binary tree, visiting left subtree, root, and then right subtree.
    void in_order_Traversal() const; 

    // Method to perform a pre-order traversal of the binary tree
    // Input: None
    // Output: None (prints the traversed nodes)
    // Description: Performs a pre-order traversal of the binary tree, visiting root, left subtree, and then right subtree.
    void pre_order_Traversal() const;

    // Method to perform a level-order traversal of the binary tree
    // Input: None
    // Output: None (prints the traversed nodes)
    // Description: Performs a level-order traversal of the binary tree, visiting nodes level by level.
    void level_order_Traversal() const;

    // Method to count the number of nodes in the binary tree
    // Input: None
    // Output: Integer representing the number of nodes in the tree
    // Description: Counts the number of nodes in the binary tree by calling the size method.
    int treeNodeCount() const {return size(root);};
};

class BST : public binaryTree {
protected:
    // Helper method to recursively insert a node into the binary search tree
    // Input: Reference to the pointer of the current node, constant reference to the element to be inserted
    // Output: None
    // Description: Recursively inserts a new node into the binary search tree while maintaining its properties.
    void insertNode(TreeNode*& node, const elemType item);


    // Method to search for an element in the binary search tree
    // Input: Constant reference to the element to be searched, TreeNode pointer representing the root node
    // Output: Boolean indicating whether the element is found or not
    // Description: Searches for the given element in the binary search tree.
    bool search (const elemType, TreeNode *) const; 

public:
    // Method to insert an element into the binary search tree
    // Input: Constant reference to the element to be inserted
    // Output: None
    // Description: Inserts a new element into the binary search tree while maintaining its properties.
    void insertItem(const elemType item);


    // Method to search for an item in the binary search tree
    // Input: Constant reference to the element to be searched
    // Output: Boolean indicating whether the item is found or not
    // Description: Searches for the given item in the binary search tree by calling the search method.
    bool searchItem (const elemType key){return search(key, root);};
};

class balancedBST : public BST {
private:
    // Method to balance the binary search tree after insertion
    // Input: Reference to the pointer of the current node
    // Output: None
    // Description: Balances the binary search tree after insertion to maintain its properties.
    void balance(TreeNode*& node);

    // Method to perform a right rotation on a node in the balanced binary search tree
    // Input: Reference to the pointer of the current node
    // Output: None
    // Description: Performs a right rotation on the given node in the balanced binary search tree.
    void rightRotate(TreeNode*& node);

    // Method to perform a left rotation on a node in the balanced binary search tree
    // Input: Reference to the pointer of the current node
    // Output: None
    // Description: Performs a left rotation on the given node in the balanced binary search tree.
    void leftRotate(TreeNode*& node);
    
    // Method to perform a left-right rotation on a node in the balanced binary search tree
    // Input: Reference to the pointer of the current node
    // Output: None
    // Description: Performs a left-right rotation on the given node in the balanced binary search tree.
    void leftRightRotate(TreeNode*& node);

    // Method to perform a right-left rotation on a node in the balanced binary search tree
    // Input: Reference to the pointer of the current node
    // Output: None
    // Description: Performs a right-left rotation on the given node in the balanced binary search tree.
    void rightLeftRotate(TreeNode*& node);

protected:
    // Helper method to recursively insert a node into the balanced binary search tree and ensure balance
    // Input: Reference to the pointer of the current node, constant reference to the element to be inserted
    // Output: None
    // Description: Recursively inserts a new node into the balanced binary search tree and ensures the tree remains balanced.
    void insertAndBalance(TreeNode*& node, const elemType item);

public:
    // Method to insert an element into the balanced binary search tree and ensure balance
    // Input: Constant reference to the element to be inserted
    // Output: None
    // Description: Inserts a new element into the balanced binary search tree and ensures the tree remains balanced.
    void insertItem(const elemType item);

    // Method to display the balance factors of nodes in the binary tree
    // Input: None
    // Output: None (prints the balance factors)
    // Description: Displays the balance factors of nodes in the binary tree, indicating whether the tree is balanced or not.
    void balanceFactors() const;
};

#endif // AVLTREES_H