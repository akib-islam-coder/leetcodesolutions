int sumOddLengthSubarrays(int* arr, int arrSize)
{
    int running_sum = 0;
    
    int i=0;
    for(i=0; i<arrSize; i++)
    {
        running_sum += arr[i];
    }

    
    //Siliding window length k
    int k=0;
    for(k=3; k<=arrSize; k+=2)
    {
        int start_index = 0;
        int end_index = k-1;
        
        //Calculate the initial sum j=0
        int sum = 0;
        int j=0;
        for(j=start_index; j<=end_index; j++)
        {
            sum += arr[j];
        }
        running_sum += sum;

        
        while(end_index < arrSize)
        {
            sum -= arr[start_index];
            start_index++;
            end_index++;
            
            if(end_index < arrSize)
            {
                sum += arr[end_index];
                running_sum += sum;

            }
            
        }
        
    }
    return running_sum;
    
}