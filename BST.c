// Binary Search Tree

struct BinarySearchTree {
    struct node *root;
    int size;
};

struct node {
    TYPE value;
    struct node *left;
    struct node *right;
};


void initBST(struct BinarySearchTree *tree){
    tree->size = 0;
    tree->root = 0;
}

void addBST(struct BinarySearchTree *tree, TYPE newValue){
    tree->root = _nodeAddBST(tree->root, newValue);
    tree->size++;
}

int sizeBST(struct binarySearchTree *tree){
    return tree->size;
}

struct node* _nodeAddBST(struct node *current, TYPE newValue){
    struct Node *node;
    
    if(current == 0){
        node =(struct Node *)malloc(sizeof(struct Node));
        assert(node != 0);
        
        node->value = newValue;
        node->left = node->right = 0;
        
        return node;
    }
    
    if(newValue < current->value)){ // (LT(newValue, current->value))
        current->left = _addNode(current->left, newValue);
        
    } else { //(newValue > current->value);
        current->right = _addNode(current->right, newValue);
    }
    
    return current;
}


// Contains Function:
int containsBST(struct binarySearchTree *tree, TYPE d){
    struct Node *cur = tree->root;
    
    while(cur != 0){
        if(d == cur->value){ // EQ(d, cur->value)
            return 1; // return if value is found
        }
        
        if(LT(d, cur->value)){
            cur = cur->left; // go left
        } else { // d > cur->value, so go right
            cur = cur->right;
        }
    }
    return 0; // value not found
}


// Remove Function:
void removeBST(struct binarySearchTree *tree, TYPE d){
    if(containsBST(tree, d)){
        tree->root = _nodeRemoveBST(tree->root, d);
        tree->size--;
    }
    return;
}

// leftmostchild func:
TYPE _leftmostChild(struct node *current){
    while(current->left != 0){ // while a left still exists
        current = current->left;
    }
    return current->value; // returns the value of the leftmost child
}

// remove leftmostchild func:
struct node* _removeLeftmostChild(struct node *current){
    struct Node *node;
    
    if(current->left == 0){
        node = current->right;
        free(current);
        return node;
    }
    
    current->left = _removeLeftmostChild(current->left);
    return current;
}


// remove node function:

void _nodeRemoveBST(struct node *current, TYPE d){
    struct Node *node;
    
    if(LT(d, current->value) == 0) { // found the value
        if(current->right == 0){
            node = current->left;
            free(current);
            return node;
        }
        current->value = _leftmostChild(current->right);
        current->right = _removeLeftmostChild(current->right);
    } else if(LT(d, current->value) < 0) {
        current->left = _nodeRemoveBST(current->left, value);
    } else { // if LT(d, current->value) > 0 
        current->right = _nodeRemoveBST(current->right, value);
    }
    return current;
}



// QUESTIONS:

// 1. What is the primary characteristic of a binary search tree?
// Answer: Every node's value is greater than all its descendents on the left, and less than or 
// equal to all its descendents on the right.

// 2. Explain how the search for an element in a binary search tree is an example of the
// idea of divide and conquer.

// 3. Try inserting the values 1 to 10 in order into a BST. What is the height of the
// resulting tree?

// 4. Why is it important that a binary search tree remain reasonably balanced? What
// can happen if the tree becomes unbalanced? Anwswer: Time complexity to access the element increases.

// 5. What is the maximum height of a BST that contains 100 elements? What is the
// minimum height? 

// 6. Explain why removing a value from a BST is more complicated than insertion.

// 7. Suppose you want to test our BST algorithms. What would be some good
// boundary value test cases?

// 8. Program a test driver for the BST algorithm and execute the operations using the
// test cases identified in the previous question.

// 9. The smallest element in a binary search tree is always found as the leftmost child
// of the root. Write a method getFirst to return this value, and a method removeFirst
// to modify the tree so as to remove this value.

// 10. With the methods described in the previous question, it is easy to create a data
// structure that stores values in a BST and implements the Priority Queue interface.
// Show this implementation, and describe the algorithmic execution time for each
// of the Priority Queue operations.

// 11. Suppose you wanted to add the equals method to our BST class, where two trees
// are considered to be equal if they have the same elements. What is the complexity
// of your operation?