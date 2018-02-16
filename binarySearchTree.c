
// WORKSHEET 29: Binary Search Trees

struct node *_nodeAddBST(struct node *current, TYPE, newValue){
    struct Node* node;
    
    if(current == 0){ // if BST is empty / or found NULL spot
        node = (struct Node *)malloc(sizeof(struct Node));
        assert(node != 0);
        node->value = newValue;
        node->left = node->right = 0;
        return node;
    }
    
    if(newValue < current->value)){ //(LT(newValue, current->value)
        current->left = _addNode(current->left, newValue);
    } else { //if(newValue > current->value)
        current->right = _addNode(current->right, newValue);
    }
    return current;
}


int containsBST(struct binarySearchTree *tree, TYPE d){
    struct Node *cur = tree->root;
    
    while(cur != 0){
        if(d == cur->value){
            return 1; // found it!
        }
        if(LT(d, cur->value)){
            cur = cur->left; // go left
        } else { // d > cur->value
            cur = cur->right // go right
        }
    }
    return 0; // didn't find it...
}


void removeBST(struct binarySearchTree *tree, TYPE d){
    if(containsBST(tree, d)){
        tree->root = _nodeRemoveBST(tree->root, d);
        tree->size--;
    }
    return;
}


TYPE _leftMostChild(struct node *current){
    while(current->left != 0){
        current = current->left;
    }
    return current->value;
}


struct node* _removeLeftMostChild(struct node *current){
    struct Node *node;
    
    if(current->left == 0){
        node = current->right;
        free(current);
        return node;
    }
    
    current->left = _removeLeftMostChild(current->left);
    return current;
}


void _nodeRemoveBST(struct node *current, TYPE d){
    struct Node *node;
    
    if(LT(d, current->value) == 0){
        // found it!
        if(current->right == 0){
            node = current->left;
            free(current);
            return node;
        }
        current->value = _leftMost(current->right);
        current->right = _removeLeftMostChild(current->right);
    } else if (LT(d, current->value) < 0) { // go left
        current->left = _removeNode(current->left, value);
    } else {
        current->right = _removeNode(current->right, value);
    }
    return current;
}


// WORKSHEET 31: AVL Trees

int h(struct AVLNode *current){
    if(current == 0){
        return -1;
    } else {
        return current->height;
    }
}


void setHeight(struct AVLNode *current){
    int lch = h(current->left);
    int rch = h(current->right);
    if(lch < rch){
        current->height = 1 + rch;
    } else {
        current->height = 1 + lch;
    }
    return;
}


struct AVLnode *AVLnodeAdd(structs AVLnode* current, TYPE newValue){
    struct AVLnode *newNode;
    if(current == 0){
        newNode = (struct AVLnode *)malloc(sizeof(struct AVLnode));
        assert(newNode != 0);
        newNode->value = newValue;
        newNode->left = newNode->right = 0;
        return newNode;
    } else if (LT(newValue, current->value)){ // go left
        current->left = AVLnodeAdd(current->left, newValue);
    } else { // go right
        current->right = AVLnodeAdd(current->right, newValue);
    }
    return balance(current);
}


// WORKSHEET 33: Heaps and Priority Queues

void HeapRemoveFirst(struct dyArray *heap){
    int last = dyArraySize(heap) - 1;
    assert(last != 0); // we have at least 1 element
    
    dyArrayPut(heap, 0, dyArrayGet(heap, last)); // copy the min element to the last position;
    dyArrayRemoveAt(heap, last); // remove last element
    adjustHeap(heap, last-1, 0); // percolate down
    return;
}


void swap(struct dyArray *v, int i, int j){
    // swap i and j
    TYPE temp = dyArrayGet(v, i);
    dyArrayPut(v, i, dyArrayGet(v, j));
    dyArrayPut(v, j, temp);
    return;
    
}

int indexSmallest(struct dyArray *v, int i, int j){
    //return index of smallest element
    if(LT(dyArrayGet(v, i), dyArrayGet(v, j)){
        return i;
    } else {
        return j;
    }
}


TYPE heapGetFirst(struct dyArray *heap){
    assert(dyArraySize(heap) > 0); // we have elements
    return dyArrayGet(heap, 0);
}


void addHeap(DynArr *heap, TYPE val){
    int parent;
    int pos = sizeDynArr(heap);
    addDynArr(heap, val);
    
    while(pos != 0){
        parent = (pos-1)/2;
        if(compare(getDynArray(heap, pos), getDynArray(heap, parent)) == -1){
            swapDynArr(heap, parent, pos);
            pos = parent;
        } else {
            return;
        }
    }
    return;
}

// a recursive function to percolate up/down our min heap! 
void _adjustHeap(struct dyArray *heap, int max, int pos){
    int leftChild = 2 * pos + 1;
    int rightChild = 2 * pos + 2;
    if(rightChild < max){ // we have 2 children (if right child doesn't exist it will be -1)
        int small = _smallerIndexHeap(heap, leftChild, rightChild);
        if(getDynArray(heap, small) <= getDynArray(heap, pos)){
            swapDynArr(heap, pos, small);
            _adjustHeap(heap, max, small);
        }
    } else if(leftChild < max){ // one child, you can only percolate left
        if(getDynArray(heap, leftChild) <= getDynArray(heap, pos)){
            swapDynArr(heap, pos, leftChild);
            _adjustHeap(heap, max, leftChild);
        }
    }
    return;
}


// WORKSHEET 34: BuildHeap and Heap Sort

/// make an already existing array into a heap
// O(n log n)
void buildHeap(struct dyArray *heap){
    int max = dyArraySize(heap);
    
    for(int i = max/2 -1; i >= 0; i--){ // i = max/2 - 1 = first non leaf node, leaf nodes are already heaps
        _adjustHeap(heap, max, i); // percolate this subtree down (up to but not inclusive of max);
    } // decrement i and repeat until we process the root
    return;
}


// sort in descending order
// O(n log n)
void heapsort(struct dyArray *v){
    buildHeap(v); // turn arbitrary array into a heap
    for(int i = dyArraySize(v) - 1; i > 0; i--){
        dyArraySwap(v, 0, i); // swap first and last elemenets
        _adjustHeap(v, i, 0); // adjust from first to last (not inclusive of last)
    } // repeat but decrement last each time
    return;
}


// WORKSHEET 36: Dynamic Array Dictionary