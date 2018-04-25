//
//  Driver.cpp
//  PizzaDelivery
//
//  Created by Nguyen Tam on 4/23/18.
//  Copyright © 2018 Nguyen Tam. All rights reserved.
//
#include <iostream>
#include <string>
#include "Driver.h"
#include "Time.h"
#include "Order.h"


using namespace std;


/* Constructor
 @pre: none
 @post: : Creates a logged-in driver with the given name.  */
Driver:: Driver(const string name){
    
}

/*Assignment operator
 @pre: none
 @post: Initializes the Driver to be equivalent to the other Driver object parameters.*/
Driver:: Driver(Driver& anotherDriver){
    
}

/* Overload assignment operator:
 @pre: none
 @post: Sets the Driver to be equivalent to the other and returns a reference to the modified Driver.*/
Driver& Driver::operator=(Driver& anotherDriver){
    
}

/* Login driver
 @pre: Driver is not logged in.
 @post: Logs the driver in.  */
void Driver:: login() throw (logic_error){
    
}

/* Logout driver
 @pre:Driver is logged in and at the restaurant.
 @post: Logs the driver out. */
 void Driver::logout() throw (logic_error){
    
}

/* Driver is delivering
 @pre: : Driver is logged in and at the restaurant.
 @post: Driver is delivering. Departure time is recorded.  */
 void Driver::depart(const Time time, const Order o) throw (logic_error){
    
}

/*  Status of delivered driver
 @pre: Driver is delivering, tip >= 0.
 @post: Driver is not delivering. Driver’s stats are updated. */
 void Driver::deliver(const Time time,const float tip) throw (logic_error){
    
}

/* Status of available drivers
 @pre: Driver is driving but not delivering.
 @post: Driver is at the restaurant. Driver’s stats are updated.  */
 void Driver::arrive(const Time time) throw (logic_error){
    
}

/* Driver's name
 @pre:
 @post:Returns the driver’s name. */
string Driver::getName() const{
    
}


/*Get the total number
 @pre: none
 @post:Returns the total number of completed deliveries. */
int Driver::getTotalDeliveries(){
    
}

/* Total delivering time
 @pre: none
 @post:  Returns the total minutes spent delivering (i.e., between “depart” and “deliver” commands). */
int Driver::getTotalMinDelivering(){
    
}

/* Estimate the total spend time
 @pre: none
 @post: Returns the total minutes spent driving (i.e., between “depart” and “arrive” commands). */
int Driver::getTotalMinDriving(){
    
}

/* Show the total tips amount
 @pre: none
 @post: Returns the total tips received, in dollars.  */
float Driver::getTotalTips(){
    
}

/* Show the infor of delivering number
 @pre: Driver is delivering.
 @post: Returns the order being delivered.  */
Order Driver::getOrder() throw (logic_error){
    
}

/* Show structure
 @pre: none
 @post: Returns a string containing the driver’s name, state (e.g., not logged in), and, if the driver is delivering an order, the departure time and toString of the order being delivered.  */
string Driver::toString() const{
    
}

/*Avg delivery time
 @pre: none
 @post: average time per completed delivery of driver (from “depart” to “deliver”). Return N/A if there is no completed delivery*/
float Driver::averageDeliveryTime() const{
    
}

/* Checking if the driver logged in
 @pre: none
 @post: Returns true if and only if the driver is logged in. */
bool Driver::isLoggedIn(){
    
}
