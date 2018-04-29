//
//  Order.cpp
//  PizzaDelivery
//
//  Created by Nguyen Tam on 4/23/18.
//  Copyright © 2018 Nguyen Tam. All rights reserved.
//

#include "Order.h"
#include <iostream>
/*Constructor
 @pre: none
 @post: constructor; creates an order with the given order and information*/
Order:: Order( Time time, string info)
{
    this->time = time;
    this->infor = info;
    ordersStatus = 0;
    
}

/* depart time
 @pre: Order is at the restaurant.
 @post: Order is out for delivery*/
void Order:: depart() throw (logic_error)
{
    if(ordersStatus != 0)
        throw logic_error("Order is not at restaurant.");
    ordersStatus = 1;
}

/*delivery
 @pre: Order is out for delivery
 @post: Order is delivered. Time to delivery is recorded*/
void Order:: deliver(const Time time) throw (logic_error)
{
        if(ordersStatus != 1)
            throw logic_error ("Order is not out for delivery." );
    deliverTime = time;
    ordersStatus = 2;
}

/*Calculate time to delivery
 @pre: Oder is delivered
 @post: returns the minutes until the order is delivered*/
int Order:: getMinToDelivery() const throw (logic_error)
{
    if (ordersStatus != 1)
        throw logic_error ("Order is not out for delivery");
    return Time:: elapsedMin(time, deliverTime);
}

/*show Structure
 @pre: none
 @post: Show a string containing the order time and information*/
string Order:: toString() const
{
    return time.toString() + " "  + info;
}
