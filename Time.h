//
//  Time.hpp
//  PizzaDelivery
//
//  Created by Nguyen Tam on 4/23/18.
//  Copyright © 2018 Nguyen Tam. All rights reserved.
//

#ifndef Time_hpp
#define Time_hpp

#include <stdio.h>
#include <string>
#include "Time.h"
#include "Order.h"

using namespace std;
class Time {
    
    //The Time class represents a time of day in 24-hour time with hours and minutes.
    
public:
    
    /* Constructor
     @pre: none
     @post:Creates a time with default values for data members.  */
    Time(string strTime = "00:00") throw (logic_error);
    
    /* Constructor
     @pre: 0 <= hour <= 23 and 0 <= min <= 59.
     @post: Creates a time with the given hour and minute. */
    Time(int hour, int min) throw (logic_error);
    
    /*Copy constructor:
     @pre: none
     @post: Initializes the Time to be equivalent to the other Time object parameters.*/
    Time(const Time& other);
    
    
    /* Assignment operator:
     @pre: none
     @post: Sets the Time to be equivalent to the other and returns a reference to the modified Time*/
    Time& operator=(const Time& other);
    
    /* Calculate time
      @pre: none
      @post: Returns the difference in minutes between t1 and t2. Assumes t2 is between 00:00 and 23:59 hours after t1. */
    static int elapsedMin(Time t1, Time t2);
    
    /* Show time
     @pre: none
     @post:Returns a string containing the hour and minute (e.g., “13:01”). */
    string toString() const;
    
private:
    /*
     @pre: achar must be a character from '0' to '9'
     @post: convert achar into a number*/
    int CharToNumber(char achar) const throw (logic_error);
    
    int hour; // hour in Time
    int min;  // minute in Time
    
};

#endif /* Time_hpp */
