// AVLs
// Trees that maintains a height balance of a tree

struct AVLNode {
    void *val;
    struct AVLNode *left; // left child
    struct AVLNode *right; // right child
    int hght; // height
};

struct AVLTree { // heigh-balanced binary search tree
    struct AVLNode *root;
    int cnt; // count
};

void initAVL(struct AVLTree *tree){
    tree->root = 0;
    tree->cnt = 0;
    return;
}

struct AVLTree *newAVLTree(){
    struct AVLTree *tree;
    tree = (struct AVLTree *)malloc(sizeof(struct AVLTree));
    assert(tree != 0);
    
    initAVL(tree);
    return tree;
}

// contains function:
int containsAVLTree(struct AVLTree *tree, void *val, comparator compare){
    struct AVLNode *cur;
    cur = tree->root;
    
    while(cur != 0){
        if((*compare)(val, cur->val) == 0){
            return 1; // found it
        } else if((*compare)(val, cur->val) < 0){
            cur = cur->left;
        } else { // val > cur->val;
            cur = cur->rght;
        }
    }
    return 0; // didn't find it.
}

// add function:
void addAVLTree(struct AVLTree *tree, void *val, comparator compare){
    tree->root = _addNode(tree->root, val, compare); // call the recursive helper function
    tree->cnt++;
    return;
}

// helper function _addNode
struct AVLNode *_addNode(struct AVLNode *cur, void *val, comparator compare){
    if(cur == 0){ // base case 
        newNode = (struct AVLNode *)malloc(sizeof(struct AVLNode));
        assert(newNode != 0);
        newNode->left = newNode->rght = 0;
        newNode->val = val;
        newNode->hght = 0;
        return newNode;
        // start here mentally for this one:
    } else { // recursive case 
        if((*compare)(val, cur->val) < 0) {
            cur->left = _addNode(cur->left, val, compare);
        } else {
            cur->rght = _addNode(cur->rght, val, compare);
        }
        return _balance(cur); // must baslance the tree on the way up from the recursion
        // return the rebuilt tree as come back from recursion
    }
}

//helper function _balance
struct AVLNode *_balance(struct AVLNode *cur){
    int cbf = _bf(cur); //balance factor!
    if(cbf < -1){ // cur is heavy on the left
        if(_bf(cur->left) > 0){ // if leftChild is heavy on the right;
            cur->left = _rotateLeft(cur->left); // must rotate left first (rotation 1 out of 2)
        }
        return _rotateRight(cur); 
    } else if(cbf > 1){ // cur is heavy on the right
        if(_bf(cur->rght) < 0) { // if rightChild is heavy on the left;
            cur->rght = _rotateRight(cur->rght);
        }
        return _rotateLeft(cur);
    }
    // balanced now
    _setHeight(cur);
    return(cur);
}

// utility function for balance factor
int _bf(struct AVLNode *cur){
    return (_height(cur->rght) - _height(cur->left));
}

// utility function to set the height of a node
void _setHeight(struct AVLNode *cur){
    int lh = _height(cur->left);
    int rh = _height(cur->rght);
    if(lh < rh){
        cur->hght = rh + 1;
    } else {
        cur->hght = lh + 1;
    }
    return;
}


