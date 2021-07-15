void merge(int arr[], int low, int mid, int high)
{
    int * tmp_arr = (int *)malloc(sizeof(int) * (high - low + 1));
    int tmp_arr_index = 0;
    
    int i=0, j=0;
    for(i=low, j=mid+1; i<=mid && j<=high; )
    {
        if(arr[i] <= arr[j])
        {
            tmp_arr[tmp_arr_index++] = arr[i++];
        }
        else
        {
            tmp_arr[tmp_arr_index++] = arr[j++];
        }
    }
    
    while(i<=mid)
    {
        tmp_arr[tmp_arr_index++] = arr[i++];
    }
    
    while(j<=high)
    {
        tmp_arr[tmp_arr_index++] = arr[j++];
    }
    
    memcpy(&arr[low], tmp_arr, sizeof(int) * tmp_arr_index);
    free(tmp_arr);
}


void merge_sort(int * arr, int low, int high)
{
    if(low < high)
    {
        int mid = (low + high)/2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}

double trimMean(int* arr, int arrSize)
{
    merge_sort(arr, 0, arrSize-1);
    
    int i=0;
    int sum=0;
    for(i=(0.05 * (double)arrSize); i<arrSize - (0.05 * (double)arrSize); i++)
    {
        sum += arr[i];
    }
    return (double)((double)sum / (double)(arrSize - (0.05 * (double)arrSize) - (0.05 * (double)arrSize)));

}