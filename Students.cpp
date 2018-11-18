/* Students.cpp */
#include "Students.h"
#include <string>
#include <iostream>

void Students::set_name(std::string name1) {
	Students::name = name1;
};
std::string Students::get_name() {
	return Students::name;
};
void Students::set_group(std::string group1) {
	Students::group = group1;
};
std::string Students::get_group() {
	return Students::group;
};
// NRB= NumberofRecordBook
void Students::set_NumberofRecordBook(std::string NRB1) {
	Students::NRB = NRB1;
};
std::string Students::get_NumberofRecordBook() {
	return Students::NRB;
};
void Students::set_marks(int markspr[4]) {
	for (int i = 0; i < 4; i++) {
		Students::marks[i] = markspr[i];
	}
};
int Students::get_marks(int index) {
	switch (index) {
	case 1:
		return Students::marks[0];
	case 2:
		return Students::marks[1];
	case 3:
		return Students::marks[2];
	case 4:
		return Students::marks[3];
	}
};
// ab = average ball
void Students::set_average_ball(double ab1) {
	Students::ab = ab1;
};
double Students::get_average_ball() {
	return Students::ab;
};
Students:: ~Students(){};