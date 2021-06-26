int hashtable1[1001] = {0};
int hashtable2[1001] = {0};

bool canBeEqual(int* target, int targetSize, int* arr, int arrSize)
{
    memset(hashtable1, 0x00, sizeof(hashtable1));
    memset(hashtable2, 0x00, sizeof(hashtable2));
    
    int i=0;
    for(i=0; i<targetSize; i++)
    {
        hashtable1[target[i]] += 1;
    }
    
    for(i=0; i<arrSize; i++)
    {
        hashtable2[arr[i]] += 1;
    }
    
    bool matches = true;
    
    //Compare both the hashtable, if they matches then there must be a way to match them by reversing target array
    for(i=0; i<1001; i++)
    {
        if(hashtable1[i] != hashtable2[i])
        {
            matches = false;
            break;
        }
    }
    return matches;
}