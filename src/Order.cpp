#include "Order.h"
#include "Globals.h"


Order::Order(funct, int amountT, float timeT, float deltaT, float stopPriceT)
{
	function = ptr;
	time = timeT;
	delta = deltaT;
	amount = amountT;
	stopPrice = stopPriceT;

}


bool Order::executeTrade(){
	function(amount, time, delta, stopPrice);
	return 1;
}

void Order::print(){
	std::cout << "Time: " << time << "\tDelta: " << delta << "\tAmount: " << amount
	<< "\tStop Price: " << stopPrice << std::endl;

}
