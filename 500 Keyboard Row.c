int hashtable[26] = {2, 3, 3, 2, 1, 2, 2, 2, 1, 2, 2, 2, 3, 3, 1, 1, 1, 1, 2, 1, 1, 3, 1, 3, 1, 3};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** findWords(char ** words, int wordsSize, int* returnSize)
{
    
    char ** ret_arr = (char **)malloc(sizeof(char *) * wordsSize);
    int ret_arr_index = 0;
    
    int i=0;
    int j=0;
    for(i=0; i<wordsSize; i++)
    {
        int row = 0; 
        if(words[i][0] >= 'a' && words[i][0] <= 'z')
        {
            row = hashtable[words[i][0] - 'a'];
        }
        else
        {
            row = hashtable[words[i][0] - 'A'];                    
        }
        bool match = true;

        
        for(j=1; j<strlen(words[i]); j++)
        {
            int alphabet = 0;
            if(words[i][j] >= 'a' && words[i][j] <= 'z')
            {
                alphabet = hashtable[words[i][j] - 'a'];
            }
            else
            {
                alphabet = hashtable[words[i][j] - 'A'];
            }
            
            if(alphabet != row)
            {
                match = false;
                break;
            }
        }
        
        if(match)
        {
           char * arr = (char *)malloc(sizeof(char) * (strlen(words[i]) + 1));
           memcpy(arr, words[i], sizeof(char) * (strlen(words[i]) + 1));
           ret_arr[ret_arr_index++] = arr; 
        }
    }
    *returnSize = ret_arr_index;
    return ret_arr;
}