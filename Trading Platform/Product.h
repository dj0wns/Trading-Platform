//object to hold each individual product from the CME Group JSON
#ifndef PRODUCT_H
#define PRODUCT_H

#include "stdafx.h"

class Product
{
public:
	Product();
	bool set(boost::property_tree::ptree, std::string);
	enum jsonCodes {
		exchangeCode,
		currentMonth,
		price,
		priceIndicator,
		Name,
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
		order,
		assetClass,
		moyrCode,
		globexCode,
		floorCode,
		cumulativeVolume,
		appendToPriceChartCode,
		color
	};
protected:
private:
	std::string contents[40];
//variables to mirror the json from CMEGroup - unknown how many of these I will actually use

};




#endif