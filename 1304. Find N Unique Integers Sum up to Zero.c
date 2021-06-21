/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sumZero(int n, int* returnSize)
{
    int * ret_arr  = (int *)malloc(sizeof(int)*n);
    int ret_arr_index = 0;
    int i=0;
    for(i=0; i<=n/2; i++)
    {
        
        if(i==0)
        {
            if(n%2 != 0)    //Odd numbers
            {
                ret_arr[ret_arr_index++] = i;
            }
        }
        else
        {
            ret_arr[ret_arr_index++] = i;
            ret_arr[ret_arr_index++] = (-1 * i);
        }
   
    }
    *returnSize = ret_arr_index;
    return ret_arr;
    
}