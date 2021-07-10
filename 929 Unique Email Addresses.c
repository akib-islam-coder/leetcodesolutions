char hashtable[101][101] = {'\0'};

int numUniqueEmails(char ** emails, int emailsSize)
{
    int rows = 0;
    char ** tmp_email = (char **)malloc(sizeof(char *) * emailsSize);
    int tmp_email_index = 0;
    
    int i=0;
    for(i=0; i<101; i++)
    {
        hashtable[i][0] = '\0';
    }
    
    for(rows=0; rows<emailsSize; rows++)
    {
        int i=0;
        char * new_arr = (char *)malloc(sizeof(char) * 101);
        int new_arr_index = 0;
        tmp_email[tmp_email_index++] = new_arr;
        bool start_ignore = false;
        bool not_ignore = false;
        
        while(emails[rows][i] != '\0')
        {
            if(emails[rows][i] == '.')
            {
                if(not_ignore)
                   new_arr[new_arr_index++] = emails[rows][i]; 
                i++;
            }
            else if(emails[rows][i] == '+')
            {
                if(not_ignore)
                   new_arr[new_arr_index++] = emails[rows][i];
                else
                    start_ignore = true;
                i++;
            }
            else
            {
                if(emails[rows][i] == '@')
                {
                    start_ignore = false;
                    not_ignore = true;
                }
                
                if(!start_ignore)
                    new_arr[new_arr_index++] = emails[rows][i];
                i++;
            }
        }
        new_arr[new_arr_index++] = '\0';
    }
    
    int insert_index = 0;
    for(rows=0; rows<tmp_email_index; rows++)
    {
       bool match = false;     
       for(i=0; i<101; i++)
       {
           if(hashtable[i][0] == '\0')
           {
               insert_index = i;
               break;
           }
           
           else if(strcmp(tmp_email[rows] ,&hashtable[i][0]) == 0) //Match found
           {
               match = true;
               break;
           }       
       }
        
        if(!match)
        {
            int len = strlen(tmp_email[rows]);
            memcpy(&hashtable[insert_index][0], tmp_email[rows], sizeof(char) * (len + 1));
            puts(&hashtable[insert_index][0]);
        }
        
        
    }
    
    return insert_index + 1;
    
}