
void Merge(int arr[], int low, int mid, int high)
{
    int * merge_arr = (int *)malloc(sizeof(int) * (high-low+1));
    int merge_arr_index = 0;
    
    int i=low, j=mid+1;
    
    for(i=low, j=mid+1; i<=mid && j<=high;)
    {
        if(arr[i] <= arr[j])
        {
            merge_arr[merge_arr_index++] = arr[i++];
        }
        else
        {
            merge_arr[merge_arr_index++] = arr[j++];
        }
    }
    
    while(i<=mid)
    {
        merge_arr[merge_arr_index++] = arr[i++];
    }
    
    while(j<=high)
    {
        merge_arr[merge_arr_index++] = arr[j++];
    }
    
    memcpy(&arr[low], &merge_arr[0], sizeof(int) * (high-low+1));
    free(merge_arr);
}

int min(int a, int b)
{
    return a<=b ? a : b;
}

void mergeSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int mid = (low + high)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        Merge(arr, low, mid, high);
    }
}

int arrayPairSum(int* nums, int numsSize)
{
    //Sort the nums
    mergeSort(nums, 0, numsSize-1);

    int sum=0;
    int i=0;
    
    
    for(i=0; i<numsSize; i+=2)
    {
        if(i+1 != numsSize)
        {
            sum += min(nums[i], nums[i+1]);
        }
        else
        {
            sum += nums[i];
        }
    }
    return sum;
    
}