// Heaps and priority cues


void HeapRemoveMin(struct dyArray *heap){
    int last = dyArraySize(heap) - 1;
    assert(last != 0);
    
    // copy the last element ot the first position
    dyArrayPut(heap, 0, dyArrayGet(heap, last));
    // remove last element
    dyArrayRemoveAt(heap, last);
    // percolate down
    _adjustHeap(heap, last-1, 0);
    
    return;
}


void addHeap(DynArr *heap, TYPE val){
    int parent;
    int pos = sizeDynArr(heap);
    addDyneArr(heap, val);
    
    while(pos != 0){
        parent = (pos-1)/2;
        if(compare(getDynArr(heap, pos) getDynArr(heap, parent) == -1){ // if pos is less than parent
            swapDynArr(heap, parent, pos);
            pos = parent;
        } else {
            return;
        }
    }
}

void _adjustHeap(DynArr *heap, int max, int pos){
    int left, right, small;
    assert(max < sizeDynArr(heap));
    left = 2*pos + 1; // leftchild is 2i+1 in the array
    right = 2*pos + 1; // right child is 2i+2 in the array
    
    if(right < max){ // there are 2 children 
        small = _smallerIndexHeap(heap, left, right);
        if(compare(getDynArr(heap, small), getDynArr(heap, pos) == -1)){ // if small < position
            swapDynArr(heap, pos, small);
            _adjustHeap(heap, max, small);
        }
    } else if(left < max){ // one child
        if(compare(getDynArr(heap, left), getDynArr(heap, pos) == -1)){ //if left < position
            swapDynArr(heap, pos, left);
            _adjustHeap(heap, max, left);
        }
    }
    return;
}