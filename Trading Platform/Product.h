//object to hold each individual product from the CME Group JSON
#ifndef PRODUCT_H
#define PRODUCT_H

#include "stdafx.h"

class Product
{
public:
	Product();
protected:
private:
//variables to mirror the json from CMEGroup - unknown how many of these I will actually use
	std::string exchangeCode,
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
		color;
};




#endif