#ifndef PRICEFETCHING_H
#define PRICEFETCHING_H


float fetchLowestPrice(std::string nameOfSecurity);  //returns the lowest price

float fetchHighestPrice(std::string nameOfSecurity); //returns the highest price

bool updatePrices(); //refreshes all prices

#endif