#ifndef PRICEFETCHING_H
#define PRICEFETCHING_H


//contains functions for fetching the costs of the commodities


#include "Globals.h"
#include "stdafx.h"
#include "Product.h"

std::vector<Product> updatePrices(); //refreshes all prices

std::vector<Product> parseFileData();// parses the file data into the products vector

#endif