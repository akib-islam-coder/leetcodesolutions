void insert(int heap[], int val, int n)
{
    heap[n] = val;
    int index = n;
    int j = n/2;
    
    while(j>=1 && val > heap[j])
    {
        int tmp = heap[j];
        heap[j] = val;
        heap[index] = tmp;
        index = j;
        j = j/2;
    }
}

int delete(int heap[], int * heap_index)
{
    int tmp_element = heap[1];
    heap[1] = heap[*heap_index];
    *heap_index -= 1;
    int index = 1;
    int j = index * 2;
    
    while(j<=*heap_index)
    {
        if(heap[j+1] > heap[j])
        {
            j = j+1;
        }
        
        if(heap[j] > heap[index])
        {
            int tmp = heap[j];
            heap[j] = heap[index];
            heap[index] = tmp;
            index = j;
            j = index * 2;
        }
        else
        {
            break;
        }
    }
    heap[(*heap_index)+1] = tmp_element;
    return tmp_element;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArray(int* nums, int numsSize, int* returnSize)
{
    int * heap = (int *)malloc(sizeof(int) * (numsSize + 1));
    
    heap[0] = 0;
    heap[1] = nums[0];
    
    int i=0;
    for(i=1; i<numsSize; i++)
    {
        insert(heap, nums[i], i+1);
    }
    
    int heap_index = numsSize;
    
    for(i=0; i<numsSize; i++)
    {
        int element = delete(heap, &heap_index);
    }
    
   
    
    *returnSize = numsSize;
    return &heap[1];
    
    
}