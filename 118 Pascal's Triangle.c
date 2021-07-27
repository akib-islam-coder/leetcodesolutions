

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes)
{
    int ** ret_arr = (int **)malloc(sizeof(int *) * numRows);
    int ret_arr_index = 0;
    int prev_index = 0;
    
    //Ret_col_size allocate
    int * ret_col = (int *)malloc(sizeof(int) * numRows);
    int ret_col_index = 0;
    *returnColumnSizes = ret_col;
    
    int i=0;
    for(i=0; i<numRows; i++)
    {
        int * tmp_arr = (int *)malloc(sizeof(int) * (i+1));
        int tmp_arr_index = 0;
        
        if(i == 0)
        {
            tmp_arr[tmp_arr_index] = 1;
            ret_col[ret_col_index++] = 1;         
        }
        else if(i == 1)
        {
            tmp_arr[tmp_arr_index++] = 1;
            tmp_arr[tmp_arr_index++] = 1;
            ret_col[ret_col_index++] = 2;
        }
        else
        {
            tmp_arr[tmp_arr_index++] = 1;
            
            int j=0;
            for(j=1; j<prev_index; j++)
            {
                tmp_arr[tmp_arr_index++] = ret_arr[ret_arr_index-1][j-1] + ret_arr[ret_arr_index-1][j];
            }
            
            tmp_arr[tmp_arr_index++] = 1;
            ret_col[ret_col_index++] = 1 + prev_index;
        }
        
        prev_index++;
        ret_arr[ret_arr_index++] = tmp_arr;
    }
    *returnSize = ret_arr_index;
    return ret_arr;
    
}