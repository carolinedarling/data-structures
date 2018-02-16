// Dynamic Array Dictionary


struct association {
    KEYTYPE key;
    VALUETYPE value;
};

void dyArrayDictionaryPut(struct dynArray *da, KEYTYPE key, VALUETYPE val){
    struct association *ap;
    
    if(dyArrayDictionaryContainsKey(da, key)){
        dyArrayDictionaryRemoveKey(da, key);
    }
    
    ap = (struct association *)malloc(sizeof(struct association));
    assert(ap != 0);
    ap->key = key;
    ap->value = val;
    dyArrayAdd(da, ap);
    
    return;
}

void dyArrayDictionaryGet(struct dynArray *da, KEYTYPE key, VALUETYPE *valptr){
    for(int i = 0; i < da->size; i++){
        if(strcmp(da->data[i]->key, key) == 0){
            *valptr = da->data[i]->value;
        }
    }
    return;
}

int dyArrayDictionaryContainsKey(struct dynArray *da, KEYTYPE key){
    for(int i = 0; i < da->size, i++){
        if(strcmp(key, da->data[i]->key) == 0){
            return 1;   //found it
        }
        return 0; // didn't find it
    }
}

void dyArrayDictionaryRemove(struct dynArray *da, KEYTYPE key){
    struct association *ap;
    for(int i = 0; i < da->size; i++){
        if(strcmp(key, da->data[i]->key) == 0){ // if the key exists in the dictionary, remove it
            struct association *temp;
            temp = da0>datap[i];
            removeAtDynArr(da, i);
            free(temp);
            break;
        }
    }
    return;
}