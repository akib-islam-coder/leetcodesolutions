/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* decode(int* encoded, int encodedSize, int first, int* returnSize)
{
    uint32_t * ret_arr = (uint32_t *)malloc(sizeof(uint32_t) * (encodedSize + 1));
    int ret_arr_index = 0;
    
    ret_arr[ret_arr_index++] = first;
    int i=0;
    for(i=0; i<encodedSize; i++)
    {
        ret_arr[ret_arr_index++] = first ^ encoded[i];
        first = ret_arr[ret_arr_index-1];
    }
    *returnSize = ret_arr_index;
    return ret_arr;
}