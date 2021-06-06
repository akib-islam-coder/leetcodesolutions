#define NO_OF_ELEMENTS 101

int hash_table[NO_OF_ELEMENTS] = {0};

double factorial(double num)
{
    if(num == 0)
        return 1;
    
    return (num * factorial(num-1));
}

/*
*   nCr = (n!)/((n-r)! * r!)
*/
double cal_combination(double num)
{
    if(num == 1)
        return 0;
    
    double n_fact = factorial(num);
    double n_r_fact = factorial(num - 2);
    double r_fact = factorial(2);
    
    return (n_fact/(r_fact * n_r_fact));
    
}

int numIdenticalPairs(int* nums, int numsSize)
{
    memset(hash_table, 0, sizeof(hash_table));
    int i=0;
    for(i=0; i<numsSize; i++)
    {
        hash_table[nums[i]] += 1;
    }
    
    int no_of_pairs = 0;
    
    for(i=1; i< NO_OF_ELEMENTS; i++)
    {
        if(hash_table[i]>0)
        {
            no_of_pairs += cal_combination(hash_table[i]);
        }

    }
    return no_of_pairs;
}