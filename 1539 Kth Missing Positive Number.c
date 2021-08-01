int findKthPositive(int* arr, int arrSize, int k)
{
    int i=0;
    int pos_num = 0;
    int last_num = 0;
    int last_pos_num = 0;
    int ret_num = 0;
    
    for(i=0; i<arrSize; i++)
    {
        int diff = arr[i] - last_num;
        if(diff == 1)
        {
            
        }
        else if(diff > 1)
        {
            pos_num += (diff - 1);
            
            if(pos_num >= k)
            {
                ret_num = (k - last_pos_num) + last_num;
                return ret_num;
            }
            last_pos_num = pos_num;          
        }
        last_num = arr[i];     
    }
    
    return last_num + (k - last_pos_num);
}