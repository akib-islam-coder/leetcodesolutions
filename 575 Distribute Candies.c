int pos_hashtable[100001] = {0};
int neg_hashtable[100001] = {0};

int distributeCandies(int* candyType, int candyTypeSize)
{   
    memset(pos_hashtable, 0x00, sizeof(pos_hashtable));
    memset(neg_hashtable, 0x00, sizeof(neg_hashtable));
    int i=0;
    for(i=0; i<candyTypeSize; i++)
    {
        if(candyType[i] < 0)
        {
            int val = candyType[i] * -1;
            neg_hashtable[val] += 1;
        }
        else
        {
            pos_hashtable[candyType[i]] += 1;
        }
    }
    
    int unique = 0;
    int max = candyTypeSize/2;
    
    for(i=0; i<100001; i++)
    {
        if(pos_hashtable[i] > 0)
        {
            unique++;
        }
        
        if(unique == max)
            break;
    }
    
    if(unique == max)
        return unique;
    
    for(i=0; i<100001; i++)
    {
        if(neg_hashtable[i] > 0)
        {
            unique++;
        }
        
        if(unique == max)
            break;
    }
    
    return unique;
}