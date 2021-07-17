

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize)
{
    int i = 0;
    int carry = 1;
    
    for(i=digitsSize-1; i>=0; i--)
    {
        int sum = digits[i] + carry;
        if(sum > 9)
        {
            carry = 1;
            digits[i] = sum % 10;
        }
        else
        {
            carry = 0;
            digits[i] = sum;
        }
    }
    
    int * ret_arr = (int *)malloc(sizeof(int) * (carry + digitsSize));
    
    if(carry == 1)
    {
        ret_arr[0] = carry;
        memcpy(&ret_arr[1], digits, sizeof(int) * digitsSize);
    }
    else
    {
        memcpy(&ret_arr[0], digits, sizeof(int) * digitsSize);
    }
    *returnSize = (carry + digitsSize);
    return ret_arr;
}