

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** imageSmoother(int** img, int imgSize, int* imgColSize, int* returnSize, int** returnColumnSizes)
{
    int i=0, j=0;
    int colSize = *imgColSize;
    
    int ** ret_arr = (int **)malloc(sizeof(int *) * imgSize);
    int ret_arr_index = 0;
    
    int smoother_arr[8] = {0};
    int smoother_arr_index = 0;
    
    for(i=0; i<imgSize; i++)
    {
        int * tmp_arr = (int *)malloc(sizeof(int) * (*imgColSize));
        int tmp_arr_index = 0;
        ret_arr[ret_arr_index++] = tmp_arr;
        for(j=0; j<colSize; j++)
        {
            memset(smoother_arr, 0x00, sizeof(smoother_arr));
            smoother_arr_index = 0;
            if(i-1 >=0 && j-1 >= 0)
            {
                smoother_arr[smoother_arr_index++] = img[i-1][j-1];
            }
            
            if(i-1>=0 && j>=0)
            {
                smoother_arr[smoother_arr_index++] = img[i-1][j];
            }
            
            if(i-1>=0 && j+1 < colSize)
            {
                smoother_arr[smoother_arr_index++] = img[i-1][j+1];
            }
            
            if(i >= 0 && j-1 >= 0)
            {
                smoother_arr[smoother_arr_index++] = img[i][j-1];
            }
            
            if(i >=0 && j+1 < colSize)
            {
                smoother_arr[smoother_arr_index++] = img[i][j+1];
            }
            
            if(i+1 < imgSize && j-1 >= 0)
            {
                smoother_arr[smoother_arr_index++] = img[i+1][j-1];
            }
            
            if(i+1 < imgSize && j >= 0)
            {
                smoother_arr[smoother_arr_index++] = img[i+1][j];
            }
            
            if(i+1 < imgSize && j+1 < colSize)
            {
                smoother_arr[smoother_arr_index++] = img[i+1][j+1];
            }
            
            int k = 0;
            int sum = 0;
            for(k=0; k<smoother_arr_index; k++)
            {
                sum += smoother_arr[k];
            }
            tmp_arr[tmp_arr_index++] = (sum + img[i][j])/(smoother_arr_index + 1);     
        }
    }
    
    int * col_arr = (int *)malloc(sizeof(int) * imgSize);
    for(i=0; i<imgSize; i++)
    {
        col_arr[i] = *imgColSize;
    }
    
    *returnColumnSizes = col_arr;
    *returnSize = imgSize;
    return ret_arr;

    
}