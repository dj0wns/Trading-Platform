//class to control the interactions between threads and eliminate race conditions

#include "threadController.h"
#include "priceFetching.h"


//TODO:
//change all joins to a doo loop until last check finishes


threadController::threadController(){
	//ctor
}

//subject to race conditions atm
std::vector<Product> threadController::fetchProducts(){
	return products;
}

std::vector<Product> threadController::updateProducts(){
	//used to pass to parse function
	std::vector<Product> temp;
	//first check if another parse is running
	if (flagList[JSON_PARSE].load(std::memory_order_relaxed)){
		//if it is, join with it and return the resulting vector
		do{
			//wait
		} while (flagList[JSON_PARSE].load(std::memory_order_relaxed));
		return products;
	}
	//if this is the case a parse is on the stack, so check for parse thread,
	//and wait for other thread to finish
	if (flagList[JSON_WRITE].load(std::memory_order_relaxed)){
		//wait for write to finish, and grab id of next parse and wait for it
		do{
			//wait
		} while (flagList[JSON_WRITE].load(std::memory_order_relaxed));
		//then if another instance is parsing the json then wait for it to finish, other wise start new one
		if (flagList[JSON_PARSE].load(std::memory_order_relaxed)){
			do{

			} while (flagList[JSON_PARSE].load(std::memory_order_relaxed));
			return products;
		}
		else{
			//create thread to parse JSON
			flagList[JSON_PARSE].store(1, std::memory_order_relaxed);
			//update products
			products = parseFileData();
			//unlock flag
			flagList[JSON_PARSE].store(0, std::memory_order_relaxed);
			return products;
		}
		
	}
	//if there is not current request to write, start new one
	else{
		flagList[JSON_WRITE].store(1, std::memory_order_relaxed);
		updatePrices();
		//consider using a mutex here
		//rerun to wait for memory write to finish

		flagList[JSON_WRITE].store(0, std::memory_order_relaxed);

		//make sure no one else started the parse yet
		if (flagList[JSON_PARSE].load(std::memory_order_relaxed)){
			do{

			} while (flagList[JSON_PARSE].load(std::memory_order_relaxed));
			return products;
		}
		flagList[JSON_PARSE].store(1, std::memory_order_relaxed);
		//updates products
		products = parseFileData();
		flagList[JSON_PARSE].store(0, std::memory_order_relaxed);

		return products;
	}
}