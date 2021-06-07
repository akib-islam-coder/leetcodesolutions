

bool arrayStringsAreEqual(char ** word1, int word1Size, char ** word2, int word2Size)
{
    
    int i=0, j=0;
    
    bool flag = true;
    int word1_index = 0;
    int word2_index = 0;
    
    char * ptr1 = *(word1);
    char * ptr2 = *(word2);
    
    
    while(flag)
    {
    
        while((ptr1[word1_index]!='\0') && (ptr2[word2_index]!='\0'))
        {
            if(ptr1[word1_index] != ptr2[word2_index])
            {
                flag = false;
                break;
            }
            else
            {
                word1_index++;
                word2_index++;
            }
        }
        
        
        if(ptr1[word1_index] == '\0')
        {
            word1_index = 0;
            i++;
            if(i==word1Size)
            {
                flag = false;
            }
            else
            {
                ptr1 = *(word1 + i);
            }
        }
        
        if(ptr2[word2_index] == '\0')
        {
            word2_index = 0;
            j++;
            if(j==word2Size)
            {
                flag = false;
            }
            else
            {
                ptr2 = *(word2 + j);
            }
        }
             
    }
    
    if((i==word1Size)&&(j==word2Size))
        flag = true;
    
    return flag;
    
    
}