/* Students.cpp */
#pragma once
#include <string>
#include <iostream>

class Students
{
private:
	std::string name;
	std::string group;
	std::string NRB;
	int         marks[4];
	double      ab;
public:
	void set_name(std::string name1);
	std::string get_name();
	void set_group(std::string group1);
	std::string get_group();
	// NRB= NumberofRecordBook
	void set_NumberofRecordBook(std::string NRB1);
	std::string get_NumberofRecordBook();
	void set_marks(int markspr[4]);
	int get_marks_1();
	int get_marks_2();
	int get_marks_3();
	int get_marks_4();
	void set_average_ball(double ab1);
	double get_average_ball();
	~Students();
};