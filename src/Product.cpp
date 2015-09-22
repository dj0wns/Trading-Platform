#include "Product.h"

Product::Product()
{
	//ctor - intentionally blank atm
}
bool Product::set(boost::property_tree::ptree &pt, std::string path){  //sets all values of product
	int i = 0;
	BOOST_FOREACH(boost::property_tree::ptree::value_type &v, pt.get_child("products." + path)){
		contents[i] = v.second.data();
		i++;
	}

	return 1;
}

std::string Product::get(int index){
	return contents[index];
}

//prints formatted data about the product
void Product::print(){
	std::cout << contents[name] << "\t" << contents[ticker] << "\t" << contents[price]
	       	<< "\t" << contents[priceIndicator] <<  std::endl;

}
