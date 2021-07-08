

int numRookCaptures(char** board, int boardSize, int* boardColSize)
{
    int rows=0, cols=0;

    //Search for rook's coordinates
    int rook_x = 0;
    int rook_y = 0;
    
    for(rows=0; rows<boardSize; rows++)
    {
        for(cols=0; cols<*boardColSize; cols++)
        {
            if(board[rows][cols] == 'R')
            {
                rook_x = rows;
                rook_y = cols;
                break;
            }
        }
    }
    
    int count = 0;
    for(cols=rook_y-1; cols>=0; cols--)
    {
        if(board[rook_x][cols] == 'p')
        {
            count++;
            break;
        }
        else if(board[rook_x][cols] == 'B')
        {
            break;
        }
    }
   
    for(cols=rook_y+1; cols<*boardColSize; cols++)
    {
        if(board[rook_x][cols] == 'p')
        {
            count++;
            break;
        }
        else if(board[rook_x][cols] == 'B')
        {
            break;
        }
    }

    for(rows=rook_x-1; rows>=0; rows--)
    {
        if(board[rows][rook_y] == 'p')
        {
            count++;
            break;
        }
        else if(board[rows][rook_y] == 'B')
        {
            break;
        }
    }
    
    for(rows=rook_x+1; rows<boardSize; rows++)
    {
        if(board[rows][rook_y] == 'p')
        {
            count++;
            break;
        }
        else if(board[rows][rook_y] == 'B')
        {
            break;
        }
    }
    
    return count;
}