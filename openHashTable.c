// Open Address Hashing -- HashTables

struct openHashTable {
    TYPE **table;
    int tablesize;
    int count;
};

void initOpenHashTable(struct openHasthTable *ht, int size){
    assert(size > 0);
    ht->table = (TYPE **)malloc(size *sizeof(TYPE *));
    assert(ht->table != 0);
    for(int i = 0; i < size; i++){
            ht->table[i] = 0; // initialize empty;
    }
    ht->tablesize = size;
    ht->count = 0;
    
    return;
}


int openHashTableSize(struct openHashTable *ht){
    return ht->count;
}


void openHashTableAdd(struct openHashTable *ht, TYPE *newValue){
    int indx;
    
    // Make sure we have space and are under the load factor threshold:
    if((ht->count / (double)ht->tablesize) > 0.75){
        _resizeOpenHashTable(ht);
    }
    
    ht->count++;
    idx = HASH(newValue) % ht->tableSize;
    
    if(idx < 0){
        idx += ht->tablesize; // only use positive arithmetic!!
    }
    
    while(idx >= 0){
        if(idx == ht->tablesize){
            idx = 0;
        }
        
        if(ht->table[idx] == 0){
            ht->table[idx] = newValue;
            idx = -1;
        } else {
            idx++;
        }
    }
    return;
}

int openHashTableContains(struct openHashTable *ht, TYPE newValue){
    int idx;
    idx = HASH(newValue) % ht->tablesize;
    if(idx < 0){
        idx += ht->tablesize;
    }
    
    while(ht->table[idx] != 0){
        if(compare(ht->table[idx], newValue) == 0) {
            return 1; // found it
        }
        idx++;
        
        if(idx == ht->tableSize){
            idx = 0; //didn't find it break while loop
        }
    }
    return 0; // didn't find it
}

void _resizeOpenHasthTable(struct openHashTable *ht){
    int oldSize = ht->tablesize;
    int newSize = 2 * oldSize;
    TYPE **temp = ht->table;
    initOpenHashTable(ht, newSize); // create a new table
    
    // copy everything over to the new table
    for(int i = 0; i < oldSize; i++){
        if(temp[i] != 0){
            openHashTableAdd(ht, temp[i]);
        }
        // ht = temp ?????
        free(temp);
    }
    return;
}