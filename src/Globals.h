#ifndef GLOBALS_H
#define GLOBALS_H


//definition for easy passing of functions as arguments
#define funct bool(*ptr)(int, float, float, float)
//containts global variables 
typedef bool(*strategy) (int, float, float, float); //array of trading strategies

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


//potential to add these constants to an xml file for easy modification
extern char CME_GROUP_WEBPAGE[]; //webpage for fetching the json

extern char FILE_PATH[]; //path where files are saved


#endif