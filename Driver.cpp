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
Driver:: Driver(const string aName): name(aName), isLoggedIn(true), isOnDelivery(false), hasDelivered(false), totalDeliveries(0), totalMinDelivering(0), totalMinDriving(0), totalTips(0.0), timeDepart(Time()), timeDeliver(Time()), timeArrive(Time()), order(Order())
{
    
}

/*Copy constructor
 @pre: none
 @post: Initializes the Driver to be equivalent to the other Driver object parameters.*/
Driver:: Driver(Driver& anotherDriver): name(anotherDriver.name), isLoggedIn(anotherDriver.isLoggedIn), isOnDelivery(anotherDriver.isOnDelivery), hasDelivered(anotherDriver.hasDelivered), totalDeliveries(anotherDriver.totalDeliveries), totalMinDelivering(anotherDriver.totalMinDelivering), totalTips(anotherDriver.totalTips), timeDepart(anotherDriver.timeDepart), timeDeliver(anotherDriver.timeDeliver), timeArrive(anotherDriver.timeArrive), order(anotherDriver.order), totalMinDriving(anotherDriver.totalMinDriving)
{
  //
}

/* Overload assignment operator:
 @pre: none
 @post: Sets the Driver to be equivalent to the other and returns a reference to the modified Driver.*/
Driver& Driver::operator=(Driver& anotherDriver){
    if (&anotherDriver != this)
    {
        name = anotherDriver.name;
        isLoggedIn = anotherDriver.isLoggedIn;
        isOnDelivery = anotherDriver.isOnDelivery;
        hasDelivered = anotherDriver.hasDelivered;
        totalDeliveries = anotherDriver.totalDeliveries;
        totalMinDelivering = anotherDriver.totalMinDelivering;
        totalTips = anotherDriver.totalTips;
        timeDepart = anotherDriver.timeDepart;
        timeDeliver = anotherDriver.timeDeliver;
        timeArrive = anotherDriver.timeArrive;
        totalMinDriving = anotherDriver.totalMinDriving;
    }
    return *this;
}

/* Login driver
 @pre: Driver is not logged in.
 @post: Logs the driver in.  */
void Driver:: login() throw (logic_error)
{
    if(isLoggedIn)
        throw logic_error("Is already logged in");
    
    isLoggedIn = true;
}

/* Logout driver
 @pre:Driver is logged in and at the restaurant.
 @post: Logs the driver out. */
void Driver::logout() throw (logic_error)
{
    if(!isLoggedIn)
    {
        throw logic_error("Is already logged out");
    }
    isLoggedIn = false;
}

/* Driver is delivering
 @pre: : Driver is logged in and at the restaurant.
 @post: Driver is delivering. Departure time is recorded.  */
void Driver::depart(const Time time, const Order o) throw (logic_error){
    if(!isLoggedIn)
        throw logic_error("Driver is not logged in");
    
    if (isOnDelivery)
        throw logic_error("Driver is already delivering");
    
    isOnDelivery = true;
    timeDepart = time;
    order = o;
    order.depart();
}

/*  Status of delivered driver
 @pre: Driver is delivering, tip >= 0.
 @post: Driver is not delivering. Driver’s stats are updated. */
void Driver::deliver(const Time time,const float tip) throw (logic_error){
    if (!isOnDelivery)
        throw logic_error("Driver is not on delivery");
    
    if (hasDelivered)
        throw logic_error("Order has been delivered");
    
    if (tip < 0)
        throw logic_error("Tip has to be equal to or greater than 0");
    
    order.deliver(time);
    
    hasDelivered = true;
    timeDeliver = time;
    totalDeliveries++;
    totalTips += tip;
    totalMinDelivering = Time::elapsedMin(timeDepart, timeDeliver);
}

/* Status of available drivers
 @pre: Driver is driving but not delivering.
 @post: Driver is at the restaurant. Driver’s stats are updated.  */
void Driver::arrive(const Time time) throw (logic_error){
    if(!isOnDelivery)
        throw logic_error(" Driver is on delivery");
    if(!hasDelivered)
        throw logic_error("Order has not been delivered");
    
    isOnDelivery = false;
    timeArrive = time;
    totalMinDriving = Time::elapsedMin(timeDepart, timeArrive);
    hasDelivered = false;
}

/* Driver's name
 @pre:
 @post:Returns the driver’s name. */
string Driver::getName() const{
    return name;
}


/*Get the total number
 @pre: none
 @post:Returns the total number of completed deliveries. */
int Driver::getTotalDeliveries() const{
    return totalDeliveries;
}

/* Total delivering time
 @pre: none
 @post:  Returns the total minutes spent delivering (i.e., between “depart” and “deliver” commands). */
int Driver::getTotalMinDelivering(){
    return totalMinDelivering;
}

/* Estimate the total spend time
 @pre: none
 @post: Returns the total minutes spent driving (i.e., between “depart” and “arrive” commands). */
int Driver::getTotalMinDriving() const{
    return totalMinDriving;
}

/* Show the total tips amount
 @pre: none
 @post: Returns the total tips received, in dollars.  */
float Driver::getTotalTips() const{
    return totalTips;
}

/* Show the infor of delivering number
 @pre: Driver is delivering.
 @post: Returns the order being delivered.  */
Order Driver::getOrder() throw (logic_error){
    if(!isOnDelivery)
        throw logic_error("Driver is not on delivery");
    return order;
}

/* Show structure
 @pre: none
 @post: Returns a string containing the driver’s name, state (e.g., not logged in), and, if the driver is delivering an order, the departure time and toString of the order being delivered.  */
string Driver::toString() const{
    string driver_info;
    driver_info = name + " ";
    
    if (isLoggedIn)
        driver_info.append("is logged in ");
    else
        driver_info.append("is not logged in.");
    
    if (isOnDelivery)
        driver_info += "and departed at " + order.toString();
    
    return driver_info;
}

/*Avg delivery time
 @pre: none
 @post: average time per completed delivery of driver (from “depart” to “deliver”). Return N/A if there is no completed delivery*/
float Driver::averageDeliveryTime() const{
    float average_time = (totalDeliveries != 0) ? (float)totalMinDelivering / totalDeliveries : 0;
    
    return average_time;
}

/* Checking if the driver logged in
 @pre: none
 @post: Returns true if and only if the driver is logged in. */
bool Driver::loggedIn(){
    return isLoggedIn;
}

