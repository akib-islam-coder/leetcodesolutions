void merge(int arr[], int low, int mid, int high)
{
    int * ret_arr = (int *)malloc(sizeof(int) * (high-low+1));
    int ret_arr_index = 0;
    
    int i=0,j=0;
    for(i=low, j=mid+1; i<=mid && j<=high;)
    {
        if(arr[i] <= arr[j])
        {
            ret_arr[ret_arr_index++] = arr[i++];
        }
        else
        {
            ret_arr[ret_arr_index++] = arr[j++];
        }
    }
    
    while(i<=mid)
    {
        ret_arr[ret_arr_index++] = arr[i++];
    }
    
    while(j<=high)
    {
        ret_arr[ret_arr_index++] = arr[j++];
    }
    
    memcpy(&arr[low], ret_arr, sizeof(int)*(high-low+1));
    free(ret_arr);
}

void merge_sort(int arr[], int low, int high)
{
    if(low < high)
    {
        int mid = (low+high)/2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}

bool canMakeArithmeticProgression(int* arr, int arrSize)
{

    //Sort the array
    merge_sort(arr, 0, arrSize-1);
    
    int i=0;
    int diff = arr[1] - arr[0];
    
    for(i=2; i<arrSize; i++)
    {
        if(arr[i] - arr[i-1] != diff)
            return false;
    }
    return true;
}