/* lab7.cpp */
#include "pch.h"
#include "Students.h"
#include "Students.cpp"
#include <iostream>
#include <string>
#include <iomanip>

int main()
{
	std::cout << "Volkov Grigory";
	std::cout << "\n";
	std::cout << "lab7";
	std::cout << "\n";
	std::cout << "\n";
	int n = 2;// 1 - random value 
	Students* student = new Students[n]; // n=1 - random value
	std::string flag, prom;
	int i = 0;
	int* prom1 = new int[4];
	Students* student1 = new Students[n];
	delete[] student1;
	int promto;
	while (true) {
		std::cout << "Do you want to add new student? (y/n) \n";
		std::cin >> flag;
		if (flag == "y") {
			if (i >= n) {
				//std::cout << "ai" << "\n";
				student1 = new Students[n];
				for (int kkk = 0; kkk < n; kkk++) {
					student1[kkk] = student[kkk];
				}
				delete[] student;
				n *= 2;
				student = new Students[n];
				for (int kkk = 0; kkk < i; kkk++) {
					student[kkk] = student1[kkk];
				}
				delete[] student1;
			}
			std::cout << "Enter name: \n";
			std::cin.ignore();
			getline(std::cin, prom);
			student[i].set_name(prom);
			std::cout << "Enter number of group: \n";
			std::cin >> prom;
			student[i].set_group(prom);
			std::cout << "Enter number of record book: \n";
			std::cin >> prom;
			student[i].set_NumberofRecordBook(prom);
			std::cout << "Enter four marks: \n";
			promto = 0;
			for (int k = 0; k < 4; k++) {
				std::cin >> prom1[k];
				promto += prom1[k];
			}
			student[i].set_marks(prom1);
			student[i].set_average_ball(promto / 4.0);
			std::cout << "\n";
			i++;
		}
		else if (flag == "n") {
			std::cout << "\n";
			break;
		}
		else {
			std::cout << "ERROR \n";
		}
	}
	std::cout << "ALL: \n";
	std::cout << std::setw(16) <<"Name      "<< std::setw(8) <<"  Group"<< std::setw(9) <<"R. Book"
		<< std::setw(7) << "Mark 1"<< std::setw(7) << "Mark 2" << std::setw(7)
		<< "Mark 3" << std::setw(7) << "Mark 4" << std::setw(8) << "a. ball" << "\n";
	for (int k = 0; k < i; k++) {
		std::cout <<std::setw(16) << student[k].get_name()<<std::setw(8) << student[k].get_group() << std::setw(9) << student[k].get_NumberofRecordBook() 
			<< std::setw(7)<< student[k].get_marks_1() << std::setw(7) << student[k].get_marks_2() << std::setw(7) 
			<< student[k].get_marks_3() << std::setw(7) << student[k].get_marks_4()<< std::setw(8) << student[k].get_average_ball() <<"\n";
	}
	std::cout << "\n";
	std::cout<<"KEY = average ball: \n";
	std::cout << std::setw(16) << "Name      " << std::setw(8) << "  Group" << std::setw(9) << "R. Book"
		<< std::setw(7) << "Mark 1" << std::setw(7) << "Mark 2" << std::setw(7)
		<< "Mark 3" << std::setw(7) << "Mark 4" << std::setw(8) << "a. ball" << "\n";
	Students pampam;
	double pam1, pam2;
	for (int k = 0; k < i-1; k++) {
		for (int kk = k + 1; kk < i; kk++) {
			pam1 = student[k].get_average_ball();
			pam2 = student[kk].get_average_ball();
			if (pam1 > pam2) {
				pampam = student[kk];
				student[kk]= student[k];
				student[k] = pampam;
			}
		}
	}
	for (int k = 0; k < i; k++) {
		std::cout << std::setw(16) << student[k].get_name() << std::setw(8) << student[k].get_group() << std::setw(9) << student[k].get_NumberofRecordBook()
			<< std::setw(7) << student[k].get_marks_1() << std::setw(7) << student[k].get_marks_2() << std::setw(7)
			<< student[k].get_marks_3() << std::setw(7) << student[k].get_marks_4() << std::setw(8) << student[k].get_average_ball() << "\n";
	}
	
}

