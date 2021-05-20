int hashtable[256] = {0};

int hash_index(int index)
{
    return (index%256);
}

int lengthOfLongestSubstring(char * s)
{
    memset(hashtable, 0, sizeof(hashtable));
    
    int f_index = 0;
    int r_index = 0;
    
    int length = 0;
    int current_len = 0;
    
    int i=0;
    
    while(s[i] != '\0')
    {
        int index = hash_index(s[i]); 
        
        if(hashtable[index] == 0)   //Item not present in hashtable
        {
            int val = hashtable[hash_index(s[r_index])];
            current_len++;
            hashtable[hash_index(s[r_index])] = ++val;
            r_index++;
            i++;
        }
        else    //Item present in hashtable
        {
            int val = hashtable[hash_index(s[f_index])];
            current_len--;
            hashtable[hash_index(s[f_index])] = --val;
            f_index++;
        }
        
        if(current_len > length)
        {
            length = current_len;
        }  
    }
    return length;
}