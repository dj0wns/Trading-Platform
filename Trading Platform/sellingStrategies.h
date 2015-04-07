#ifndef SELLINGSTRATEGIES_H
#define SELLINGSTRATEGIES_H



bool immediateTradeSell(int amountToBuy, float time, float delta, float stopPrice);//tries to sell the entire order as quickly as possible without regard to shift in prices 

bool standardTWAPSell(int amountToBuy, float time, float delta, float stopPrice);//tries to outperform the time weighted average price over a given period of time

bool aggressiveTWAPSell(int amountToBuy, float time, float delta, float stopPrice);//similar to standardTWAP, however tries to sell as much as possible in the first time segment

#endif