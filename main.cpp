//
//  main.cpp
//  PizzaDelivery
//
//  Created by Nguyen Tam on 4/29/18.
//  Copyright © 2018 Nguyen Tam. All rights reserved.
//


#include <iostream>
#include <string>
#include <vector>

#include <ctime>
#include <iomanip>
#include "Time.h"
#include "Restaurant.h"

using namespace std;

//~~~~~Function prototypes~~~~~

// Pre: Driver is not logged in
// Post: The driver logs into the system
void login(string driver, Restaurant& aRestaurant) throw (logic_error);

// Pre: The driver is logged in
// Post: The driver log out of the system
void logout(string driver, Restaurant& aRestaurant) throw (logic_error);

// Pre: None
// Post: add a new order to the system
void order(const Time& time, const string info, Restaurant& aRestaurant);

// Pre: None
// Post: An order is done cooking and enqueued for delivery. The information given in INFO for the corresponding “order” command is attached to the order.
void serve(const Time& time, Restaurant& aRestaurant);

// Pre: None
// Post: Driver goes out to deliver the next order enqueued for delivery
void depart(const Time& time, const string driver, Restaurant& aRestaurant);

// Pre: None
// Post: Driver completes delivering and receives tip
void deliver(const Time& time, const string driver, const float tip, Restaurant& arestaurant);

// Pre: None
// Post: driver return from delivering
void arrive(const Time& time, const string driver, Restaurant& aRestaurant);

// Pre: None
// Post: Showing the status of orders and drivers
void status(Restaurant& aRestaurant);

// Pre: None
// Post: Showing the summary statistics on orders and drivers
void summary(Restaurant& aRestaurant);

// Pre: None
// Post: Print help.
void print_help();

//~~~~~Main~~~~~

int main()
{
    Restaurant CyPiz; //a Restaurant object called "Cypiz"
    
    string command; //a string to hold the command
    
    string driver; //a string to hold the driver's name
    
    string string_time; //a string to hold time
    
    string info; //a string to hold an order's info
    
    print_help();
    cin >> command;

    
    while (command != "quit") {
        
        //Handles input and calls the corresponding function
        if (command == "help") {
            print_help();
        }
        
        else if (command == "login")
        {
            cin >> driver;
            login(driver, CyPiz);
        }
        
        else if (command == "logout")
        {
            cin >> driver;
            logout(driver, CyPiz);
        }
        
        else if (command == "order")
        {
            cin >> string_time;
            getline(cin, info);
            Time time(string_time);
            order(time, info, CyPiz);
        }
        
        else if (command == "serve")
        {
            cin >> string_time;
            Time time(string_time);
            serve(time, CyPiz);
        }
        
        else if (command == "depart")
        {
            cin >> string_time;
            Time time(string_time);
            cin >> driver;
            depart(time, driver, CyPiz);
        }
        
        else if (command == "deliver")
        {
            cin >> string_time;
            Time time(string_time);
            cin >> driver;
            float tip;
            cin >> tip;
            deliver(time, driver, tip, CyPiz);
        }
        
        else if (command == "arrive")
        {
            cin >> string_time;
            Time time(string_time);
            cin >> driver;
            arrive(time, driver, CyPiz);
        }
        
        else if (command == "status")
            status(CyPiz);
        
        else if (command == "summary")
            summary(CyPiz);
        
        else
            cout << "Not a valid command" << endl;
        
        cin >> command;
    }
    
    return 0;
}

//~~~~~Implementation~~~~~

// Pre: Driver is not logged in
// Post: The driver logs into the system
void login(string driver, Restaurant& arestaurant) throw (logic_error) {
    Driver* DriverPtr =  arestaurant.getDriver(driver);
    if (DriverPtr == nullptr) {
        
        Driver* aDriver = new Driver(driver);
        arestaurant.addDriver(aDriver);
    }
    else
        throw logic_error("The driver is already logged in");
}

// Pre: The driver is logged in
// Post: The driver log out of the system
void logout(string driver, Restaurant& arestaurant) throw (logic_error){
    
    Driver* DriverPtr =  arestaurant.getDriver(driver);
    
    if (DriverPtr == nullptr) {
        throw logic_error("Driver does not exist");
    }
    (*DriverPtr).logout();
}

// Pre: None
// Post: add a new order to the system
void order(const Time& time, const string info, Restaurant& arestaurant) {
    Order* anOrder = new Order(time,info);
    arestaurant.addOrder(anOrder);
}

// Pre: None
// Post: An order is done cooking and enqueued for delivery. The information given in INFO for the corresponding “order” command is attached to the order.
void serve(const Time& time, Restaurant& arestaurant) {
    arestaurant.serveNextOrder();
}

// Pre: None
// Post: Driver goes out to deliver the next order enqueued for delivery
void depart(const Time& time, const string driver, Restaurant& arestaurant) {
    Order*departOrder = arestaurant.departNextOrder();
    Driver*DriverPtr =  arestaurant.getDriver(driver);
    DriverPtr->depart(time, *departOrder);
}

// Pre: None
// Post: Driver completes delivering and receives tip
void deliver(const Time& time, const string driver, const float tip, Restaurant& arestaurant) {
    Driver*DriverPtr =  arestaurant.getDriver(driver);
    arestaurant.deliver(DriverPtr, time, tip);
}

// Pre: None
// Post: driver return from delivering
void arrive(const Time& time, const string driver, Restaurant& arestaurant) {
    Driver*DriverPtr =  arestaurant.getDriver(driver);
    DriverPtr->arrive(time);
}

// Pre: None
// Post: Showing the status of orders and drivers
void status(Restaurant& arestaurant) {
    arestaurant.status();
}

// Pre: None
// Post: Showing the summary statistics on orders and drivers
void summary(Restaurant& arestaurant) {
    arestaurant.summary();
}

// Pre: None
// Post: Print help.
void print_help()
{
    cout << endl << "Commands:" << endl;
    cout << "  Help : Print help" << endl;
    cout << "  Login DRIVER : Driver logs in" << endl;
    cout << "  Logout DRIVER : Driver logs out" << endl;
    cout << "  Order TIME INFO : Adds new order. Time format: HH:MM" << endl;
    cout << "  Serve TIME : Sends order out for delivery. Time format: HH:MM" << endl;
    cout << "  Depart TIME DRIVER : Driver departs with next order for delivery. Time format: HH:MM" << endl;
    cout << "  Deliver TIME DRIVER TIP : Driver delivers order and receives tip. Time format: HH:MM" << endl;
    cout << "  Arrive TIME DRIVER : Driver returns. Time format: HH:MM" << endl;
    cout << "  Status : Status of orders and drivers" << endl;
    cout << "  Summary : Statistics of all drivers and orders" << endl;
    cout << "  Quit : Terminates the program" << endl;
    cout << endl;
}

