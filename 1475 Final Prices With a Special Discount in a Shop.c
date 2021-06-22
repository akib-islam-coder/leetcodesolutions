

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* finalPrices(int* prices, int pricesSize, int* returnSize)
{
    int * ret_arr = (int *)malloc(sizeof(int) * pricesSize);
    int ret_arr_index = 0;
    
    int i=0;
    for(i=0; i<pricesSize; i++)
    {
        int original_price = prices[i];
        int discount_amount = 0;
        
        int j=0;
        if(i+1 != pricesSize)
        {
            for(j=i+1; j<pricesSize; j++)
            {
                if(prices[j] <= original_price)
                {
                    discount_amount = prices[j];
                    break;
                }
            }
        }
        ret_arr[ret_arr_index++] = original_price - discount_amount;
    }
    *returnSize = ret_arr_index;
    return ret_arr;
}