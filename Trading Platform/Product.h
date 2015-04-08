//object to hold each individual product from the CME Group JSON
#ifndef PRODUCT_H
#define PRODUCT_H

#include "stdafx.h"

class Product
{
public:
	Product();
	bool set(boost::property_tree::ptree, std::string); //sets all properties of the product
	std::string get(int); //returns the string of the corresponding enum
	void print();
	enum jsonCodes {
		exchangeCode,
		currentMonth,
		price,
		priceIndicator,
		name,
		groupName,
		globexOrFloor,
		netChange,
		tradeDate,
		URL,
		exchange_code,
		closePrice,
		highLimitPrice,
		lowLimitPrice,
		lowPrice,
		highPrice,
		openInterest,
		openPrice,
		priorSettlePrice,
		productType,
		settlePrice,
		ticker,
		tradeQuantity,
		formattedHighLowLimit,
		lowPriceIndicator,
		highPriceIndicator,
		fullTradeDate,
		priceChartCode,
		volumeChartCode,
		order,
		assetClass,
		moyrCode,
		globexCode,
		floorCode,
		cumulativeVolume,
		appendToPriceChartCode,
		netChange2,
		color
	};
protected:
private:
	std::string contents[38];
//variables to mirror the json from CMEGroup - unknown how many of these I will actually use

};




#endif