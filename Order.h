//
//  Order.hpp
//  PizzaDelivery
//
//  Created by Nguyen Tam on 4/23/18.
//  Copyright © 2018 Nguyen Tam. All rights reserved.
//

#ifndef Order_hpp
#define Order_hpp

#include <stdio.h>
#include <string>
#include "Time.h"

using namespace std;

class Order {
    //The Order class represents an order of one or more food items placed by a customer.
    //The order can be in one of three states: at the restaurant, out for delivery, or delivered.
    //The order keeps track of the time it was placed, the information needed to cook and deliver it (food items and address), and the time taken to deliver it.
    
public:
    /*Constructor
     @pre: none
     @post: constructor; creates an order with the given order and information*/
    Order( const Time time = Time(),  const string info = "");
    
    /* depart time
     @pre: Order is at the restaurant.
     @post: Order is out for delivery*/
    void depart() throw (logic_error);
    
    /*delivery
     @pre: Order is out for delivery
     @post: Order is delivered. Time to delivery is recorded*/
    void deliver(const Time time) throw (logic_error);
    
    /*Calculate time to delivery
     @pre: Oder is delivered
     @post: returns the minutes until the order is delivered*/
    int getMinToDelivery() const throw (logic_error);
    
    /*show Structure
     @pre: none
     @post: Show a string containing the order time and information*/
    string toString() const;
    
private:
    Time time; // the time order was placed
    string infor; // the information needed to cook and deliver it
    int ordersStatus; // The status of the order:
    // status = 0: if the order is at the restaurant
    // status = 1 if the order is out for delivery
    // statuas = 2 if the order is delivered
    
    Time deliverTime; // Time when the order is delivered
};

#endif /* Order_h*/
