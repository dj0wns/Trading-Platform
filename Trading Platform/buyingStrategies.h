#ifndef BUYINGSTRATEGIES_H
#define BUYINGTRATEGIES_H
//contains the functions for all buying strategies


bool immediateTradeBuy(int amountToBuy, float time, float delta, float stopPrice);//tries to purchase the entire order as quickly as possible without regard to shift in prices

bool standardTWAPBuy(int amountToBuy, float time, float delta, float stopPrice);//tries to outperform the time weighted average price over a given period of time

bool aggressiveTWAPBuy(int amountToBuy, float time, float delta, float stopPrice);//similar to standardTWAP, however tries to buy as much as possible in the first time segment

#endif