// Author:  Karan Sahu
// Assignment Number: Lab 2
// File Name: KaranSahuLab2.cpp
// Course/Section: COSC 1337 Section 003
// Due Date:  6/21/2018
// Instructor: Bernard Ku
//
//  This program will take in and display finacial information about spools purchase
//
#include <iostream>
#include <string.h>     // std::string, std::stoi
#include <iomanip>
#include <stdexcept>
#include<sstream>
#include <stdio.h>


using namespace std;



const double UNIT_SPOOL_COST = 100.00, SHIPPING_CHARGE  = 10.00;

// Function prototypes
void getOrderInfo (int &, int &, double &);
void processDisplayStatus(int, int, double );

int main()
{
    int numOrdered ,              // Number of spools ordered
              inStock;                 // Number of spools in stock
    double specialChgs;    // Special charges (if any) to ship the spools

    getOrderInfo(numOrdered, inStock, specialChgs);

	if(specialChgs != 0.0)			//    if Special charges are not zero - call the second function and add shipping and special charges together
    	processDisplayStatus(numOrdered, inStock, SHIPPING_CHARGE + specialChgs);
//     if Special charges are zero - call the second function and add shipping charges only

    else
		processDisplayStatus(numOrdered, inStock, SHIPPING_CHARGE);

    return 0;
}// end of main function
bool IsValidNumber(char * string)
{
   for(int i = 0; i < strlen( string ); i ++)
   {
      //ASCII value of 0 = 48, 9 = 57. So if value is outside of numeric range then fail
      //Checking for negative sign "-" could be added: ASCII value 45.
      if (string[i] < 48 || string[i] > 57)
         return false;
   }
 
   return true;
}

bool IsValidDouble(char * string)
{
   for(int i = 0; i < strlen( string ); i ++)
   {
		if (string[i] == 46)
			return true;
      //ASCII value of 0 = 48, 9 = 57. So if value is outside of numeric range then fail
      //Checking for negative sign "-" could be added: ASCII value 45.
      if (string[i] < 48 || string[i] > 57)
         return false;
   }
 
   return true;
}
/*************************************************************
 *                        getOrderInfo                       *
 * This function is called by main to input and validate     *
 * the number of spools ordered, the number in stock, and    *
 * any special shipping charges. These values are stored in  *
 * reference parameters.                                     *
 *************************************************************/
void getOrderInfo(int &order, int &inStock, double &specChg)

{
	
	string b, a , c;
	
	stringstream conv;
	
	order = -1;
	inStock = -1;
	specChg = -1;
	
	do 
	{
		cout << "How many spools were ordered(please enter an integer)? ";
		cin >> b;
		
	//	const_cast<char*>(b.c_str())
		
		if (IsValidNumber(	const_cast<char*>(b.c_str())))
		{
		
			conv << b;
			conv >> order;
			
			cout << endl;
		}
	}while (order < 0);
	
	stringstream conv1;
	do 
	{
		cout << "How many spools in stock?(please enter an integer) ";
		cin >> b;
		
	//	const_cast<char*>(a.c_str())
		
		if (IsValidNumber(	const_cast<char*>(b.c_str())))
		{
		
			conv1 << b;
			conv1 >> inStock;
			
			cout << endl;
		}
	}while (inStock < 0);
	
	stringstream conv2;
	do 
	{
		cout << "Amount of any special shipping charges (per spool)" << endl << "above the regular $10 per spool rate (0 for none)(please enter a number): ";
		cin >> b;
		
	//	const_cast<char*>(b.c_str())
		
		if (IsValidDouble(	const_cast<char*>(b.c_str())))
		{
		
			conv2 << b;
			conv2 >> specChg;
			
			cout << endl;
		}
	}while (specChg < 0);
	


}



/***************************************************************
 *                       processDisplayStatus                         *
 * This function is called by main and passed as arguments the *
 * number of spools ordered, the number in stock, and the      *
 * shipping charge per spool. The default value for shipping   *
 * charge is $10.00. This information is used to display an    *
 * order status report.                                        *
 ***************************************************************/


void processDisplayStatus(int numOrdered, int inStock, double ShipChg)
{
	int thisShipment;
	int backOrder;
	double total;
	
	if (numOrdered <= inStock)
	{
		backOrder = 0;
		thisShipment = numOrdered;
	}
	else 
	{	
		thisShipment = inStock;
		backOrder = numOrdered - inStock;
	}
	cout << "      *** Order Summary ***" << endl << endl;
	cout << left << setw(30) << "spools ordered: " << numOrdered << endl;
	cout << left << setw(30) << "spools in this shipment: " << thisShipment << endl;
	cout << left << setw(30) << "spools back ordered: " << backOrder << endl;

	cout << endl;
	
	cout << "    Charges for this shipment" << endl;
	cout << "    -------------------------"	<< endl << endl;
	
	cout << left << setw(21) << "Spool charges:" << "$  " << UNIT_SPOOL_COST * thisShipment << endl;
	cout << left << setw(21) << "Shipping charges:" << "$  " << thisShipment * (ShipChg) << endl;
	total = (UNIT_SPOOL_COST * thisShipment ) + (thisShipment * (ShipChg));
	cout << left << setw(21) << "Total this shipment:" << "$  " << total;
	
		
	
}




/* SAMPLE OUTPUT
How many spools were ordered(please enter an integer)? -1
How many spools were ordered(please enter an integer)? j
How many spools were ordered(please enter an integer)? 10

How many spools in stock?(please enter an integer) -1
How many spools in stock?(please enter an integer) p
How many spools in stock?(please enter an integer) 8

Amount of any special shipping charges (per spool)
above the regular $10 per spool rate (0 for none)(please enter a number): -1
Amount of any special shipping charges (per spool)
above the regular $10 per spool rate (0 for none)(please enter a number): a
Amount of any special shipping charges (per spool)
above the regular $10 per spool rate (0 for none)(please enter a number): 10

      *** Order Summary ***

spools ordered:               10
spools in this shipment:      8
spools back ordered:          2

    Charges for this shipment
    -------------------------

Spool charges:       $  800
Shipping charges:    $  160
Total this shipment: $  960


*/
