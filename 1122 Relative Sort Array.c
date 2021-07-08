#define MAX_INDEX 1001
int hashtable[1001] = {0};

void merge(int arr[], int low, int mid, int high)
{
    int * ret_arr = (int *)malloc(sizeof(int) * (high - low + 1));
    int ret_arr_index = 0;
    
    int i=0, j=0;
    for(i=low, j=mid+1; i<=mid && j<=high; )
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
    
    memcpy(&arr[low], ret_arr, sizeof(int) * (high - low + 1));
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

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize)
{
    memset(hashtable, 0, sizeof(hashtable));
    merge_sort(arr1, 0, arr1Size-1);
    
    int * ret_arr = (int *)malloc(sizeof(int) * arr1Size);
    int ret_arr_index = 0;
    
    int i=0;
    for(i=0; i<arr2Size; i++)
    {
        int element = arr2[i];
        int j = arr1[0];
        
        bool start = false;
        for(j=0; j<arr1Size; j++)
        {
            if(arr1[j] != element)
            {
                if(start)
                    break;
            }
            else
            {
                start = true;
                ret_arr[ret_arr_index++] = arr1[j];
                hashtable[j] = 1;
            }
        }
    }
    

    for(i=0; i<arr1Size; i++)
    {
        if(hashtable[i] == 0)
        {
            ret_arr[ret_arr_index++] = arr1[i];
        }
    }
    
    *returnSize = ret_arr_index;
    memcpy(arr1, ret_arr, sizeof(int) * ret_arr_index);
    free(ret_arr);
    return arr1;
    
    
}