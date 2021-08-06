

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** findRestaurant(char ** list1, int list1Size, char ** list2, int list2Size, int* returnSize)
{
    int i=0, j=0;
    int index = 0;
    int min_index = INT_MAX;
    
    for(i=0; i<list1Size; i++)
    {
        for(j=0; j<list2Size; j++)
        {
            if(strcmp(list1[i], list2[j]) == 0)
            {
                index = i + j;
                if(index <= min_index)
                {
                    min_index = index;
                }
            }
        }
    }

    char ** ret_arr = (char **)malloc(sizeof(char *) * (list1Size >= list2Size ? list1Size : list2Size));
    int ret_arr_index = 0;
    
    for(i=0; i<list1Size; i++)
    {
        for(j=0; j<list2Size; j++)
        {
            if(strcmp(&list1[i][0], &list2[j][0]) == 0 && (i+j == min_index))
            {
                char * new_arr = (char *)malloc(sizeof(char) * (strlen(list1[i]) + 1));
                int new_arr_index = 0;
                ret_arr[ret_arr_index++] = new_arr;
                memcpy(&new_arr[0], list1[i], sizeof(char) * (strlen(list1[i]) + 1));
            }
        }
    }
    *returnSize = ret_arr_index;
    return ret_arr;
}