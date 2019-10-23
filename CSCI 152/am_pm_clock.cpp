#include <iostream>
#include "am_pm_clock.h"

	am_pm_clock::am_pm_clock(){
		am = 1;
		hours = 12;
		minutes = 0;
		seconds = 0;
	}

	/*
	 * Constructor - sets fields to the given argument values
	 */
	am_pm_clock::am_pm_clock(unsigned int hrs, unsigned int mins,
			    unsigned int secs, bool am_val){
			    	hours = hrs;
			    	minutes = mins;
			    	seconds = secs;
			    	am = am_val;
				}

	/*
	 * Copy constructor
	 */
	am_pm_clock::am_pm_clock(const am_pm_clock &clock){
		hours = clock.hours;
		minutes = clock.minutes;
		seconds = clock.seconds;
		am =clock.am;
	}
	/*
	 * Assignment operator
	 */
	am_pm_clock& am_pm_clock::operator=(const am_pm_clock& clock){
		hours = clock.hours;
		minutes = clock.minutes;
		seconds = clock.seconds;
		am = clock.am;
	}


	/*
	 * Toggles the am/pm value for the clock
	 */
	void am_pm_clock::toggle_am_pm() {
		if(am == 0)
			am = 1;
		else{
			am = 0;
		}
	}

	/*
	 * Resets the time to midnight
	 */
	void am_pm_clock::reset() {
		am = 1;
		hours = 12;
		minutes = 0;
		seconds = 0; 
	}

	/*
	 * Advances the time of the clock by one second
	 */
	void am_pm_clock::advance_one_sec(){
		seconds++;

		if(seconds == 60){
			minutes++;
			seconds = 0;
		if(minutes == 60){
			hours++;
			minutes = 0;
			if(hours == 12){
				if(am == 0)
					am = 1;
				else{
					am = 0;
				}
			}
			else{
				hours = hours%12;
			}
		}
	}

	}

	/*
	 * Advances the time of the clock by n seconds
	 */
	void am_pm_clock::advance_n_secs(unsigned int n) {
		for(int i=0; i<n; i++){
			advance_one_sec();
		}
	}
	/*
	 * Getter for hours field
	 */
	unsigned int am_pm_clock::get_hours() const {
	return hours;
	}

	/*
	 * Setter for hours field; throws an invalid_argument exception
	 * if hrs is not a legal hours value
	 */
	void am_pm_clock::set_hours(unsigned int hrs){
		if (hrs > 12 || hrs < 1){
			throw std::invalid_argument("hours are not valid");
		}
		hours = hrs;
	}
	/*
	 * Getter for minutes field
	 */
	unsigned int am_pm_clock::get_minutes() const {
	return minutes;
	}
	/*
	 * Setter for minutes field; throws an invalid_argument exception
	 * if mins is not a legal minutes value
	 */
	void am_pm_clock::set_minutes(unsigned int mins){
		if (mins > 59 || mins < 0){
			throw std::invalid_argument("minutes are not correct");
		}
		minutes = mins;
	}

	/*
	 * Getter for seconds field
	 */
	unsigned int am_pm_clock::get_seconds() const {
	return seconds; 
	}
	/*
	 * Setter for seconds field; throws an invalid_argument exception
	 * if secs is not a legal seconds value
	 */
	void am_pm_clock::set_seconds(unsigned int secs){
		if (secs > 59 || secs < 0){
			throw std::invalid_argument("seconds are not correct");
		}
		seconds = secs;
	}

	/*
	 * Getter for am field
	 */
	bool am_pm_clock::is_am() const{
	return am;
	}

	/*
	 * Setter for am field
	 */
	void am_pm_clock::set_am(bool am_val){
		if (am_val > 1){
			throw std::invalid_argument("am is not correct");
		}
		am = am_val;
	}


	/*
	 * Destructor
	 */
	am_pm_clock::~am_pm_clock() {};
	
