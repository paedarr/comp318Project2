#ifndef AVLTREES_H
#define AVLTREES_H

#include <algorithm>
#include <iostream>
#include <string>
#include <iomanip>
#include <queue>
#include <stack>
using namespace std;

typedef char elemType;

class binaryTree {
protected:
    struct TreeNode {
        elemType data;
        TreeNode* left;
        TreeNode* right;
        int balance_factor;
        // Constructor for convenience
        TreeNode(elemType x, TreeNode* l = nullptr, TreeNode* r = nullptr)
            : data(x), left(l), right(r), balance_factor(0) {}
    };
    TreeNode * root;

    // Helper methods for tree operations
    int getHeight(TreeNode* node) const;
    void printBalanceFactors(TreeNode* node) const;
    // Add other traversal methods if needed
    //void display_computation(TreeNode* node, int indent) const;
    void display_computation(string order, TreeNode * node, bool isLeft) const;
    void in_order (TreeNode *) const; 
    void pre_order (TreeNode *) const;    
    void post_order (TreeNode *) const; 
    void level_order(TreeNode *) const;
    int size (TreeNode *) const;

    string level_order_string(TreeNode *) const;



public:
    binaryTree () {root = NULL;};
    int height() const;
    void display() const; // Implement as per project specification
    void post_orderTraversal() const; 	
    void in_order_Traversal() const; 
    void pre_order_Traversal() const;
    void level_order_Traversal() const;
    int treeNodeCount() const {return size(root);};
};

class BST : public binaryTree {
protected:
    void insertNode(TreeNode*& node, const elemType item);
    bool search (const elemType, TreeNode *) const; 
    // Add other BST-specific helper methods if needed

public:
    void insertItem(const elemType item);
    bool searchItem (const elemType key){return search(key, root);};
    // Add other public methods if needed
};

class balancedBST : public BST {
private:
    void balance(TreeNode*& node);
    void rightRotate(TreeNode*& node);
    void leftRotate(TreeNode*& node);
    // Add methods for double rotation
    void leftRightRotate(TreeNode*& node);
    void rightLeftRotate(TreeNode*& node);
protected:
  void insertAndBalance(TreeNode*& node, const elemType item);

public:
    void insertItem(const elemType item);
    void balanceFactors() const;
};

#endif // AVLTREES_H