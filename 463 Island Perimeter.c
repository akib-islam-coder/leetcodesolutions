

int islandPerimeter(int** grid, int gridSize, int* gridColSize)
{
    //For each cell, we need to look up, down, left and right, if any of the adjacent cell is 0 then add 1 to perimeter, else add 0 to perimeter
    int perimeter = 0;
    int rows = 0, cols = 0;
    for(rows=0; rows<gridSize; rows++)
    {
        for(cols=0; cols<*gridColSize; cols++)
        {
            if(grid[rows][cols] == 1)
            {
                //Check upper cell
                if(rows > 0)
                {
                    if(grid[rows-1][cols] == 0)
                    {
                        perimeter += 1;
                    }
                }
                else
                {
                    perimeter += 1;
                }
                
                
                //Check lower cell
                if(rows < gridSize - 1)
                {
                    if(grid[rows+1][cols] == 0)
                    {
                        perimeter += 1;
                    }
                }
                else
                {
                    perimeter += 1;
                }
                
                //Check left cell
                if(cols > 0)
                {
                    if(grid[rows][cols-1] == 0)
                    {
                        perimeter += 1;
                    }
                }
                else
                {
                    perimeter += 1;
                }
                
                //Check right cell
                if(cols < *gridColSize - 1)
                {
                    if(grid[rows][cols+1] == 0)
                    {
                        perimeter += 1;
                    }
                }
                else
                {
                    perimeter += 1;
                }
            }
        }
    }
    return perimeter;
    
}