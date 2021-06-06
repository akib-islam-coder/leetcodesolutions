

int maximumWealth(int** accounts, int accountsSize, int* accountsColSize)
{
    int rows = 0, column = 0;
    int running_sum = 0;
    int max_sum = INT_MIN;
     
    for(rows=0; rows<accountsSize; rows++)
    {
        for(column=0; column < (*accountsColSize); column++)
        {
            running_sum += accounts[rows][column];
        }
        
        if(running_sum >= max_sum)
        {
            max_sum = running_sum;
        }
        running_sum = 0;
    }
    return max_sum;
}