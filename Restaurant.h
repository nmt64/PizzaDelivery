//
//  Restaurant.hpp
//  PizzaDelivery
//
//  Created by Nguyen Tam on 4/23/18.
//  Copyright © 2018 Nguyen Tam. All rights reserved.
//

#ifndef Restaurant_hpp
#define Restaurant_hpp

#include <stdio.h>
#include <string>
#include <deque>
#include <vector>
#include "Driver.h"
#include "Order.h"

using namespace std;

class Restaurant {
    //The Restaurant class keeps track of all drivers and orders in the system, including logged-out drivers and completed orders.
    //Think carefully about whether to store these as objects or pointers to objects.
    
public:
    
    /* Create an empty restaurant
     @pre: none
     @post: Create an initial restaurant without any orders/drivers */
    Restaurant();
    
    /*
     @pre: none
     @post: Prints status of orders and logged-in drivers, as specified by the “status” command description. */
    void status() const;
    
    /*
     @pre: none
     @post:Prints summary statistics on orders and drivers, as specified by the “summary” command description.  */
    void summary() const;
    
    /*
     @pre: none
     @post:If a driver with the given name exists within the system (logged in or not), returns a pointer to that driver. Otherwise, returns a null pointer*/
    Driver * getDriver( const string name) const;
    
    /*
     @pre: none
     @post:Adds the given driver to the system.  */
    void addDriver(Driver* driver) const throw (logic_error);
    
    /*
     @pre: none
     @post: Adds the given order to the system, enqueuing it for cooking.  */
    void addOrder(Order* order);
    
    /*
     @pre: The cooking queue is not empty.
     @post: Removes the oldest order from the cooking queue and enqueues it for departure.   */
    void serveNextOrder() throw (logic_error);
    
    /*
     @pre: The departure queue is not empty.
     @post: Removes the oldest order from the departure queue and returns */
    Order* departNextOrder() throw (logic_error);
    
    /*
     @pre: none
     @post: The order carried by the driver is delivered at the given time. The driver receives the given tip.  */
    void deliver(Driver * driver, const Time time, const float tip);
private:
    vector<Driver*> driver_list; // A vector containing all the drivers
    deque<Order*> order_queue; // The cooking queue
    deque<Order*> delivery_queue; // The delivery queue
    
    int totalOrders; // number of total orders
    int totalOrderTime; // The total time of all orders ( from receiving to delivering
    
    
    /*avg order time
     @Pre: none
     @Post: returns the average time for each order (from receiving to delivering)*/
    float averageOrderTime() const;
};
#endif /* Restaurant_hpp */
