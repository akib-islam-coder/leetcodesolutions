

int minDeletionSize(char ** strs, int strsSize)
{
    int rows=0, columns=0;
    int len = strlen(&strs[0][0]);
    int no_of_del_ops = 0;
    
    for(columns=0; columns<len; columns++)
    {
        for(rows=1; rows<strsSize; rows++)
        {
               if(strs[rows][columns] < strs[rows-1][columns])
               {
                   no_of_del_ops++;
                   break;
               }
        }
    }
    return no_of_del_ops;
}