
int hashtable[26] = {0};

bool checkIfPangram(char * sentence)
{
    int i=0;
    memset(hashtable, 0x00, sizeof(hashtable));
    while(sentence[i] != '\0')
    {
        int index = (sentence[i] - 'a')%26;
        hashtable[index] = 1;
        i++;    
    }
    
    i=0;
    bool ispangram = true;
    
    while(i<26)
    {
        if(hashtable[i] == 0)
        {
            ispangram = false;
            break;
        }
        i++;
    }
    return ispangram;
}