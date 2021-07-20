
typedef struct 
{
   int hashtable[1000001];
} MyHashSet;



/** Initialize your data structure here. */

MyHashSet* myHashSetCreate() 
{
    MyHashSet * obj = (MyHashSet *)malloc(sizeof(MyHashSet));
    int i=0;
    for(i=0; i<1000001; i++)
    {
        obj->hashtable[i] = 0;
    }
    return obj;
}

void myHashSetAdd(MyHashSet* obj, int key) 
{

    if(obj->hashtable[key] == 0)
    {

        obj->hashtable[key] = 1;
    }
}

void myHashSetRemove(MyHashSet* obj, int key) 
{

    if(obj->hashtable[key] == 1)
    {
        obj->hashtable[key] = 0;
    }
}

/** Returns true if this set contains the specified element */
bool myHashSetContains(MyHashSet* obj, int key)
{

    if(obj->hashtable[key] == 1)
    {
        return true;
    }
    else
        return false;
}

void myHashSetFree(MyHashSet* obj) 
{
    free(obj);
}

/**
 * Your MyHashSet struct will be instantiated and called as such:
 * MyHashSet* obj = myHashSetCreate();
 * myHashSetAdd(obj, key);
 
 * myHashSetRemove(obj, key);
 
 * bool param_3 = myHashSetContains(obj, key);
 
 * myHashSetFree(obj);
*/