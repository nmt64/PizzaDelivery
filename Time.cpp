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


/* Conver char to number
 @Pre: a char must be a character from '0' to '9'
 @Post: convert achar into a number*/
int Time::CharToNumber(char achar) const throw (logic_error)
{
    int num = achar - '0';
    if (num < 0 || num > 9) // Make sure achar is a character between '0' and '9'
        throw logic_error("Time must be in range 00:00 to 23:59.");
        return num;
}

/* Constructor
 @pre: none
 @post:Creates a time with default values for data members.  */
Time:: Time(string strTime) throw (logic_error)
{
    if (strTime.length() != 5)
        throw logic_error("Input must be in format HH:MM, ex: 09:52.");
    else if (strTime[2] != ':')
        throw logic_error("Input must be in format HH:MM ex: 09:53.");
    
    int chour = 10*CharToNumber(strTime[0]) + CharToNumber(strTime[1]); // hour in integer when convert
                                                                        // from string
    int cmin = 10*CharToNumber(strTime[3]) + CharToNumber(strTime[4]);  // minute in integer when
                                                                        // convert from string
    if (0 > chour || 23 < chour || 0 > cmin || 59 < cmin)
        throw logic_error("Time must be in range 00:00 to 23:59.");
    else
    {
        hour = chour;
        min = cmin;
    }
}
    
/* Constructor
 @pre: 0 <= hour <= 23 and 0 <= min <= 59.
 @post: Creates a time with the given hour and minute. */
Time::Time(int hour, int min) throw (logic_error)
{
    if(hour <0 || hour > 23 || min < 0 || min > 59 )
        throw logic_error("Invalid time given");
    else {
        this->hour = hour;
        this->min = min;
    }
   
}

/*Copy constructor:
 @pre: none
 @post: Initializes the Time to be equivalent to the other Time object parameters.*/
Time::Time(const Time& other): hour(other.hour), min(other.min) {
}


/* Assignment operator:
 @pre: none
 @post: Sets the Time to be equivalent to the other and returns a reference to the modified Time*/
Time& Time::operator=(const Time& other)
{
    if (this != &other)
    {
        hour = other.hour;
        min = other.min;
    }
    return *this;
}

/* Calculate time
 @pre: none
 @post: Returns the difference in minutes between t1 and t2. Assumes t2 is between 00:00 and 23:59 hours after t1. */
int Time::elapsedMin(Time t1, Time t2)
{
    int elapsedTime = 60 * (t2.hour - t1.hour) + (t2.min - t1.min);
    return elapsedTime;
}

/* Show time
 @pre: none
 @post:Returns a string containing the hour and minute (e.g., “13:01”). */
string Time::toString() const
{
    string stringHour = to_string(hour), stringMin = to_string(min), stringTime;
    
    // Convert Time into right format:
    if(hour < 10)
        stringHour = "0" + stringHour;
    if(min < 10)
        stringMin = "0" + stringMin;
    stringTime = stringHour + ":" + stringMin;
    
    return stringTime;
}

