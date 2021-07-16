

bool threeConsecutiveOdds(int* arr, int arrSize)
{
    int i=0;
    int start_index = 0;
    int end_index = 0;
    int k = 3;
    
    for(end_index=0; end_index<arrSize; )
    {
        if(end_index-start_index < 3)
        {
            if(arr[end_index]%2 == 1)
            {
                end_index++;
            }
            else
            {
                end_index++;
                start_index = end_index;
            }
        }
        else if(end_index - start_index == 3)
        {
            return true;
        }
    }
    
    if(end_index - start_index == 3)
    {
        return true;
    }
    return false;
}