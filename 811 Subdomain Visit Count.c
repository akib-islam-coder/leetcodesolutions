char domain_hashtable[300][100] = {'\0'};
int count_hashtable[300] = {0};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** subdomainVisits(char ** cpdomains, int cpdomainsSize, int* returnSize)
{
    memset(&domain_hashtable[0][0], '\0', sizeof(char)*300*100);
    memset(count_hashtable, '\0', sizeof(int)*300);
    
    int i=0, j=0;
    char num_arr[100];
    
    char toplevel[100];
    int top_level_index = 0;
    
    char sublevel[100];
    int sub_level_index = 0;
    
    char lowlevel[100];
    int low_level_index = 0;
        
    
    for(i=0; i<cpdomainsSize; i++)
    {
        memset(toplevel, '\0', sizeof(toplevel));
        memset(sublevel, '\0', sizeof(sublevel));
        memset(lowlevel, '\0', sizeof(lowlevel));
        top_level_index  = 0;
        sub_level_index  = 0;
        low_level_index  = 0;
                
        j=0;
        while(cpdomains[i][j] != ' ')
        {
            num_arr[j] = cpdomains[i][j];
            j++;
        }
        num_arr[j++] = '\0';
        int num = atoi(num_arr);

        
        int k = j;
        int num_of_levels = 1;
        while(cpdomains[i][k] != '\0')
        {
            if(cpdomains[i][k] == '.')
            {
                num_of_levels++;
            }
            k++;
        }
        
        int z = j;

        if(num_of_levels == 2)
        {
            sub_level_index = 0;
            low_level_index = 0;
            
            while(cpdomains[i][z] != '\0')
            {
                sublevel[sub_level_index++] = cpdomains[i][z];
                if(cpdomains[i][z] == '.')
                {
                    j = z;
                }
                z++;
            }
            sublevel[sub_level_index] = '\0';

            //Add to hashtable
            k=0;
            for(k=0; k<300; k++)
            {
                if(domain_hashtable[k][0] == '\0')
                {
                    //Add an entry in hashtable
                    strcpy(domain_hashtable[k], sublevel);
                    count_hashtable[k] = num;
                    break;
                }
                
                
                if(strcmp(domain_hashtable[k], sublevel) == 0)
                {
                    count_hashtable[k] += num;
                    break;
                }
            }
            
            j++;
            z = j;

            while(cpdomains[i][z] != '\0')
            {
                toplevel[top_level_index++] = cpdomains[i][z];
                z++;
            }
            toplevel[top_level_index] = '\0';

            
            //Add to hashtable
            k=0;
            for(k=0; k<300; k++)
            {
                if(domain_hashtable[k][0] == '\0')
                {
                    //Add an entry in hashtable
                    strcpy(domain_hashtable[k], toplevel);
                    count_hashtable[k] = num;
                    break;
                }
                
                
                if(strcmp(domain_hashtable[k], toplevel) == 0)
                {
                    count_hashtable[k] += num;
                    break;
                }
            }
        }
        else
        {
            sub_level_index = 0;
            low_level_index = 0;
            top_level_index = 0;
            bool first_dot = false;
            while(cpdomains[i][z] != '\0')
            {
                lowlevel[low_level_index++] = cpdomains[i][z];
                
                if(cpdomains[i][z] == '.' && first_dot == false)
                {
                    j = z;
                    first_dot = true;
                }
                z++;
            }
            lowlevel[low_level_index] = '\0';

            
            //Add to hashtable
            k=0;
            for(k=0; k<300; k++)
            {
                if(domain_hashtable[k][0] == '\0')
                {
                    //Add an entry in hashtable
                    strcpy(domain_hashtable[k], lowlevel);
                    count_hashtable[k] = num;
                    break;
                }
                
                
                if(strcmp(domain_hashtable[k], lowlevel) == 0)
                {
                    count_hashtable[k] += num;
                    break;
                }
            }
                
            
            j++;     
            z = j;
            
            while(cpdomains[i][z] != '\0')
            {

                sublevel[sub_level_index++] = cpdomains[i][z];
                
                if(cpdomains[i][z] == '.')
                {
                    j = z;
                }
                z++;
            }
            sublevel[sub_level_index] = '\0';
            
            //Add to hashtable
            k=0;
            for(k=0; k<300; k++)
            {
                if(domain_hashtable[k][0] == '\0')
                {
                    //Add an entry in hashtable
                    strcpy(domain_hashtable[k], sublevel);
                    count_hashtable[k] = num;
                    break;
                }
                
                
                if(strcmp(domain_hashtable[k], sublevel) == 0)
                {
                    count_hashtable[k] += num;
                    break;
                }
            }
            
            j++;
            z = j;
            
            while(cpdomains[i][z] != '\0')
            {
                toplevel[top_level_index++] = cpdomains[i][z++];
            }
            toplevel[top_level_index] = '\0';
            
            //Add to hashtable
            k=0;
            for(k=0; k<300; k++)
            {
                if(domain_hashtable[k][0] == '\0')
                {
                    //Add an entry in hashtable
                    strcpy(domain_hashtable[k], toplevel);
                    count_hashtable[k] = num;
                    break;
                }
                
                
                if(strcmp(domain_hashtable[k], toplevel) == 0)
                {
                    count_hashtable[k] += num;
                    break;
                }
            }


        }    
    }
    
    int count = 0, k=0;
    for(k=0; k<300; k++)
    {
        if(domain_hashtable[k][0] != '\0')
        {
            count++;
        }
        else
        {
            break;
        }
    }
    
    
    char ** ret_arr = (char **)malloc(sizeof(char *) * count);
    int ret_arr_index = 0;
    
    for(k=0; k<count; k++)
    {
        int len1 = 0, len2 = 0;        
        char int_arr[100] = {'\0'};
  
        sprintf(int_arr, "%d", count_hashtable[k]);
        
        len1 = strlen(int_arr);
        len2 = strlen(domain_hashtable[k]);
        
        char * new_str = (char *)malloc(sizeof(char) *  (len1 + len2 + 2));
        memcpy(&new_str[0], int_arr, sizeof(char) * len1);
        new_str[len1] = ' ';
        memcpy(&new_str[len1+1], domain_hashtable[k], sizeof(char) * len2);
        new_str[len1 + 1 + len2] = '\0';
        ret_arr[k] = new_str;
    }
    
    
    *returnSize = count;
    return ret_arr;
    
}