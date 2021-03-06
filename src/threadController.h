//class to control the interactions between threads and eliminate race conditions

#ifndef THREAD_CONTROLLER_H
#define THREAD_CONTROLLER_H


#include "stdafx.h"
#include "Product.h"


class threadController
{
public:

	threadController();
	void newOrder(std::thread); //pass a new order into the vectors
	std::vector<Product> fetchProducts();
	std::vector<Product> updateProducts();
protected:
private:

	//code in function prevents race conditions here
	std::vector<Product> products;
	enum flagNames{
		JSON_WRITE,
		JSON_PARSE
	};

	//I dont think this needs to be an atomic because it is a bool
	std::atomic<bool> flagList[2];
};

#endif // HOLDING_H
