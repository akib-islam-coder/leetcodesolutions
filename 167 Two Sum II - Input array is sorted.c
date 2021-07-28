

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize)
{
    int * ret_arr = (int *)malloc(sizeof(int)* 2);
    int ret_arr_index = 0;
    bool match = false;
    int i=0;
    for(i=0; i<numbersSize-1; i++)
    {
        int search_element = target - numbers[i];     
        int low = i+1;
        int high = numbersSize - 1;
        while(low <= high)
        {
            int mid = (low + high)/2;
        
            if(numbers[mid] == search_element)
            {
                ret_arr[0] = i+1;
                ret_arr[1] = mid+1;
                match = true;
                break;
            }
            else if(search_element <= numbers[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        
        if(match == true)
            break;
    }
    *returnSize = 2;
    return ret_arr;
}