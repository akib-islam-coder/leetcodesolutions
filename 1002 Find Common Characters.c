

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** commonChars(char ** words, int wordsSize, int* returnSize)
{
    char ** ret_arr = (char **)malloc(sizeof(char *) * 10000);
    int ret_arr_index = 0;
    int rows = 0;
    int i=0;
    int min_count = INT_MAX;
    int cur_count = 0;
    
    for(i='a'; i<='z'; i++)
    {
        min_count = INT_MAX;
        cur_count = 0;
        for(rows=0; rows<wordsSize; rows++)
        {
            int j=0;
            cur_count = 0;
            while(words[rows][j] != '\0')
            {
                if(words[rows][j] == i)
                {
                    cur_count++;
                }
                j++;
            }

            
            if(cur_count <= min_count)
            {
                min_count = cur_count;
            }
        }
        while(min_count > 0)
        {
            char * new_arr = (char *)malloc(sizeof(char) * 2);
            new_arr[0] = i;
            new_arr[1] = '\0';
            ret_arr[ret_arr_index++] = new_arr;
            min_count--;
        }
    }
    
    *returnSize = ret_arr_index;
    return ret_arr;
}