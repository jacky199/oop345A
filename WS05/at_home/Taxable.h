/**********************************************************
 * Name: jack
 * Student ID: 123456789
 * Seneca email:jack@myseneca.ca
 **********************************************************/
#ifndef SICT_TAXABLE_H
#define SICT_TAXABLE_H
#include<iostream>
namespace sict{
	class Taxable{
	float taxrate;
	public:
		Taxable(float rate){
		taxrate = rate;
		}
		float operator()(float price){
			return price*(1 + taxrate);
		}
	};
}
#endif