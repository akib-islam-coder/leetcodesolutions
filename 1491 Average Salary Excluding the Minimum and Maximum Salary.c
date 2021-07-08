

double average(int* salary, int salarySize)
{
    int min = INT_MAX;
    int max = INT_MIN;
    int sum = 0;
    
    int i=0;
    for(i=0; i<salarySize; i++)
    {
        sum += salary[i];
        
        if(salary[i] >= max)
        {
            max = salary[i];
        }
        
        if(salary[i] <= min)
        {
            min = salary[i];
        }
    }
    
    sum = sum - max - min;
    return (double)sum / (double)(salarySize-2);
}