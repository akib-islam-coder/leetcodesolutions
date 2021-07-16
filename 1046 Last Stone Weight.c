void merge(int arr[], int low, int mid, int high)
{
    int * tmp_arr = (int *)malloc(sizeof(int) * (high - low + 1));
    int tmp_arr_index = 0;
    
    int i=0, j=0;
    for(i=low, j=mid+1; i<=mid && j<=high; )
    {
        if(arr[i] >= arr[j])
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


void merge_sort(int arr[], int low, int high)
{
    if(low < high)
    {
        int mid = (low + high)/2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid+1, high);
        merge(arr, low, mid, high); 
    }
}

int lastStoneWeight(int* stones, int stonesSize)
{
    merge_sort(stones, 0, stonesSize-1);
    
    int i=0;
    int prev_item = stones[0];
    for(i=1; i<stonesSize; )
    {
        if(stones[i] > prev_item)
        {
            prev_item = stones[i] - prev_item;
            stones[i] = prev_item;
            merge_sort(&stones[i], 0, stonesSize-1-i);
            prev_item = stones[i];
            i++;
        }
        else if(stones[i] == prev_item)
        {
            if(i+1 >= stonesSize)
            {
                prev_item = 0;
            }
            else
            {
                prev_item = stones[++i];
            }
            i++;
        }
        else
        {
            prev_item = prev_item - stones[i];
            stones[i] = prev_item;
            merge_sort(&stones[i], 0, stonesSize-1-i);
            prev_item = stones[i];
            i++;
        }
    }
    return prev_item;
    
}