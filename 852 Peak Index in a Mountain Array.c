int peakIndexInMountainArray(int* arr, int arrSize)
{
    int low = 0;
    int high = arrSize-1;
    
    while(low <= high)
    {
        int mid = (low+high)/2;
        if(mid-1 >= 0 && mid+1 < arrSize)
        {
            if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1])
                return mid;
            else if(arr[mid] > arr[mid-1] && arr[mid] < arr[mid+1]) //Ascending
                low = mid+1;
            else if(arr[mid] < arr[mid-1] && arr[mid] > arr[mid+1]) //Descending
                high = mid-1;
        }
        else
        {
            if(low == high)
                return low;
            else if(mid-1 < 0)
            {
                if(arr[mid] > arr[mid+1])
                    return mid;
                else
                    low = mid+1;
            }
            else if(mid+1 >= arrSize)
            {
                if(arr[mid] > arr[mid-1])
                    return mid;
                else
                    high = mid-1;
                    
            }
        }
    }
    return -1;
}