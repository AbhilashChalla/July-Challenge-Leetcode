/*
Problem Statement:
----------------------------------------------------------
Given two numbers, hour and minutes. Return the smaller angle (in degrees) formed between the hour and the minute hand.
Example 1:

Input: hour = 12, minutes = 30
Output: 165

Example 2:

Input: hour = 3, minutes = 30
Output: 75
----------------------------------------------------------
*/
class Solution {
	//Approach: 60 mins = 360 degrees. 1 min = 6 degrees. This sorts out the angle calculation of minutes hand. 
	//For hour angle calculation: For 60mins, hour hand moves 5 places. For 1 min, hour hand moves 5/60 places. Using the above observation along with current point, 
	// hour angle can be calculated as (minutes/2)+hour*30. Need to check for anti-clockwise direction also as we need to return minimum angle.
	//Time Complexity: O(1)
	//Space Complexity: O(1)
public:
    double angleClock(int hour, int minutes) {
        hour%=12;
        double mins_angle_clockwise=(double)minutes*6;
        double hours_angle_clockwise=((double)minutes/2)+((double)hour*30);
        double mins_angle_anticlockwise=360-mins_angle_clockwise;
        double hours_angle_anticlockwise=360-hours_angle_clockwise;
        return min(abs(mins_angle_clockwise-hours_angle_clockwise),hours_angle_clockwise+mins_angle_anticlockwise);
    }
};
