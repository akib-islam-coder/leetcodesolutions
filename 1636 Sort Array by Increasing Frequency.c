void merge(int arr[], int low, int mid, int high)
{
    int * ret_arr = (int *)malloc(sizeof(int) * (high - low + 1));
    int ret_arr_index = 0;

    int i=low, j=mid+1;
    for(i=low, j=mid+1; i<=mid && j<=high; )
    {
        if(arr[i] >= arr[j])
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

    memcpy(&arr[low], ret_arr, sizeof(int) * (high - low + 1));
    free(ret_arr);
}

void merge_2d(int ** arr, int low, int mid, int high)
{
    int ** ret_arr = (int **)malloc(sizeof(int *) * (high - low + 1));
    int ret_arr_index = 0;

    int i=low, j=mid+1;
    

    for(i=low, j=mid+1; i<=mid && j<=high; )
    {
        if(arr[i][1] <= arr[j][1])
        {
            int * new_arr = (int *)malloc(sizeof(int) * 2);
            new_arr[0] = arr[i][0];
            new_arr[1] = arr[i][1];
            ret_arr[ret_arr_index++] = new_arr;
            i++;
        }
        else
        {
            int * new_arr = (int *)malloc(sizeof(int) * 2);
            new_arr[0] = arr[j][0];
            new_arr[1] = arr[j][1];
            ret_arr[ret_arr_index++] = new_arr;
            j++;
        }
    }
    
    while(i<=mid)
    {
        int * new_arr = (int *)malloc(sizeof(int) * 2);
        new_arr[0] = arr[i][0];
        new_arr[1] = arr[i][1];
        ret_arr[ret_arr_index++] = new_arr;
        i++;
    }
    
    while(j<=high)
    {
        int * new_arr = (int *)malloc(sizeof(int) * 2);
        new_arr[0] = arr[j][0];
        new_arr[1] = arr[j][1];
        ret_arr[ret_arr_index++] = new_arr;
        j++;
    }
    
    int k = 0;
    for(i=low; i<=high; i++)
    {
        arr[i][0] = ret_arr[k][0];
        arr[i][1] = ret_arr[k][1];
        k++;
    }

    
    
    free(ret_arr);
}

void merge_sort(int arr[], int low, int high)
{
    if(low<high)
    {
        int mid = (low + high)/2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}


void merge_sort_2d(int **arr, int low, int high)
{
    if(low<high)
    {
        int mid = (low + high)/2;
        merge_sort_2d(arr, low, mid);
        merge_sort_2d(arr, mid+1, high);
        merge_2d(arr, low, mid, high);
    }
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* frequencySort(int* nums, int numsSize, int* returnSize)
{
    int * ret_arr = (int *)malloc(sizeof(int) * numsSize);
    int ret_arr_index = 0;
    
    //Merge Sort it in decreasing order
    merge_sort(nums, 0, numsSize-1);
    int i=0;
    
    
    int ** tmp_arr = (int **)malloc(sizeof(int *) * numsSize);
    int tmp_arr_index = 0;
    
    int start_index = 0;
    int end_index = 0;
    
    //Value and frequency - Take a 2d array and merge sort it based on frequency
    for(end_index=0; end_index<numsSize; )
    {
        if(start_index == end_index)
        {
            end_index++;
        }
        else if(nums[start_index] == nums[end_index])
        {
            end_index++;
        }
        else
        {
            int * new_arr = (int *)malloc(sizeof(int) * 2);
            int new_arr_index = 0;
            
            new_arr[0] = nums[start_index];
            new_arr[1] = (end_index - start_index);
            tmp_arr[tmp_arr_index++] = new_arr;
            start_index = end_index;
        }
    }
    
    int * new_arr = (int *)malloc(sizeof(int) * 2);
    int new_arr_index = 0;
    new_arr[0] = nums[start_index];
    new_arr[1] = (end_index - start_index);
    tmp_arr[tmp_arr_index++] = new_arr;

    int j=0;

    
    //Sort the 2d array based on the frequency
    merge_sort_2d(tmp_arr, 0, tmp_arr_index-1);
    

    int nums_index = 0;
    for(i=0; i<tmp_arr_index; i++)
    {
        int freq_count = tmp_arr[i][1];
        
        while(freq_count > 0)
        {
            nums[nums_index++] = tmp_arr[i][0];
            freq_count--;
        }
    }
    
    *returnSize = nums_index;
    return nums;
    
    
}