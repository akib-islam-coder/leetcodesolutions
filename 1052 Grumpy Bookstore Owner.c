

int maxSatisfied(int* customers, int customersSize, int* grumpy, int grumpySize, int minutes)
{
    int max_satisfied_customer = 0;
    int prev_sum = 0;
    int next_sum = 0;
    
    int current_sum = 0;
    int i=0;
    
    if(grumpySize <= minutes)
    {
        for(i=0; i<grumpySize; i++)
        {
            current_sum += customers[i];
        }
        return current_sum;
    }
    
    int end_index = 0;
    int start_index = 0;
    
   
    
    for(end_index=minutes-1; end_index<grumpySize; end_index++)
    {
            current_sum = 0;
        
            //Current sum calculation when the minutes is in effect
            for(i=start_index; i<=end_index; i++)
            {
                current_sum += customers[i];
            }
        
            if(start_index >= 1)
            {
                if(grumpy[start_index-1] == 0)
                {
                    prev_sum += customers[start_index-1];
                }
            }
            current_sum += prev_sum;
        
            if(end_index == minutes-1)
            {
                for(i=end_index+1; i<grumpySize; i++)
                {
                    if(grumpy[i] == 0)
                    {
                        current_sum += customers[i];
                        next_sum += customers[i];
                    }
                }
                
            }
            else
            {
                if(grumpy[end_index] == 0)
                {
                    next_sum -= customers[end_index];
                }
                current_sum += next_sum;
            }
        
                
            if(current_sum >= max_satisfied_customer)
            {
                max_satisfied_customer = current_sum;
            }
        
            start_index++;
    }
    return max_satisfied_customer;
}