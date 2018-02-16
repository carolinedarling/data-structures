// BuildHeap and Heap Sort

void buildHeap(struct dyArray *heap){
    int max = dyArraySize(heap);
    
    for(int i = (max/2-1); i >= 0; i--){
        _adjustHeap(heap, max, i);
    }
    return;
}

void heapsort(struct dyArray *v){
    buildHeap(v);
    for(int i = dyArraySize(v) - 1; i > 0; i--){
        dyArraySwap(v, 0, i);
        _adjustHeap(v, i, 0);
    }
    
    return;
}