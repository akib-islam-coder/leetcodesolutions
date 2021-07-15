int signFunc(int x)
{
    if(x < 0)
        return -1;
    else if(x>0)
        return 1;
    
    return 0;
}

int arraySign(int* nums, int numsSize)
{
    int product = 1;
    int i=0;
    for(i=0; i<numsSize; i++)
    {
        product *= nums[i];
        product =  signFunc(product);
    }
    
    return product;
}