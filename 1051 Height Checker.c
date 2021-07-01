void Merge(int arr[], int low, int mid, int high)
{
    int * aux_arr = (int *)malloc(sizeof(int) * (high-low+1));
    int aux_arr_index = 0;
    
    int i=low;
    int j=mid+1;
    
    for(i=low, j=mid+1; i<=mid && j<=high; )
    {
        if(arr[i] <= arr[j])
        {
            aux_arr[aux_arr_index++] = arr[i];
            i++;
        }
        else
        {
            aux_arr[aux_arr_index++] = arr[j];
            j++;
        }
    }
    
    while(i<=mid)
    {
        aux_arr[aux_arr_index++] = arr[i++];
    }
    
    while(j<=high)
    {
        aux_arr[aux_arr_index++] = arr[j++];
    }
    
    memcpy(&arr[low], aux_arr, sizeof(int) * (high-low+1));
    free(aux_arr);
}

void merge_sort(int arr[], int low, int high)
{
    if(low < high)
    {
        int mid = (low+high)/2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid+1, high);
        Merge(arr, low, mid, high);
    }
}

int heightChecker(int* heights, int heightsSize)
{
    //Applying merge sort to sort the height
    int * sort_arr = (int *)malloc(sizeof(int) * heightsSize);
    memcpy(sort_arr, heights, sizeof(int)*heightsSize);
    
    merge_sort(sort_arr, 0, heightsSize-1);
    
    int i=0;

    int count = 0;
    for(i=0; i<heightsSize; i++)
    {
        if(heights[i] != sort_arr[i])
            count++;
    }
    return count;
}
