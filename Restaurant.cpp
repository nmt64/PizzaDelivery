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
void Restaurant::status() const
{
    cout << "Order waiting to cook:" << endl;
    
    //iterates through cooking queue and prints out the information of each order
    for (deque<Order*>:: const_iterator order = order_queue.begin(); order != order_queue.end(); order++)
        cout << "   " << (**order).toString() << endl;
    cout << "Orders waiting to depart:" << endl;
    
    
    //iterates through delivery queue and prints out the information for each order
    for (deque<Order*>:: const_iterator order = delivery_queue.begin(); order != delivery_queue.end(); order++)
        cout << "   " << (**order).toString() << endl;
    cout << "Driver: " << endl;
    
    //iterates through the driver list and prints out all the logged-in drivers ( and there current delivery)
    for (vector<Driver*>:: const_iterator driver = driver_list.begin(); driver != driver_list.end(); driver++)
        cout << "   " << (**driver).toString() << endl << endl;
    
}

/*
 @pre: none
 @post:Prints summary statistics on orders and drivers, as specified by the “summary” command description.  */
void Restaurant::summary() const
{
    cout << "Number of orders completed: " << totalOrders << endl;
    cout << "Average time per order: " << fixed << setprecision(1) << averageOrderTime() << endl;
    
    
    //iterates through the driver list and prints out information of each driver
    for (vector<Driver*>:: const_iterator driver = driver_list.begin(); driver != driver_list.end(); driver++)
    {
        cout << "Driver " << (**driver).getName() << endl;
        cout << " Number of deliveries completed: " << (**driver).getTotalDeliveries() << endl;
        cout << " Average time per delivery: " ;
        
        if ((**driver).averageDeliveryTime() == 0) // If driver did not make any delivery, print "N/A"
            cout << "N/A" << endl;
        else
            cout << fixed << setprecision(1) << (**Driver).averageDeliveryTime() << endl;
        
        cout << " Total Driving Time:" << (**driver).getTotalMinDriving() << endl;
        cout << " Total Tips: " <<(**driver).getTotalTips() << endl;
    }
    
    cout << endl;
    
}

/*
 @pre: none
 @post:If a driver with the given name exists within the system (logged in or not), returns a pointer to that driver. Otherwise, returns a null pointer*/
Driver* Restaurant::getDriver( const string name) const{
    vector<Driver*>::const_iterator driver = driver_list.begin();
    
    Driver* driverPtr = nullptr;
    bool driverExists = false;
    
    while (!driverExists && driver != driver_list.end()) //iterates through the driver list
    {
        if ((**driver).getName() == name) //checks if a driver with that name already exists in the system
        {
            driverPtr = *driver;
            driverExists = true;
        }
        driver++;
    }
    
    return driverPtr;
    
}

/*
 @pre: none
 @post:Adds the given driver to the system.  */
void Restaurant:: addDriver(Driver* driver) throw (logic_error)
{
    if (getDriver((*driver).getName()) != nullptr)
        throw logic_error("Driver with this name already exists");
    
    driver_list.push_back(driver); //adds driver to driver list
}

/*
 @pre: none
 @post: Adds the given order to the system, enqueuing it for cooking.  */
void Restaurant::addOrder(Order* order)
{
    order_queue.push_back(order); //adds order to order list
}

/*
 @pre: The cooking queue is not empty.
 @post: Removes the oldest order from the cooking queue and enqueues it for departure.   */
void Restaurant::serveNextOrder() throw (logic_error)
{
    if (order_queue.size() == 0)
        throw logic_error("No uncooked order");
    delivery_queue.push_back(order_queue.front()); // adds next order to delivery queue
    order_queue.pop_front();
}

/*
 @pre: The departure queue is not empty.
 @post: Removes the oldest order from the departure queue and returns */
Order* Restaurant::departNextOrder() throw (logic_error)
{
    if (delivery_queue.size() == 0)
        throw logic_error ("No order to be delivered");
    
    Order* departing_order = delivery_queue.front();
    delivery_queue.pop_front();
    
    return departing_order;
}

/*
 @pre: none
 @post: The order carried by the driver is delivered at the given time. The driver receives the given tip.  */
void Restaurant::deliver(Driver* driver, const Time time, const float tip)
{
    (*driver).deliver(time,tip);
    totalOrders++;
    totalOrderTime += (*driver).getOrder().Order::getMinToDelivery();
    
}

/*avg order time
 @Pre: none
 @Post: returns the average time for each order (from receiving to delivering)*/
float Restaurant::averageOrderTime() const
{
    float average_time = (totalOrders != 0) ? (totalOrderTime / totalOrders) : 0; //calculates the average time per order, 0 if there is no order
    
    return average_time;
}
