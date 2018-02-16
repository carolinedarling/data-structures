
/* Binary Search Tree Iterator

            1
          /   \
         2     3
       /  \
      4    5
      
(a) Preorder (Root, Left, Right) : 1 2 4 5 3   EULER LEFT SIDE
(b) Inorder (Left, Root, Right) : 4 2 5 1 3    EULER BOTTOM SIDE
(c) Postorder (Left, Right, Root) : 4 5 2 3 1  EULER RIGHT SIDE


*/

struct BSTIterator {
    struct DynArr *stk;
    struct BSTree *tree;
};

void BSTIteratorInit(struct BSTree *tree, struct BSTIterator *itr){
    itr->tree = tree;
    itr->stk = newDynArr(); //Dyn Arr imp of stack
    return;
}

void slideLeft (Node n){
    while(n != NULL){
        pop(n); // onto the stack
        n = n->left;
    }
    return;
}

    
int BSTIteratorHasNext(struct BSTIterator *itr){
    BNode *n;
    
    if(isEmptyDynArr(itr->stk)){ // if the stack is completely empty
        slideLeft(itr->tree->root);
    } else {
        n = topDynArr(itr->stk); //put n on top of the stack
        popDynArr(itr->stk); // pop the first one on stack
        slideLeft(n->right); // slide left on its right child
    }
    
    if(!isEmptyDynArr(itr->stk)){
        return 1;
    } else {
        return 0;
    }
    
}


TYPE BSTIteratorNext(struct BSTIterator *itr){
    return(topDynArr(itr->stk))->val;
}


void _slideLeft(struct Node *cur, struct BSTIterator *itr){
    while(cur->left != NULL){
        dynArrayPush(itr->stk, cur);
        cur = cur->left;
    }
    return;
}