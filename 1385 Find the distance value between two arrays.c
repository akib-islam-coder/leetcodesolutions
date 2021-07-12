

int findTheDistanceValue(int* arr1, int arr1Size, int* arr2, int arr2Size, int d)
{
    int i=0, j=0;
    int count = 0;
    for(i=0; i<arr1Size; i++)
    {
        for(j=0; j<arr2Size; j++)
        {
            int diff = arr1[i] - arr2[j];
            if(diff < 0)
            {
                diff *= -1;
            }
            
            if(diff <= d)
                break;
            
            if(j==arr2Size-1)
                count++;
        }
    }
    return count;
}