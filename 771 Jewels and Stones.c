int hash_table[256] = {0};

int numJewelsInStones(char * jewels, char * stones)
{
    memset(hash_table, 0x00, sizeof(hash_table));
    
    int i=0;
    while(jewels[i]!='\0')
    {
        hash_table[jewels[i]] = 1;
        i++;
    }
    
    i=0;
    int sum = 0;
    
    while(stones[i]!='\0')
    {
        if(hash_table[stones[i]] == 1)
        {
            sum += 1;
        }
        i++;
    }
    return sum;
}