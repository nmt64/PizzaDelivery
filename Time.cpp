//
//  Time.cpp
//  PizzaDelivery
//
//  Created by Nguyen Tam on 4/23/18.
//  Copyright © 2018 Nguyen Tam. All rights reserved.
//

#include <iostream>
#include "Time.h"
#include <math.h>

using namespace std;
/* Conver char to number
 @Pre: a char must be a character from '0' to '9'
 @Post: convert achar into a number*/
int Time::CharToNumber(char achar) const throw (logic_error) {
}

/* Constructor
 @pre: none
 @post:Creates a time with default values for data members.  */
Time:: Time(string strTime) throw (logic_error){
    
}

/* Constructor
 @pre: 0 <= hour <= 23 and 0 <= min <= 59.
 @post: Creates a time with the given hour and minute. */
Time:: Time(int hour, int min) throw (logic_error){
    
}

/*Copy constructor:
 @pre: none
 @post: Initializes the Time to be equivalent to the other Time object parameters.*/
Time::Time(const Time& other): hour(other.hour), min(other.min){
    
}


/* Assignment operator:
 @pre: none
 @post: Sets the Time to be equivalent to the other and returns a reference to the modified Time*/
Time& Time::operator=(const Time& other)
{
    
}

/* Calculate time
 @pre: none
 @post: Returns the difference in minutes between t1 and t2. Assumes t2 is between 00:00 and 23:59 hours after t1. */
int Time::elapsedMin(const Time t1, const Time t2){
    
}

/* Show time
 @pre: none
 @post:Returns a string containing the hour and minute (e.g., “13:01”). */
string Time::toString() const{
    
}

