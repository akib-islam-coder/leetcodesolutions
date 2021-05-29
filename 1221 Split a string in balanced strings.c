

int balancedStringSplit(char * s)
{
    int l_count = 0;
    int r_count = 0;
    int no_of_balanced_strings = 0;
    
    int i=0;
    while(s[i] != '\0')
    {
        if(s[i] == 'L')
        {
            l_count++;
        }
        else if(s[i] == 'R')
        {
            r_count++;
        }
        
        if(l_count == r_count)
        {
            no_of_balanced_strings++;
        }
        i++;
    }
    return no_of_balanced_strings;
}