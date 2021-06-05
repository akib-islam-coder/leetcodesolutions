#define MAX_WORDS 9

char * sortSentence(char * s)
{
    int len = strlen(s);
    
    int i=0;
    
    char ** arr_ptr = (char **)malloc(sizeof(char *) * MAX_WORDS);
    int arr_ptr_index = 0;
    
    int start_index = 0;
    int bytes_to_copy = 0;
    
    while(s[i] != '\0')
    {
        if(i==0)
        {
            start_index = 0;
        }
        
        if((s[i] >= '0') && (s[i] <= '9'))
        {
            int index = s[i] - '0';
            
            if((s[i] - '0') >= arr_ptr_index)
                arr_ptr_index = s[i] - '0';
            
            bytes_to_copy = i - start_index;  
            
            char * new_str = (char *)malloc(sizeof(char) * (bytes_to_copy+1));
            
            memcpy(new_str, &s[start_index], bytes_to_copy);
            new_str[bytes_to_copy] = '\0';
            
            *(arr_ptr + (index - 1)) = new_str;
        }
        
        else if(s[i] == ' ')
        {
            start_index = i+1;
        }   
        
        i++;
    }
    
    memset(s, '\0', len+1);
    
    i=0;
    int s_index = 0;
    
    
    for(i=0; i<arr_ptr_index; i++)
    {
        int len_copy = strlen(*(arr_ptr+i));
        memcpy(&s[s_index], *(arr_ptr+i), len_copy);
        s_index += len_copy;
        
        if(i != arr_ptr_index-1)
            s[s_index++] = ' ';
        else 
            s[s_index++] = '\0';
    }
    return s;
}