

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes)
{
    int ** ret_arr = (int **)malloc(sizeof(int *) * (*matrixColSize));
    int ret_arr_index = 0;
    
    int i=0, j=0;
    for(i=0; i<(*matrixColSize); i++)
    {
        int * tmp_arr = (int *)malloc(sizeof(int) * matrixSize);
        ret_arr[ret_arr_index++] = tmp_arr;
    }
    
    for(i=0; i<matrixSize; i++)
    {
        for(j=0; j< *matrixColSize; j++)
        {
            ret_arr[j][i] = matrix[i][j];
        }
    }
    *returnSize = (*matrixColSize);
    
    int * ret_col_arr = (int *)malloc(sizeof(int) * (*matrixColSize));
    for(i=0; i< *matrixColSize; i++)
    {
        ret_col_arr[i] = matrixSize;
    }
    *returnColumnSizes = ret_col_arr;
    return ret_arr;
    
}