//
//  Restaurant.cpp
//  PizzaDelivery
//
//  Created by Nguyen Tam on 4/23/18.
//  Copyright © 2018 Nguyen Tam. All rights reserved.
//


#include <iostream>
#include <deque>
#include <vector>
#include <iomanip>
#include "Restaurant.h"
#include "Order.h"
#include "Driver.h"
#include "Time.h"

/* Create an empty restaurant
 @pre: none
 @post: Create an initial restaurant without any orders/drivers */
Restaurant:: Restaurant(): totalOrders(0), totalOrderTime(0){
    
}

/*
 @pre: none
 @post: Prints status of orders and logged-in drivers, as specified by the “status” command description. */
void Restaurant::status() const{
    
}

/*
 @pre: none
 @post:Prints summary statistics on orders and drivers, as specified by the “summary” command description.  */
void Restaurant::summary() const{
    
}

/*
 @pre: none
 @post:If a driver with the given name exists within the system (logged in or not), returns a pointer to that driver. Otherwise, returns a null pointer*/
Driver* Restaurant::getDriver( const string name) const{
    
}

/*
 @pre: none
 @post:Adds the given driver to the system.  */
void Restaurant::addDriver(Driver* driver) const throw (logic_error){
    
}

/*
 @pre: none
 @post: Adds the given order to the system, enqueuing it for cooking.  */
void Restaurant::addOrder(Order* order){
    
}

/*
 @pre: The cooking queue is not empty.
 @post: Removes the oldest order from the cooking queue and enqueues it for departure.   */
void Restaurant::serveNextOrder() throw (logic_error){
    
}

/*
 @pre: The departure queue is not empty.
 @post: Removes the oldest order from the departure queue and returns */
Order* Restaurant::departNextOrder() throw (logic_error){
    
}

/*
 @pre: none
 @post: The order carried by the driver is delivered at the given time. The driver receives the given tip.  */
void Restaurant::deliver(Driver* driver, const Time time, const float tip){
    
}

/*avg order time
 @Pre: none
 @Post: returns the average time for each order (from receiving to delivering)*/
float Restaurant::averageOrderTime() const
{

}
