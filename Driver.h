//
//  Driver.hpp
//  PizzaDelivery
//
//  Created by Nguyen Tam on 4/23/18.
//  Copyright © 2018 Nguyen Tam. All rights reserved.
//

#ifndef Driver_hpp
#define Driver_hpp

#include <iostream>
#include <string>
#include "Time.h"
#include "Order.h"


using namespace std;

class Order {
    //The Driver class represents a pizza delivery driver.
    //The driver can be in one of several states: not logged in, logged in and at the restaurant, delivering (i.e., on the way to a delivery), and driving (i.e., on the way back from a delivery).
    //The driver keeps track of its own stats (time delivering, time driving, tips, and number of deliveries). If the driver is currently delivering an order, the driver stores the order.
    
public:
    
    /* Constructor
     @pre: none
     @post: : Creates a logged-in driver with the given name.  */
    Driver(const string name);
    
    /* Login driver
     @pre: Driver is not logged in.
     @post: Logs the driver in.  */
    void login() throw (logic_error);
    
    /* Logout driver
     @pre:Driver is logged in and at the restaurant.
     @post: Logs the driver out. */
    void logout() throw (logic_error);
    
    /* Driver is delivering
     @pre: : Driver is logged in and at the restaurant.
     @post: Driver is delivering. Departure time is recorded.  */
    void depart(Time time, Order o) throw (logic_error);
    
    /*  Status of delivered driver
     @pre: Driver is delivering, tip >= 0.
     @post: Driver is not delivering. Driver’s stats are updated. */
    void deliver(Time time, float tip) throw (logic_error);
    
    /* Status of available drivers
     @pre: Driver is driving but not delivering.
     @post: Driver is at the restaurant. Driver’s stats are updated.  */
    void arrive(Time time) throw (logic_error);
    
    /* Driver's name
     @pre:
     @post:Returns the driver’s name. */
    string getName();
    
    /* Checking if the driver logged in
     @pre: none
     @post: Returns true if and only if the driver is logged in. */
    bool isLoggedIn();
    
    /*Get the total number
     @pre: none
     @post:Returns the total number of completed deliveries. */
    int getTotalDeliveries();
    
    /* Total delivering time
     @pre: none
     @post:  Returns the total minutes spent delivering (i.e., between “depart” and “deliver” commands). */
    int getTotalMinDelivering();
    
    /* Estimate the total spend time
     @pre: none
     @post: Returns the total minutes spent driving (i.e., between “depart” and “arrive” commands). */
    int getTotalMinDriving();
    
    /* Show the total tips amount
     @pre: none
     @post: Returns the total tips received, in dollars.  */
    float getTotalTips();
    
    /* Show the infor of delivering number
     @pre: Driver is delivering.
     @post: Returns the order being delivered.  */
    Order getOrder() throw (logic_error);
    
    /* Show structure
     @pre: none
     @post: Returns a string containing the driver’s name, state (e.g., not logged in), and, if the driver is delivering an order, the departure time and toString of the order being delivered.  */
    string toString() const;
    
private:
    
    string name; // Driver's name

    bool isLoggedIn; //True if the driver is on delivery, false otherwise
    
    bool hasDelivered; // True if the order has been delivered, false otherwise
    
    int totalDeliveres; // total deliveries
    
    int totalMinDelivering; // total min spent per deivery ( from departing to delivering)
    
    int totalMinDriving; // total min spent for driving/delivery
    
    float totalTips; // totalTips that the driver receives
    
    Order order; // the order the driver is delivering
    
    Time timeDepart; // departure time
    
    Time timeDeliver; //Time of delivery
    
    Time timeArrive; //Arrival time
};
#endif /* Driver_h */
