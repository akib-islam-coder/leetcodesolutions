

int oddCells(int m, int n, int** indices, int indicesSize, int* indicesColSize)
{
    int * matrix = (int *)malloc(sizeof(int)* m * n);
    memset(matrix, 0x00, sizeof(int)* m * n);
    
    int row_size = m;
    int column_size = n;
    
    int matrix_ptr = 0;
    
    int i=0, j=0;
    for(i=0; i<indicesSize; i++)
    {
        int row = indices[i][0];
        int column = indices[i][1];
        
        for(j=0; j<column_size; j++)
        {
            *(matrix + (row * column_size) + j) += 1;
        }
        
        for(j=0; j<row_size; j++)
        {
            *(matrix + (j * column_size) + column) += 1;

        }
    }
    
    int count = 0;
    for(i=0; i<row_size; i++)
    {
        for(j=0; j<column_size; j++)
        {
            if((*(matrix + (i*(column_size)) + j)) %2 != 0)
            {
                count++;
            }
                
        }
    }
    free(matrix);
    return count;
    
    
}

int oddCells(int m, int n, int** indices, int indicesSize, int* indicesColSize)
{
    int * matrix = (int *)malloc(sizeof(int)* m * n);
    memset(matrix, 0x00, sizeof(int)* m * n);
    
    int row_size = m;
    int column_size = n;
    
    int matrix_ptr = 0;
    
    int i=0, j=0;
    for(i=0; i<indicesSize; i++)
    {
        int row = indices[i][0];
        int column = indices[i][1];
        
        for(j=0; j<column_size; j++)
        {
            *(matrix + (row * column_size) + j) += 1;
        }
        
        for(j=0; j<row_size; j++)
        {
            *(matrix + (j * column_size) + column) += 1;

        }
    }
    
    int count = 0;
    for(i=0; i<row_size; i++)
    {
        for(j=0; j<column_size; j++)
        {
            if((*(matrix + (i*(column_size)) + j)) %2 != 0)
            {
                count++;
            }
                
        }
    }
    free(matrix);
    return count;
    
    
}