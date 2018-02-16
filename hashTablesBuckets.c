// Hash Tables using Buckets

struct hlink {
    TYPE value;
    struct hlink *next;
};

struct hashTable {
    struct hlink **table;
    int tablesize;
    int count;
};


void initHashTable(struct hashTable *ht, int size){
    if(ht == NULL){
        return;   
    }   
    ht->table = (hlink**)malloc(sizeof(hlink*)*tablesize);
    ht->tablesize = size;
    ht->count = 0;
    for(int index = 0; index < tablesize; index++){
        ht->table[index] = 0;
    }

    return;
}


int sizeHashTable(struct hashTable *ht){
    return ht->count;
}



void _resizeTable(struct hashTable *ht){
    int oldts = ht->tablesize;
    hlink *cur, *last;
    
    initHashTable(ht, 2*oldts);
    for(int i = 0; i < oldts; i++){
        cur = ht->table[i];
        while(cur != 0){
            addHashTable(ht, cur->value);
            last = cur;
            cur = cur->next;
            free last;
        }
    }
    free(oldTable); //what
    return;
}


void addHashTable(struct hashTable *ht, TYPE newValue){
    int hash = HASH(newValue);
    int hashIndex = (int) (labs(hash) % ht.tablesize);
    struct hlink *newLink = (struct hlink *)malloc(sizeof(struct hlink));
    assert(newLink);
    newLInk->value = newValue;
    // to be continued
}


