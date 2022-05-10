#pragma once
#pragma once
/* ScrollingText.h
*  Bryson McBreen
*  4-12-22
*  Purpose:
*		Take in a string and output it into the console at a variable speed
*/

#include "Includes.h"

#define SPEED 200

void sleep(int t) {
	// CREDIT: Mark Wheeler, telling me how to use this_thread::sleep_for() 
	this_thread::sleep_for(chrono::milliseconds(t));
}

void scroll(string s) {
	int length;
	length = s.length();

	vector<char> v(s.begin(), s.end());


	for (int i = 0; i < length; i++) {
		cout << v[i];
		sleep(SPEED);
	}
}

void varScroll(string s, int t) {
	int length;
	length = s.length();

	vector<char> v(s.begin(), s.end());


	for (int i = 0; i < length; i++) {
		cout << v[i];
		sleep(t);
	}
}


// Created by Bryson McBreen, use it, modify it, IDC