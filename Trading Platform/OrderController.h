//class to control run the buy/sell orders.

#ifndef ORDER_CONTROLLER_H
#define ORDER_CONTROLLER_H


#include "stdafx.h"
#include "Order.h"


class OrderController
{
public:

	OrderController();

protected:
private:
	//vector of orders in progress (as pointers to lessen run time)
	std::vector<Order*> inProgress;

	//vector of orders 
	std::vector<Order*> queued;

};

#endif // ORDER_CONTROLLER_H
