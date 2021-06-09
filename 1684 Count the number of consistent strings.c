int hash_table[256] = {0};


int countConsistentStrings(char * allowed, char ** words, int wordsSize)
{
    int i=0;
    memset(hash_table, 0, sizeof(hash_table));
    
    while(allowed[i] != '\0')
    {
        hash_table[allowed[i]] = 1;
        i++;
    }
    
    int consistent_str = 0;
    
    i=0;
    for(i=0; i<wordsSize; i++)
    {
        int j=0;
        bool flag = true;
        
        while(words[i][j] != '\0')
        {
            if(hash_table[words[i][j]] == 0)
            {
                flag = false;
                break;
            }
            j++;
        }
        
        if(flag == true)
            consistent_str++;
    }
    return consistent_str;
    
}