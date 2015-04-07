
#define _CRT_SECURE_NO_DEPRECATE // for fopen

//contains functions for fetching best price of a stock or security or currency

//plan to use YQL to fetch data and an xml parser to parse the data into a usable format
// may also check against bid listings on a variety of sites to give the most relevant price
#include "Globals.h"
#include "stdafx.h"


size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata){
	std::ofstream fout;
	fout.open("CMEGroup/Commodities");
	fout << ptr;
	return 0;
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


	curl = curl_easy_init();

	
	if (curl) {
		curl_easy_setopt(curl, CURLOPT_URL, CME_GROUP_WEBPAGES[0]);
		/* example.com is redirected, so we tell libcurl to follow redirection */
		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, *write_callback);


		/* Perform the request, res will get the return code */
		res = curl_easy_perform(curl);
		/* Check for errors */
		if (res != CURLE_OK){
			fprintf(stderr, "curl_easy_perform() failed: %s\n",
			curl_easy_strerror(res));
			return 0;
		}

		/* always cleanup */
		curl_easy_cleanup(curl);
	}
	std::cout << res;

	return 1;
}

