#ifndef PRICEFETCHING_H
#define PRICEFETCHING_H


//contains functions for fetching the costs of the commodities


#include "Globals.h"
#include "stdafx.h"
#include "Product.h"

bool updatePrices(); //refreshes all prices

bool parseFileData(std::vector<Product> &);// parses the file data into the products vector

#endif