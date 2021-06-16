

int largestAltitude(int* gain, int gainSize)
{
    int highest_altitude = 0;
    
    int i=0;
    int prev_gain = 0;
    
    for(i=0; i<gainSize; i++)
    {
        int new = gain[i] + prev_gain;
        prev_gain = new;
        if(new >= highest_altitude)
        {
            highest_altitude = new;
        }
    }
    return highest_altitude;
}