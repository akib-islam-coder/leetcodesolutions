/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* replaceElements(int* arr, int arrSize, int* returnSize)
{
    int * ret_arr = (int *)malloc(sizeof(int) * arrSize);
    int ret_arr_index = arrSize-1;
    int i=0;
    int max = INT_MIN;
    
    for(i=arrSize-1; i>=0; i--)
    {
        if(i==arrSize-1)
        {
            max = arr[i];
            ret_arr[ret_arr_index--] = -1;
            continue;
        }
        ret_arr[ret_arr_index--] = max;
        if(arr[i] >= max)
        {
            max = arr[i];
        }
           
    }
    *returnSize = arrSize;
    return ret_arr;
}