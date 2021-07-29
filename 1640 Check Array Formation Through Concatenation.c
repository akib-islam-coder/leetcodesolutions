

bool canFormArray(int* arr, int arrSize, int** pieces, int piecesSize, int* piecesColSize)
{
    int i=0;
    int sum_j = 0;
    
    for(i=0; i<piecesSize; i++)
    {
        sum_j += piecesColSize[i];
    }
    
    int * tmp_arr = (int *)malloc(sizeof(int) * piecesSize * sum_j);
    int tmp_arr_index = 0;
    
    
    for(i=0; i<arrSize; i++)
    {
        int j=0;
        for(j=0; j<piecesSize; j++)
        {
            if(arr[i] == pieces[j][0])
            {
                memcpy(&tmp_arr[tmp_arr_index], &pieces[j][0], sizeof(int) * piecesColSize[j]);
                tmp_arr_index += piecesColSize[j];
            }
        }
    }
    
    bool match = true;
    for(i=0; i<arrSize; i++)
    {
        if(arr[i] != tmp_arr[i])
        {
            match = false;
            break;
        }
    }
    return match;
}