#include "AVLTrees.h"

int binaryTree::height() const {
    return getHeight(this->root);
}
// Implementations of binaryTree methods
int binaryTree::getHeight(TreeNode* node) const {
    if (node == nullptr) return 0;
    return 1 + max(getHeight(node->left), getHeight(node->right));
}

void binaryTree::display() const {
    string order = level_order_string(root);
    display_computation("", root, false);
    cout << "--------------------------------" << endl;

    // <!--- Comment out the lines below if you want to test with the
    //       vertical binary tree. However, this is unstable and there
    //       are major issues with alignment and correct output per line.
    //       However, it can be observed that the program actually does output
    //       the nodes, and branches, in the correct ordering, it just doesn't
    //       format correctly.  ---!>
    // display_vertical(root, 0);
    // cout << "--------------------------------" << endl;
}

void binaryTree::display_computation(string order, TreeNode * node, bool isLeft) const{
    if( node != nullptr ){
        cout << order;

        cout << (isLeft ? "├──" : "└──" );

        // print the value of the node
        cout << node->data << endl;

        // enter the next tree level - left and right branch
        display_computation( order + (isLeft ? "│   " : "    "), node->right, true);
        display_computation( order + (isLeft ? "│   " : "    "), node->left, false);
    }
}


// !! THIS IS THE OLD DISPLAY METHOD THAT HAS UNSTABLE FORMATTING !!
// void binaryTree::display_vertical(TreeNode* node, int indent) const {
//   // Use a stack to store nodes and their corresponding indentation levels
//   stack<pair<TreeNode*, int> > traversal_stack;

//   // Initialize stack with the root and indent level 0
//   traversal_stack.push(make_pair(node, indent));

//   while (!traversal_stack.empty()) {
//     pair<TreeNode*, int> current_pair = traversal_stack.top();
//     traversal_stack.pop();

//     node = current_pair.first;
//     indent = current_pair.second;

//     bool does_child_exist = false;

//     // Process current node
//     if (node != nullptr) {
//       // Print indentation
//       if (indent > 0) {
//         cout << setw(indent) << ' ';  // Add spaces based on indent level
//       }

//       // Add branch character based on right child
//       if (node->right != nullptr) {
//         does_child_exist = true;
//         //cout << "/";
//       }
//       // Print node data
//       cout << node->data;
//       cout << endl;
//       // Add branch character based on left child
//       if (node->left != nullptr) {
//         if (does_child_exist == true){
//             cout << "/";
//             cout << " ";
//             does_child_exist = false;
//         }
//         cout << "\\";
//       }
//       cout << "\n";

//       // Push right subtree first (pre-order) with increased indentation
//       traversal_stack.push(make_pair(node->right, indent + 1));

//       // Push left subtree with increased indentation
//       traversal_stack.push(make_pair(node->left, indent + 1));
//     }
//   }
// }



// Implementations of BST methods
void BST::insertItem(const elemType item) {
    insertNode(root, item);
}

void BST::insertNode(TreeNode*& node, const elemType item) {
    if (node == nullptr) {
        node = new TreeNode(item);
    } else if (item < node->data) {
        insertNode(node->left, item);
    } else if (item > node->data) {
        insertNode(node->right, item);
    } // Ignore duplicates
}

// Implementations of balancedBST methods
void balancedBST::insertItem(const elemType item) {
    insertAndBalance(this->root, item);
}

void balancedBST::insertAndBalance(TreeNode*& node, const elemType item) {
    if (node == nullptr) {
        node = new TreeNode(item);
    } else if (item < node->data) {
        insertAndBalance(node->left, item);
        balance(node); // Ensure balance is called after insertion
    } else if (item > node->data) {
        insertAndBalance(node->right, item);
        balance(node); // Ensure balance is called after insertion
    }
    // If the item is equal (duplicate), do nothing

    // After insertion, check if the node is unbalanced
    if (getHeight(node->left) - getHeight(node->right) > 1) {
        if (item < node->left->data) {
            rightRotate(node);
        } else {
            leftRightRotate(node);
        }
    } else if (getHeight(node->right) - getHeight(node->left) > 1) {
        if (item > node->right->data) {
            leftRotate(node);
        } else {
            rightLeftRotate(node);
        }
    }
}

void balancedBST::rightRotate(TreeNode*& node) {
    TreeNode* temp = node->left;
    node->left = temp->right;
    temp->right = node;
    node->balance_factor = getHeight(node->left) - getHeight(node->right);
    temp->balance_factor = getHeight(temp->left) - getHeight(temp->right);
    node = temp;
}

