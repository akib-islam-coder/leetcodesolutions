
/* Solving this question with O(n) time complexity using KMP Algorithm */
int strStr(char * haystack, char * needle)
{
    if(strlen(haystack) == 0 && strlen(needle) == 0)
    {
        return 0;
    }
    else if(strlen(haystack) == 0)
    {
        return -1;
    }
    else if(strlen(needle) == 0)
    {
        return 0;
    }
    
    int len_lps = strlen(needle);
    int * lps = (int *)malloc(sizeof(int) * (len_lps));
    
    
    //Building the lps
    /*
    *   1. Fill the first index with 0. Take two indices, starting with index=0 and i=1.
    *   2. If needle[i] == needle[index], lps[i] = index + 1 and increment both i and index.
    *   3. If needle[i] != needle[index], and index == 0, fill the lps[i] with 0.
    *   4. If needle[i] != needle[index], and index != 0, so we move back the index to lps[index - 1]
    *   https://www.youtube.com/watch?v=GTJr8OvyEVQ&ab_channel=TusharRoy-CodingMadeSimple
    */
    int index=0, i=0;
    lps[0] = 0;
    
    for(i=1; i<len_lps;)
    {
        if(needle[i] == needle[index])
        {
            lps[i] = index + 1;
            index++;
            i++;
        }
        else 
        {
            if(index == 0)
            {
                lps[i] = 0;
                i++; 
            }
            else
            {
                index = lps[index - 1];
            }
        }
    }

    int j=0;
    i = 0;
    for(j=0; j<strlen(haystack) && i<len_lps; )
    {
        if(haystack[j] == needle[i])
        {
           j++;
           i++;
        }
        else
        {
            if(i == 0)
            {
                j++;
            }
            else
            {
                i = lps[i-1];
            }
        }
    }
    
    if(i == len_lps)
    {
        return (j - i);
    }
    return -1;
   
}