

bool isToeplitzMatrix(int** matrix, int matrixSize, int* matrixColSize)
{
    int rows = 0;
    int cols = 0;
    bool match = true;
    int val = -1;
    int col_start_index = 0;
    int row_start_index = matrixSize - 1;
    
    int count = 0;
    for(cols=0; cols < *matrixColSize; cols++)
    {
        count = 0;
        col_start_index = cols;
        for(rows=matrixSize-1; rows>=0; rows--)
        {
            if(col_start_index >= 0)
            {
                if(count == 0)
                {
                    count = 1;
                    val = matrix[rows][col_start_index--];
                }
                else
                {
                    if(val != matrix[rows][col_start_index--])
                    {
                        match = false;
                        break;
                    }
                }
            }
            else
            {
                break;
            }
        }     
        
        if(match == false)
            break;
    
    }
    
    if(match == false)
        return match;
    

        while(cols == *matrixColSize )
        {
            count = 0;
            col_start_index = cols-1;
            
            if(row_start_index >= 0)
            {

                for(rows=row_start_index; rows>=0; rows--)
                {
                    if(col_start_index >= 0)
                    {
                        if(count == 0)
                        {
                            count = 1;
                            val = matrix[rows][col_start_index--];
                        }
                        else
                        {
                            if(val != matrix[rows][col_start_index--])
                            {
                                match = false;
                                break;
                            }
                        }
                    }
                    else
                    {
                        break;
                    }
                }
                
                if(match == false)
                    break;
            }
            else
            {
                break;    
            }
            row_start_index--;
        }
     
    
    return match;
    
}