int hashtable[501] = {0};

int findLucky(int* arr, int arrSize)
{
    memset(hashtable, 0x00, sizeof(hashtable));
    
    int i=0;
    for(i=0; i<arrSize; i++)
    {
        hashtable[arr[i]] += 1;
    }
    
    int count = 0;
    for(i=0; i<501; i++)
    {
        if(hashtable[i] == i)
        {
            count = i;
        }
    }
    
    if(count == 0)
        return -1;
    return count;
    
} 