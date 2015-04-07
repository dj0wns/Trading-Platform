#ifndef GLOBALS_H
#define GLOBALS_H
typedef bool(*strategies) (int, float, float, float); //array of trading strategies

enum buyFunctionNames { //names of purchase functions for easy reference when passing the function pointer - B refers to buy
	immediateTradeB,
	standardTWAPB,
	aggressiveTWAPB
};

enum sellFunctionNames { //names of sales functions for easy reference when passing the function pointer - S refers to sell
	ImmediateTradeSellS,
	standardTWAPSellS,
	aggressiveTWAPSellS
};

extern const int CME_GROUP_WEBPAGES_SIZE;

extern const char *CME_GROUP_WEBPAGES[3];


#endif