#ifndef ORDER_H
#define ORDER_H
//Object to contain and execute an order

#include "Globals.h"

class Order
{
    public:
	Order(strategy, int, float, float, float); //instantiate variables
        bool executeTrade();

    protected:
    private:
	strategy function; //function used in the trade
        float time; //time for trade to execute
        float delta; // range the price is allowed to move before a stop
        int amount; //amount of buy/sell orders to execute
	float stopPrice;

};

#endif // ORDER_H
