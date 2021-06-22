

int countNegatives(int** grid, int gridSize, int* gridColSize)
{
    int count = 0;
    
    int rows = 0;
    int columns = 0;
    
    for(rows=0; rows<gridSize; rows++)
    {
        for(columns=0; columns<(*gridColSize); columns++)
        {
            if(grid[rows][columns] < 0)
            {
                count += (*gridColSize - columns);
                break;
            }
        }
    }
    return count;
}