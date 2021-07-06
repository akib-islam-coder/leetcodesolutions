void Merge(int ** aux_arr, int low, int mid, int high)
{
    int * tmp_arr = (int *)malloc(sizeof(int) * ((high-low+1)*2));
    int tmp_arr_index = 0;
    
    int i=low;
    int j=mid+1;
    
    for(i=low, j=mid+1; i<=mid && j<=high;)
    {
        if(aux_arr[i][1] <= aux_arr[j][1])
        {
            *(tmp_arr + tmp_arr_index) = aux_arr[i][0];
            tmp_arr_index++;
            *(tmp_arr + tmp_arr_index) = aux_arr[i][1];
            tmp_arr_index++;
            i++;
        }
        else
        {
            *(tmp_arr + tmp_arr_index) = aux_arr[j][0];
            tmp_arr_index++;
            *(tmp_arr + tmp_arr_index) = aux_arr[j][1];
            tmp_arr_index++;
            j++;
        }
    }
    
    while(i<=mid)
    {
        *(tmp_arr + tmp_arr_index) = aux_arr[i][0];
        tmp_arr_index++;
        *(tmp_arr + tmp_arr_index) = aux_arr[i][1];
        tmp_arr_index++;
        i++;
    }
    
    while(j<=high)
    {
        *(tmp_arr + tmp_arr_index) = aux_arr[j][0];
        tmp_arr_index++;
        *(tmp_arr + tmp_arr_index) = aux_arr[j][1];
        tmp_arr_index++;
        j++;
    }
    
    j=0;
    for(i=0; i<tmp_arr_index; )
    {
        aux_arr[low+j][0] = tmp_arr[i];
        i++;
        aux_arr[low+j][1] = tmp_arr[i];
        i++;
        j++;       
    }
    
    free(tmp_arr);
}


void mergeSort(int ** aux_arr, int low, int high)
{
    if(low < high)
    {
        int mid = (low + high)/2;

        mergeSort(aux_arr, low, mid);
        mergeSort(aux_arr, mid+1, high);
        Merge(aux_arr, low, mid, high);
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* kWeakestRows(int** mat, int matSize, int* matColSize, int k, int* returnSize)
{
    int * ret_arr = (int *)malloc(sizeof(int) * matSize);
    int ret_arr_index = 0;
    
    int i=0,j=0;
    for(i=0; i<matSize; i++)
    {
        int count = 0;
        for(j=0; j<*matColSize; j++)
        {
            if(mat[i][j] == 1)
            {
                count++;
            }
        }
        ret_arr[ret_arr_index++] = count;
    }

    
    //Convert into a 2d array with column 0 as index and column 1 as values
    int ** aux_arr = (int **)malloc(sizeof(int *) * matSize);
    int aux_arr_index = 0;
    
    for(i=0; i<matSize; i++)
    {
        int * tmp_arr = (int *)malloc(sizeof(int) * 2);
        tmp_arr[0] = i;             //Row No
        tmp_arr[1] = ret_arr[i];    //Count
        aux_arr[aux_arr_index++] = tmp_arr;
    }
    
    
    //Sort the array on basis of column[1]
    mergeSort(aux_arr, 0, aux_arr_index-1);

     ret_arr_index = 0;
     for(i=0; i<matSize; i++)
     {
         ret_arr[ret_arr_index++] = aux_arr[i][0];
     }
        
        
    *returnSize = k;
     return ret_arr;

    

    
}