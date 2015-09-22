//class to control run the buy/sell orders.

#ifndef ORDER_CONTROLLER_H
#define ORDER_CONTROLLER_H


#include "stdafx.h"
#include "Order.h"
#include "Globals.h"
#include "threadController.h"


class OrderController
{
public:

	OrderController();
	//adds and order to the queue
	void queueOrder(funct, int, float, float, float);
	//executes an order in the queue at the index
	void executeOrder(int); //TODO

	std::vector<Order*> getCompleted();
	std::vector<Order*> getInProgress();
	std::vector<Order*> getQueue();
	void printCompleted();
	void printInProgress();
	void printQueue();
	void printAll();

protected:
private:

	//holding for completed orders, to be cleaned as they are written to the log file
	std::vector<Order*> completed;

	//vector of orders in progress (as pointers to lessen run time)
	std::vector<Order*> inProgress;

	//vector of orders 
	std::vector<Order*> queue;

};

#endif // ORDER_CONTROLLER_H
