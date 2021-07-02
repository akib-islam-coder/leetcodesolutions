#define ARR_SIZE 2001
int hashtable[ARR_SIZE] = {0};
int num_of_duplicates[ARR_SIZE] = {0};

bool uniqueOccurrences(int* arr, int arrSize)
{
    memset(hashtable, 0x00, sizeof(hashtable));
    memset(num_of_duplicates, 0x00, sizeof(num_of_duplicates));
    int i=0;
    for(i=0; i<arrSize; i++)
    {
        if(arr[i] < 0)
        {
            int num = (-1 * arr[i]);
            hashtable[num] += 1;
        }
        else if(arr[i] == 0)
        {
            hashtable[arr[i]] += 1;
        }
        else if(arr[i] > 0)
        {
            hashtable[arr[i]+1000] += 1;
        }
    }
    
    for(i=0; i<ARR_SIZE; i++)
    {
        num_of_duplicates[hashtable[i]] += 1;
    }
    
    for(i=1; i<ARR_SIZE; i++)
    {
        if(num_of_duplicates[i] > 1)
            return false;
    }
    
    return true;
}