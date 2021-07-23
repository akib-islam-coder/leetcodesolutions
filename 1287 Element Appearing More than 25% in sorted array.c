int hashtable[100001] = {0};

int findSpecialInteger(int* arr, int arrSize)
{
    memset(hashtable, 0x00, sizeof(hashtable));
    int i=0;
    for(i=0; i<arrSize; i++)
    {
        hashtable[arr[i]] += 1;
    }
    
    int ret_num = -1;
    int count_num = (arrSize/4);
    int max = INT_MIN;
    for(i=0; i<=arr[arrSize-1]; i++)
    {
        if(hashtable[i] >= count_num)
        {
            if(hashtable[i] >= max)
            {
                max = hashtable[i];
                ret_num = i;
            }
        }
    }
    return ret_num;
    
}