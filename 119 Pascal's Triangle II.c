

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize)
{
    int * ret_arr = (int *)malloc(sizeof(int) * (rowIndex+1));
    int ret_arr_index = 0;
    
    int ** tmp_ptr = (int **)malloc(sizeof(int *) * (rowIndex+1));
    int tmp_ptr_index = 0;
    
    int last_row_index = 0;
    int i=0;
    for(i=0; i<=rowIndex; i++)
    {
        if(i==0)
        {
            int * new_arr = (int *)malloc(sizeof(int) *(i+1));
            tmp_ptr[tmp_ptr_index++] = new_arr;
            new_arr[0] = 1;
        }
        else if(i == 1)
        {
            int k=0;
            int * new_arr = (int *)malloc(sizeof(int) * (i+1));
            int new_arr_index = 0;
            tmp_ptr[tmp_ptr_index++] = new_arr;
            for(k=0; k<=i; k++)
            {           
                new_arr[new_arr_index++] = 1;
            }
        }
        else
        {
            int k=0;
            int * new_arr = (int *)malloc(sizeof(int) * (i+1));
            int new_arr_index = 0;
            tmp_ptr[tmp_ptr_index++] = new_arr;
            for(k=0; k<=i; k++)
            {               
               if(k==0 || k==i)
               {
                   new_arr[new_arr_index++] = 1;
               }               
               else
               {
                    new_arr[new_arr_index++] = tmp_ptr[tmp_ptr_index-2][k-1] + tmp_ptr[tmp_ptr_index-2][k];
               }
            }
        }
    }
    
    memcpy(ret_arr, &tmp_ptr[tmp_ptr_index-1][0], sizeof(int) * tmp_ptr_index);
    *returnSize = tmp_ptr_index;
     return ret_arr;
    
    
}