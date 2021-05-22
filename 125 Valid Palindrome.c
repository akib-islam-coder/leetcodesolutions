

bool isPalindrome(char * s)
{
    int first_index = 0;
    int i=0;
    int last_index = 0;
    int mid = 0;
    bool even_len = false;
    
    while(s[i]!='\0')
    {
        last_index++;
        i++;
    }

    
    last_index -= 1;
    
    bool pal_found = true;
    char first_element = '\0';
    char last_element = '\0';
    
        while(first_index <= last_index)
        {
            if(((s[first_index] >= '0') && (s[first_index] <= '9')) || ((s[first_index] >= 'a') && (s[first_index] <= 'z')))
            {
                first_element = s[first_index];
            }
            else if((s[first_index] >= 'A') && (s[first_index] <= 'Z'))
            {
                first_element = s[first_index] + ('a' - 'A');
            }
            else
            {
                first_index++;
                continue;
            }
            
            if(((s[last_index] >= '0') && (s[last_index] <= '9')) || ((s[last_index] >= 'a') && (s[last_index] <= 'z')))
            {
                last_element = s[last_index];
            }
            else if((s[last_index] >= 'A') && (s[last_index] <= 'Z'))
            {
                last_element = s[last_index] + ('a' - 'A');
            }
            else
            {
                last_index--;
                continue;
            }
            
            if(first_element == last_element)
            {
                first_index++;
                last_index--;
            }
            else
            {
                pal_found = false;
                break;
            }
        }

    if(pal_found)
    {
        return true;
    }
    else
    {
        return false;
    }
 
}