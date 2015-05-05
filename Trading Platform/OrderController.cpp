#include "OrderController.h"

OrderController::OrderController(){

	//ctor
}

void OrderController::queueOrder(funct, int amountT, float timtT, float deltaT, float stopPriceT){
	auto foo = new Order(ptr, amountT, timtT, deltaT, stopPriceT); 
	queue.push_back(foo);
}

void OrderController::executeOrder(int index){
	//check out of bounds

	//add an error to throw if oob
	if (queue.at(index)){
		//add to in progress
		inProgress.push_back(queue[index]);

		//TODO handle thread operations
	}

}

std::vector<Order*> OrderController::getCompleted(){
	return completed;
}

std::vector<Order*> OrderController::getInProgress(){
	return inProgress;
}

std::vector<Order*> OrderController::getQueue(){
	return queue;
}