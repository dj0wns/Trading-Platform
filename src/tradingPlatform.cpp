//Trading Platform - By Derek Jones (2015)
//Description: A simulated trading platform for futures with support for TWAPs and other complex trading algorithms to simulate a real market

//Planned Features:
//Ability to buy/sell using modular buy/sell algorithms
//Attempt to mimic a real market using TWAPs and other common industry trading methods
//Save all trades to a log so they can be reviewed
//Keep track of holdings to make trades within budget



/*
Changelog:
12/08/15
	Version 0.5a - Fixed the random hang, turns out it wasn't a threading issue but rather I did not initialize the flags in thread controller
9/22/15
	Version 0.5 - Added print statements for Orders and began work on UI
9/21/15
	Version 0.4b - Removed Visual Studio dependencies and configured to work in a Linux environment
4/13/15
	Version 0.4 - added OrderController class and completed order class 
4/09/15
	Version 0.3 - added thread controller to manage multithreading 
		-plan to start work on order management soon and after that ui
4/08/15
	Version 0.2 - moved file operations to a background thread
4/07/15
	Version 0.1b - Now correctly parses the read json into a vector of products
4/06/15
	Version 0.1a - libcURL finally works properly
4/01/15
	Version 0.1 - Started work with libcurl
3/14/15 - PI day~
    Version 0.0 - Wrote out function and class skeletons
*/



/*TODO
-Finish Order Controller
-Write trading algorithms
-Create UI
-Finalize and test trades
-Add exceptions to the file creation and working with the json file (atm assumes everything just works)
-Add xml file for configuration
*/

/*Known Issues
 -Seg Fault if CMEWorkgroup directory does not exist, but works the second time
 */

#include "stdafx.h"
#include "Order.h" //container for an order to be processed
#include "Holding.h"    //container to hold information for current positions
#include "buyingStrategies.h" //contains the buying strategies as function pointers, passed into Order class
#include "sellingStrategies.h" //contains the sales strategies as function pointers, passed into Order class
#include "priceFetching.h" //methods to fetch prices of a stock or security or w/e
#include "Globals.h"
#include "threadController.h" //methods for controlling thread interaction
#include "OrderController.h" //methods for execution trades

void initialize(std::vector<Product>&, threadController &);
void driver(OrderController&, std::vector<Product>&, threadController &);
void commandTable(std::string&, OrderController&, std::vector<Product>&, threadController&);

int main(){
	std::vector<Product> products;
	strategy buyStrategies[] = { //initialize the list of buy strategies to push into order
		immediateTradeBuy,
		standardTWAPBuy,
		aggressiveTWAPBuy
	};
	strategy sellStrategies[] = { //initialize the list of sell strategies to push into order
		immediateTradeSell,
		standardTWAPSell,
		aggressiveTWAPSell
	};
	threadController tControl;
	OrderController oControl;	
	//products = tControl.updateProducts();
	//for(auto v : products){
	//	v.print();
//	}
	std::thread initialRun(initialize, std::ref(products), std::ref(tControl));
	initialRun.join();
	driver(oControl, products, tControl);
	//for testing, will be removed when ui implemented

	return 0;
}

//initialize global vars among other things
void initialize(std::vector<Product> &products, threadController &tControl){	
	products = tControl.updateProducts();
	BOOST_FOREACH(Product v, products){
		v.print();
	}

}

void driver(OrderController &oControl, std::vector<Product> &products, threadController &tControl){
	std::string input;
	
	while(!(input == "quit")){
		std::cout << ">";
		std::getline(std::cin, input);
		commandTable(input, oControl, products, tControl);
	}

}

void commandTable(std::string &input, OrderController &oControl, std::vector<Product> &products, 
		threadController &tControl){
	if(input == "print products") {
		if(products.size() == 0){
			std::cout << "No products in database" << std::endl;
		}
		BOOST_FOREACH(Product v, products){
			v.print();
		}
	} 
	if(input == "print queue"){
		oControl.printQueue();
	}
	if(input == "print inprogress"){
		oControl.printInProgress();
	}
	if(input == "print completed"){
		oControl.printCompleted();
	}
	if(input == "print all"){
		oControl.printAll();
	}
	if(input == "update"){
		std::cout << "Updating" << std::endl;
		products = tControl.updateProducts();
		std::cout << "Updated" << std::endl;
		BOOST_FOREACH(Product v, products){
			v.print();
		}
	
	}	
}

/*TESTING BLOCKS (insert into main to test various functions)

-Test race conditions in thread controller
	std::thread t1(&threadController::updateProducts, &tControl);
	std::thread t2(&threadController::updateProducts, &tControl);
	std::thread t3(&threadController::updateProducts, &tControl);
	std::thread t4(&threadController::updateProducts, &tControl);
	std::thread t5(&threadController::updateProducts, &tControl);
	t1.join():
	t2.join();
	t3.join();
	t4.join();
	t5.join();

-Test if functions are passing into orders properly
	Order newOrder(buyStrategies[immediateTradeB], 0, 0, 0, 0);
	newOrder.executeTrade();


*/
