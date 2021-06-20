char hashtable[26][6] = { ".-",  "-...", "-.-.", "-..",  ".",   "..-.", "--.", "....",
                         "..",   ".---", "-.-",  ".-..", "--",  "-.",   "---", ".--.",
                         "--.-", ".-.",  "...",  "-",    "..-", "...-", ".--", "-..-",
                         "-.--", "--.." };

int uniqueMorseRepresentations(char ** words, int wordsSize)
{
    int count = 0;
    
    if(wordsSize == 1)
        return wordsSize;
    
    char ** morse_ptr = (char **)malloc(sizeof(char *)*wordsSize);
    int morse_ptr_index = 0;
    
    int rows = 0;
    for(rows=0; rows<wordsSize; rows++)
    {
        int columns = 0;
        int len = strlen(words[rows]);
        char * tmp_ptr = (char *)malloc(sizeof(char) * ((4*len)+1));
        int tmp_ptr_index = 0;
        
        while(words[rows][columns] != '\0')
        {
            int morse_len = strlen(hashtable[words[rows][columns]-'a']);
            memcpy(&tmp_ptr[tmp_ptr_index], hashtable[words[rows][columns]-'a'], morse_len);
            tmp_ptr_index += morse_len;
            columns++;
            
        }
        tmp_ptr[tmp_ptr_index] = '\0';
        
        morse_ptr[morse_ptr_index++] = tmp_ptr;
    }
    

    
    int i=0;
    
    //Create a hashtable and mark the morse table pointer visited 
    char ** arr_ptr = (char **)malloc(sizeof(char *) * wordsSize);
    int arr_ptr_index = 0;

    for(i=0; i<wordsSize; i++)
    {
        int j=0;
        bool match_found = false;
        for(j=0; j<arr_ptr_index; j++)
        {
            int result = strcmp(morse_ptr[i], arr_ptr[j]);
            if(result == 0)
            {
                match_found = true;
                break;
            }
        }
        
        if(!match_found)    //Add to the array 
        {
            char * tmp_ptr = (char *)malloc(sizeof(char) *(strlen(morse_ptr[i]) + 1));
            int tmp_ptr_index = 0;
            arr_ptr[arr_ptr_index++] = tmp_ptr;
            memcpy(tmp_ptr, morse_ptr[i], strlen(morse_ptr[i]));
            tmp_ptr_index = strlen(morse_ptr[i]);
            tmp_ptr[tmp_ptr_index] = '\0';
        }
    }
    
    
   
    
    count = arr_ptr_index;
    
    return count;
    
}