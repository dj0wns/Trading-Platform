#ifndef PRICEFETCHING_H
#define PRICEFETCHING_H

#include "Globals.h"
#include "stdafx.h"
#include "Product.h"

float fetchLowestPrice(std::string nameOfSecurity);  //returns the lowest price

float fetchHighestPrice(std::string nameOfSecurity); //returns the highest price

std::vector<Product> updatePrices(); //refreshes all prices

std::vector<Product> parseFileData();// parses the file data into the products vector

#endif