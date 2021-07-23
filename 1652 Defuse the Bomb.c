

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* decrypt(int* code, int codeSize, int k, int* returnSize)
{
    int * ret_arr = (int *)malloc(sizeof(int) * codeSize);
    int ret_arr_index = 0;
    int i=0;
    int next_k_sum = 0;
    int prev_k_sum = 0;
    int cur_k = 0;
   
    
    if(k == 0)
    {
        for(i=0; i<codeSize; i++)
        {
            ret_arr[ret_arr_index++] = 0;
        }
    }
    else if(k > 0)
    {
         for(i=0; i<k; i++)
         {
            next_k_sum += code[i];
            cur_k++;
         }
        
        
        for(i=0; i<codeSize; i++)
        {
            if(cur_k == codeSize)
            {
                cur_k = 0;
            }     
            next_k_sum = next_k_sum - code[i] + code[cur_k++];
            
            ret_arr[ret_arr_index++] = next_k_sum;
        }
    }
    else if(k < 0)
    {
        int pos_k = (k * -1);
        int start_index = codeSize - pos_k;
        int end_index;
        for(end_index= codeSize - pos_k; end_index< codeSize; end_index++)
        {
            next_k_sum += code[end_index];
        }
        
        for(i=0; i<codeSize; i++)
        {   
            ret_arr[ret_arr_index++] = next_k_sum;
            
            if(end_index == codeSize)
            {
                end_index = 0;
            } 
            
            if(start_index == codeSize)
            {
                start_index = 0;
            }
            next_k_sum = next_k_sum - code[start_index++] + code[end_index++];
         } 
        
    }
    *returnSize = ret_arr_index;
    return ret_arr;
}