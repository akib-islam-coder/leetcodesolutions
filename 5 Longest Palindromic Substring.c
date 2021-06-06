/* 
*   Approach - We will expand from the middle and slide the window towards left and right. 
*   1st iteration - pointer at index 0,0 and 0,1
*   2nd iteration - pointer at index 1,1 and 1,2
*/


char * expand_from_middle(char * str, int left, int right, int * ret_count)
{  
    int len = strlen(str);
    
    if(len == 0)
    {
        char * ret_str = (char *)malloc(sizeof(char)*(len+1));
        ret_str[len] = '\0';
        *ret_count = 0;
        return ret_str;
    }
    
    int count = 0;

    while((left >= 0) && (right < len))
    {
        if(str[left] == str[right])
        {
            if(left == right)
                count++;
            else
                count += 2;
            
            left--;
            right++;
        }
        else
        {
            break;
        }
    }
    
    char * ret_str = (char *)malloc(sizeof(char)*(count+1));
    memcpy(ret_str, &str[left+1], count);
    ret_str[count]= '\0';
    *ret_count = count;
    return ret_str;
}

char * longestPalindrome(char * s)
{
    const int len = strlen(s);
    
    int i=0;
    int longest_count = 0;
    int current_count = 0;
    int current_count1 = 0;
    int current_count2 = 0;
    
    int send_len = 1;
    
    char * ret_str = (char *)malloc(sizeof(char)*(len+1));
    memset(ret_str, '\0', sizeof(char)*(len+1));
    
    for(i=0; i<len; i++)
    {
   
        char * char_str1;
        char * char_str2;
        
        
        char_str1 = expand_from_middle(s, i, i,   &current_count1);
        char_str2 = expand_from_middle(s, i, i+1, &current_count2);
        
        
        if(current_count1 >= longest_count)
        {
            memset(ret_str, '\0', sizeof(char)*(len+1));
            memcpy(ret_str, char_str1, current_count1+1);
            longest_count = current_count1;
        }
        
        if(current_count2 >= longest_count)
        {
            memset(ret_str, '\0', sizeof(char)*(len+1));
            memcpy(ret_str, char_str2, current_count2+1);
            longest_count = current_count2;
        }
        
        free(char_str1);
        free(char_str2);
    }
    
    return ret_str;   
    
}