void balancedBST::leftRotate(TreeNode*& node) {
    TreeNode* temp = node->right;
    node->right = temp->left;
    temp->left = node;
    node->balance_factor = getHeight(node->left) - getHeight(node->right);
    temp->balance_factor = getHeight(temp->left) - getHeight(temp->right);
    node = temp;
}

void balancedBST::leftRightRotate(TreeNode*& node) {
    leftRotate(node->left);
    rightRotate(node);
}

void balancedBST::rightLeftRotate(TreeNode*& node) {
    rightRotate(node->right);
    leftRotate(node);
}

void balancedBST::balanceFactors() const {
    printBalanceFactors(root);
}

void binaryTree::printBalanceFactors(TreeNode* node) const {
    if (node != nullptr) {
        int balanceFactor = getHeight(node->left) - getHeight(node->right);
        cout << node->data << ":" << balanceFactor << " ";
        printBalanceFactors(node->left);
        printBalanceFactors(node->right);
    }
}

void binaryTree::post_orderTraversal() const {
    post_order(root);
}

void binaryTree::post_order(TreeNode* node) const {
    if (node != nullptr) {
        post_order(node->left);
        post_order(node->right);
        cout << node->data << " ";
    }
}

void binaryTree::in_order_Traversal() const {
    in_order(root);
}

void binaryTree::in_order(TreeNode* node) const {
    if (node != nullptr) {
        in_order(node->left);
        cout << node->data << " ";
        in_order(node->right);
    }
}

void binaryTree::pre_order_Traversal() const {
    pre_order(root);
}

void binaryTree::pre_order(TreeNode* node) const {
    if (node != nullptr) {
        cout << node->data << " ";
        pre_order(node->left);
        pre_order(node->right);
    }
}

void binaryTree::level_order_Traversal() const {
    level_order(root);
}

void binaryTree::level_order(TreeNode* node) const {
    if (node == nullptr) return;

    queue<TreeNode*> q;
    q.push(node);

    while (!q.empty()) {
        int level_size = q.size(); // Get the number of nodes at the current level

        // Traverse all nodes at the current level
        for (int i = 0; i < level_size; ++i) {
            TreeNode* current = q.front();
            q.pop();

            cout << current->data << " ";

            // Enqueue the left and right children of the current node
            if (current->left != nullptr) {
                q.push(current->left);
            }
            if (current->right != nullptr) {
                q.push(current->right);
            }
        }
    }
}

string binaryTree::level_order_string(TreeNode* node) const {
    string result;

    if (node == nullptr) return result;

    queue<TreeNode*> q;
    q.push(node);

    while (!q.empty()) {
        int level_size = q.size(); // Get the number of nodes at the current level

        // Traverse all nodes at the current level
        for (int i = 0; i < level_size; ++i) {
            TreeNode* current = q.front();
            q.pop();

            // Append current node's data to the result string
            result += current->data;
            result += " ";

            // Enqueue the left and right children of the current node
            if (current->left != nullptr) {
                q.push(current->left);
            }
            if (current->right != nullptr) {
                q.push(current->right);
            }
        }
    }

    return result;
}

int binaryTree::size(TreeNode* node) const {
    if (node == nullptr) {
        // Base case: if the node is null, it contributes 0 to the size count.
        return 0;
    } else {
        // Recursive case: count the current node (+1) plus the size of both subtrees.
        return 1 + size(node->left) + size(node->right);
    }
}

bool BST::search(const elemType item, TreeNode* node) const {
    if (node == nullptr) {
        // Base case: The item is not found in the tree.
        return false;
    } else if (item == node->data) {
        // The item is found.
        return true;
    } else if (item < node->data) {
        // If the item is less than the node's data, search in the left subtree.
        return search(item, node->left);
    } else {
        // If the item is greater than the node's data, search in the right subtree.
        return search(item, node->right);
    }
}

void balancedBST::balance(TreeNode*& node) {
    if (node == nullptr) return;

    // Update the balance factor of the node
    node->balance_factor = getHeight(node->left) - getHeight(node->right);

    // Left heavy situation
    if (node->balance_factor > 1) {
        // Left-Left Case
        if (getHeight(node->left->left) >= getHeight(node->left->right)) {
            rightRotate(node);
        }
        // Left-Right Case
        else {
            leftRightRotate(node);
        }
    }
    // Right heavy situation
    else if (node->balance_factor < -1) {
        // Right-Right Case
        if (getHeight(node->right->right) >= getHeight(node->right->left)) {
            leftRotate(node);
        }
        // Right-Left Case
        else {
            rightLeftRotate(node);
        }
    }
    // If the balance factor is -1, 0, or 1, the tree is already balanced
    node->balance_factor = getHeight(node->left) - getHeight(node->right);
}