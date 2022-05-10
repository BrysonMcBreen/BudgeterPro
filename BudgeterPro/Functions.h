#pragma once
/* Functions.h
*  Bryson McBreen
*  5-1-22
*  Purpose:
*		Store functions that do not require their own files
*/

#include "Includes.h"


string checkColorMode(int i, string c) {
	if (i == 0) {
		c = "Dark Mode ";
	}
	else {
		c = "Light Mode";
	}
	return c;
}

int changeColorMode(int i, string color) {
	if (i == 0) {
		system("color F0");
		i++;
	}
	else {
		system("color 0F");
		i--;
	}
	return i;
}

int takeLengthInt(int i, int l) {
	if (i >= 0 && i <= 9) {
		l = 1;
	}
	else if (i >= 10 && i <= 99) {
		l = 2;
	}
	else if (i >= 100 && i <= 999) {
		l = 3;
	}
	else if (i >= 1000 && i <= 9999) {
		l = 4;
	}
	else if (i >= 10000 && 99999) {
		l = 5;
	}
	else {
		l = 6;
	}
	return l;
}