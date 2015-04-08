
#define _CRT_SECURE_NO_DEPRECATE // for fopen

//contains functions for fetching best price of a stock or security or currency

//plan to use YQL to fetch data and an xml parser to parse the data into a usable format
// may also check against bid listings on a variety of sites to give the most relevant price
#include "Globals.h"
#include "stdafx.h"
#include "Product.h"
using namespace boost::filesystem;

size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {

	//check if folder exists
	if (exists("CMEGroupFiles")){
		if (!is_directory("CMEGroupFiles")){
			remove("CMEGroupFiles");
			if (!create_directory("CMEGroupFiles")){
				std::cout << "Unable to write to file";
				return 0;
			}
		}

	}
	else{
		if (!create_directory("CMEGroupFiles")){
			std::cout << "Unable to write to file";
			return 0;
		}
	}


	size_t written = fwrite(ptr, size, nmemb, stream);
	return written;
}

std::vector<Product> parseFileData(){ //parses the json into an obect list
	using boost::property_tree::ptree;
	ptree pt;
	read_json("CMEGroupFiles/commodities.json", pt);
	Product foo;
	std::string temp;
	std::vector<Product> products;

	//have this pass the contents to a new instance of product
	BOOST_FOREACH(ptree::value_type &v, pt.get_child("products")){
		if (((std::string)v.first.data()).compare("ALL_TICKERS") != 0){ //move out the useless node
			// only doing grains and metals atm
			temp = pt.get_child("products." + (std::string)v.first.data() + ".GROUP_NAME").data();
			if (temp.compare("Grains and Oilseeds") == 0 ||
				temp.compare("Precious") == 0){
				foo.set(pt, v.first.data());
				products.push_back(foo);
			}
		}
	}
	return products;
}

float fetchLowestPrice(std::string nameOfSecurity){  //returns the lowest price

    return 0;
}

float fetchHighestPrice(std::string nameOfSecurity){ //returns the highest price
    return 0;
}

bool updatePrices(){
	CURL *curl;
	CURLcode res;


	FILE *f = fopen("CMEGroupFiles/commodities.json","wb"); 
	curl = curl_easy_init();

	
	if (curl) {
		curl_easy_setopt(curl, CURLOPT_URL, "http://www.cmegroup.com/XSLT/homepage/DelayedQuotesJSON.html");
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);

		curl_easy_setopt(curl, CURLOPT_WRITEDATA, f);


		res = curl_easy_perform(curl);
		if (res != CURLE_OK){
			fprintf(stderr, "curl_easy_perform() failed: %s\n",
			curl_easy_strerror(res));
			return 0;
		}

		/* always cleanup */
		curl_easy_cleanup(curl);
	}
	fclose(f);
	parseFileData();
	return 1;
}

