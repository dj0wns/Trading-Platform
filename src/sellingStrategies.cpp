
/* Contains a set of functions for purchasing contracts or currencies or whatever - should be written to work regardless of what is being purchased

*/

//explanation of variables
//amountToBuy - the amount of contracts to purchase
//time - the time to make the trade - used in calculating and beating the TWAP
//delta - stopping point as a percent difference of the current first purchase <1 means NULL
//stopPrice - stopping point as a number relative to the firstPurchase price

bool immediateTradeSell(int amountToBuy, float time, float delta, float stopPrice){ //tries to sell the entire order as quickly as possible without regard to shift in prices 
    return 1; //returns 1 if successful
}

bool standardTWAPSell(int amountToBuy, float time, float delta, float stopPrice){ //tries to outperform the time weighted average price over a given period of time

    return 1; //returns 1 if successful
}

bool aggressiveTWAPSell(int amountToBuy, float time, float delta, float stopPrice){ //similar to standardTWAP, however tries to sell as much as possible in the first time segment

    return 1; //return 1 if successful
}

