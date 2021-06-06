

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize)
{
    int max_candy = 0;
    
    int i=0;
    for(i=0; i<candiesSize; i++)
    {
        if(candies[i] >= max_candy)
            max_candy = candies[i];
    }
    printf("max candy : %d", max_candy);
    
    bool * ret_arr = (bool *)malloc(sizeof(bool)*candiesSize);
    int ret_arr_index = 0;
    
    for(i=0; i<candiesSize; i++)
    {
        if(candies[i] + extraCandies >= max_candy)
        {
            ret_arr[ret_arr_index++] = true;
        }
        else
        {
            ret_arr[ret_arr_index++] = false;
        }
    }
    *returnSize = ret_arr_index;
    return ret_arr;
    
}