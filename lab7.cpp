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
			for (int k = 0; k < 4; k++) {
				std::cin >> prom1[k];
			}
			student[i].set_marks(prom1);
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
		<< "Mark 3" << std::setw(7) << "Mark 4" << "\n";
	for (int k = 0; k < i; k++) {
		std::cout <<std::setw(16) << student[k].get_name()<<std::setw(8) << student[k].get_group() << std::setw(9) << student[k].get_NumberofRecordBook() 
			<< std::setw(7)<< student[k].get_marks_1() << std::setw(7) << student[k].get_marks_2() << std::setw(7) 
			<< student[k].get_marks_3() << std::setw(7) << student[k].get_marks_4()<<"\n";
	}
	std::cout << "\n";
	std::cout<<"KEY = Grade point average: \n";
	std::cout << std::setw(16) << "Name      " << std::setw(8) << "  Group" << std::setw(9) << "R. Book"
		<< std::setw(7) << "Mark 1" << std::setw(7) << "Mark 2" << std::setw(7)
		<< "Mark 3" << std::setw(7) << "Mark 4" << "\n";
	int sum;
	double* gpa = new double[i];
	for (int k = 0; k < i; k++) {
		sum = student[k].get_marks_1();
		sum += student[k].get_marks_2();
		sum += student[k].get_marks_3();
		sum += student[k].get_marks_4();
		gpa[k] = sum / 4.0;
	}
	/*for (int k = 0; k < i; k++) {
		std::cout << "k=" <<k<<" "<< gpa[k] << " ";
		std::cout << "\n";
	}
	std::cout << "\n";*/
	double min;
	/*for (int j = 0; j < i; j++) {
		min = 1000000.0;
		if (gpa[j] < min) {
			min = gpa[j];
		}
	}*/
	int* pam= new int [i];
	int ch;
	int pamvr11;
	int kk = 0;
	student1 = new Students[i];
	for (int j = 0; j < i; j++) {
		min = 1000000.0;
		ch = 0;
		delete[] pam;
		pam = new int[i];
		for(int jj=0;jj<i;jj++){
			if (gpa[jj] == min) {
				//std::cout<<"ch=" << ch << " "<<"min="<<min<<" " <<"j="<< j << " " <<"jj="<< jj << "\n";
				pam[ch] = jj;
				ch++;
			}
			else if (gpa[jj] < min) {
				min = gpa[jj];
				delete[] pam;
				pam = new int[i];
				ch = 0;
				pam[ch] = jj;
				ch++;
			}
		}
		if (ch == 0) {
			student1[kk] = student[pamvr11];
			kk += 1;
		}
		else {
			for (int jjj = 0; jjj < ch; jjj++)
			{
				pamvr11 = pam[jjj];
				/*std::cout << std::setw(16) << student[pamvr11].get_name() << std::setw(8) << student[pamvr11].get_group() << std::setw(9) << student[pamvr11].get_NumberofRecordBook()
					<< std::setw(7) << student[pamvr11].get_marks_1() << std::setw(7) << student[pamvr11].get_marks_2() << std::setw(7)
					<< student[pamvr11].get_marks_3() << std::setw(7) << student[pamvr11].get_marks_4() << "\n";*/
				gpa[pamvr11] = 1000001.0;
				student1[kk] = student[pamvr11];
				kk += 1;
			}
		}
	}
	delete[] student;
	for (int k = 0; k < i; k++) {
		std::cout << std::setw(16) << student1[k].get_name() << std::setw(8) << student1[k].get_group() << std::setw(9) 
			<< student1[k].get_NumberofRecordBook()<< std::setw(7) << student1[k].get_marks_1() << std::setw(7) << student1[k].get_marks_2()
			<< std::setw(7)<< student1[k].get_marks_3() << std::setw(7) << student1[k].get_marks_4() << "\n";
	}
}

