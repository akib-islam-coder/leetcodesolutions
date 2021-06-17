int countGoodTriplets(int* arr, int arrSize, int a, int b, int c)
{
    int i=0;
    int j=0;
    int k=0;
    int count = 0;
    
    for(i=0; i<arrSize-2; i++)
        for(j=i+1; j<arrSize-1; j++)
            for(k=j+1; k<arrSize; k++)
            {
                int diff1 = (arr[i] - arr[j]) > 0 ? (arr[i] - arr[j]) : (arr[j] - arr[i]);
                int diff2 = (arr[j] - arr[k]) > 0 ? (arr[j] - arr[k]) : (arr[k] - arr[j]);
                int diff3 = (arr[i] - arr[k]) > 0 ? (arr[i] - arr[k]) : (arr[k] - arr[i]);
                
                if( (diff1 <= a) && (diff2 <= b) && (diff3 <= c))
                {
                    count++;
                }
            }
    return count;
}