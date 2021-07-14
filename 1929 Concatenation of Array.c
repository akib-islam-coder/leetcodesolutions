

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getConcatenation(int* nums, int numsSize, int* returnSize)
{
    int * ret_arr = (int *)malloc(sizeof(int) * (2*numsSize));

    memcpy(&ret_arr[0], nums, sizeof(int) * numsSize);
    memcpy(&ret_arr[numsSize], nums, sizeof(int) * numsSize);
    *returnSize = (2 * numsSize);
    return ret_arr;
}