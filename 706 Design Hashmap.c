#define MAX_VAL 1000001


typedef struct 
{
    int arr[MAX_VAL];
} MyHashMap;

/** Initialize your data structure here. */

MyHashMap* myHashMapCreate() 
{
    MyHashMap * obj = (MyHashMap *)malloc(sizeof(MyHashMap));
    int i=0;
    for(i=0; i<MAX_VAL; i++)
    {
        obj->arr[i] = -1;
    }
    return obj;
}

/** value will always be non-negative. */
void myHashMapPut(MyHashMap* obj, int key, int value) 
{
    obj->arr[key] = value;
}

/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
int myHashMapGet(MyHashMap* obj, int key) 
{
    return obj->arr[key];
}

/** Removes the mapping of the specified value key if this map contains a mapping for the key */
void myHashMapRemove(MyHashMap* obj, int key) 
{
    if(obj->arr[key] == -1)
        return;
    else
        obj->arr[key] = -1;
    return;
}

void myHashMapFree(MyHashMap* obj) 
{
    free(obj);
}

/**
 * Your MyHashMap struct will be instantiated and called as such:
 * MyHashMap* obj = myHashMapCreate();
 * myHashMapPut(obj, key, value);
 
 * int param_2 = myHashMapGet(obj, key);
 
 * myHashMapRemove(obj, key);
 
 * myHashMapFree(obj);
*/