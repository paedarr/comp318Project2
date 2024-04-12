#include "AVLTrees.h"
int main(){

    balancedBST bst;
    bst.insertItem('A');
    bst.insertItem('B');
    bst.insertItem('C');
    bst.insertItem('D');
    bst.insertItem('E');
    bst.insertItem('F');
    bst.insertItem('G');
    bst.insertItem('H');
    bst.insertItem('I');

    cout << "Binary Search Tree created." << endl;
    cout << "In-order Traversal: ";
    bst.in_order_Traversal();
    cout << endl;
    cout << "Pre-order Traversal: ";
    bst.pre_order_Traversal();
    cout << endl;
    cout << "Post-order Traversal: ";
    bst.post_orderTraversal();
    cout << endl;
    cout << "Level-order Traversal: ";
    bst.level_order_Traversal();
    cout << endl;

    // Displaying number of nodes in binary search tree
    cout << "Number of nodes in BST: " << bst.treeNodeCount() << endl;

    // Displaying height of binary search tree
    cout << "Height of BST: " << bst.height() << endl;

    // Searching for an item in binary search tree
    if (bst.searchItem('D'))
        cout << "Item 'D' found in BST." << endl;
    else
        cout << "Item 'D' not found in BST." << endl;

    if (bst.searchItem('Z'))
        cout << "Item 'Z' found in BST." << endl;
    else
        cout << "Item 'Z' not found in BST." << endl;

    cout << "Tree Display: " << endl;
    bst.display();

    cout << "Balance Factors: " << endl;
    bst.balanceFactors();

    return 0;
}