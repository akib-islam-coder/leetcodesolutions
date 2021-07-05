

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shortestToChar(char * s, char c, int* returnSize)
{
    int len = strlen(s);
    int * ret_arr = (int *)malloc(sizeof(int) * len);
    memset(ret_arr, 1, sizeof(int) * len);
    int ret_arr_index = 0;
    
    int i=0;
    while(s[i]!='\0')
    {
        if(s[i] == c)
        {
            ret_arr[ret_arr_index++] = 0;
        }
        else
        {
            ret_arr_index++;
        }
        i++;
    }
    
    //Sliding window on 0
    int start_index = 0;
    int end_index = 0;
    ret_arr_index = 0;
    int prev_index = -1;
    
    for(end_index=0; end_index<len; )
    {
        if(s[end_index]!=c)
        {
            end_index++;
        }
        
        if(s[end_index] == c && start_index < end_index)
        {
            if(prev_index == -1)
            {
                ret_arr[ret_arr_index++] = (end_index - start_index);
                start_index++;
            }
            else
            {
                printf("start_index: %d\r\n", start_index);
                int diff1 = start_index - prev_index;
                int diff2 = end_index - start_index;
                if(diff1 >= diff2)
                {
                    ret_arr[ret_arr_index++] = diff2;
                }
                else
                {
                    ret_arr[ret_arr_index++] = diff1;
                }
                start_index++;
            }
        }
        
        if(start_index == end_index)
        {
            prev_index = start_index;
            end_index++;
            start_index++;
            ret_arr_index++;
        }
    }
    
    while(start_index < end_index)
    {

            int diff1 = start_index - prev_index;
            ret_arr[ret_arr_index++] = diff1;
            start_index++;

    }
    
    *returnSize = ret_arr_index;
    return ret_arr;
    

    
    
}