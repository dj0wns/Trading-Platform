//Trading Platform - By Derek Jones (2015)
//Description: A simulated trading platform for futures with support for TWAPs and other complex trading algorithms to simulate a real market

//Planned Features:
//Ability to buy/sell using modular buy/sell algorithms
//Attempt to mimic a real market using TWAPs and other common industry trading methods
//Save all trades to a log so they can be reviewed
//Keep track of holdings to make trades within budget



/*
Changelog:
3/14/15 - PI day~
    Version 0.0 - Wrote out function and class skeletons
*/
#include "stdafx.h"
#include "Order.h" //container for an order to be processed
#include "Holding.h"    //container to hold information for current positions
#include "buyingStrategies.h" //contains the buying strategies as function pointers, passed into Order class
#include "sellingStrategies.h" //contains the sales strategies as function pointers, passed into Order class
#include "priceFetching.h" //methods to fetch prices of a stock or security or w/e
#include "Globals.h"


int main(){

	updatePrices();
    return 0;
}

void initialize(){//initialize global vars among other things
	strategies buyStrategies[] = { //initialize the list of buy strategies to push into order
		immediateTradeBuy,
		standardTWAPBuy,
		aggressiveTWAPBuy
	};
	strategies sellStrategies[] = { //initialize the list of sell strategies to push into order
		immediateTradeSell,
		standardTWAPSell,
		aggressiveTWAPSell
	};

}
