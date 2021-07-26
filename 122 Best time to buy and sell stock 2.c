

int maxProfit(int* prices, int pricesSize)
{
    int i=0;
    int max_profit = 0;
    int buy_share  = prices[0];
    int sell_share = 0;
    int last_profit = 0;
    
    bool buy_done = true;
    bool sell_done = false;
    
    for(i=1; i<pricesSize; i++)
    {
        if(buy_done && prices[i] <= buy_share)
        {
            buy_share = prices[i];
            buy_done = true;
            sell_done = false;
        }
        else if(buy_done && prices[i] > buy_share)
        {
                sell_done = true;
                buy_done  = false;
                
                sell_share = prices[i];
                
                max_profit += (sell_share - buy_share);
                last_profit = sell_share - buy_share;
        
        }
        else if(sell_done && prices[i] > sell_share)
        {
            sell_done = true;
            buy_done = false;
            
            sell_share = prices[i];
            
            max_profit -= last_profit;
            max_profit += (sell_share - buy_share);
            last_profit = (sell_share - buy_share);
        }
        else if(sell_done && prices[i] <= sell_share)
        {
            sell_done = false;
            buy_done = true;
            buy_share = prices[i];
        }
    }
    return max_profit;

}