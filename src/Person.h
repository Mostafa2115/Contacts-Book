#ifndef PERSON_H
#define PERSON_H
#include<algorithm>
#include"Address.h"
#include<iostream>
#include<fstream>
#include<iomanip>
template<class T>
class Person {
protected:
	T fName;
	T lName;
	T classification;
	size_t favorite;
	size_t numOfphone;
	size_t emailNum;
	T* emails;
	T* mobiles;
	Address<T> address;
public:
	Person() :fName(""), lName(""), classification(""), favorite(0), numOfphone(1), emailNum(1) {}
	Person(T fn, T ln, size_t fav, size_t nPhone, size_t nEmail, T classi, Address<T> add, T* mob, T* email)
		: fName(fn), lName(ln), favorite(fav), numOfphone(nPhone), emailNum(nEmail), classification(classi), address(add) {
		mobiles = new T[numOfphone];
		for (size_t i = 0; i < numOfphone; i++) {
			mobiles[i] = mob[i];
		}
		emails = new T[emailNum];
		for (size_t i = 0; i < emailNum; i++) {
			emails[i] = email[i];
		}
	}
	~Person() {}
	Person(const Person& per)
		: fName(per.fName), lName(per.lName), classification(per.classification),
		favorite(per.favorite), numOfphone(per.numOfphone), emailNum(per.emailNum),
		address(per.address) {
		mobiles = new T[numOfphone];
		for (size_t i = 0; i < numOfphone; i++) {
			mobiles[i] = per.mobiles[i];
		}
		emails = new T[emailNum];
		for (size_t i = 0; i < emailNum; i++) {
			emails[i] = per.emails[i];
		}
	}
	T getfName() const {
		return this->fName;
	}
	T getlName()const {
		return this->lName;
	}
	void printName() const {
		std::cout << fName << " " << lName;
	}
	size_t isFav() const {
		return this->favorite;
	}
	void printMobiles() const {
		for (size_t i = 0; i < numOfphone; i++) {
			std::cout << mobiles[i] << (i < numOfphone - 1 ? ", " : "");
		}
		std::cout << std::endl;
	}
	void printEmails() const {
		for (size_t i = 0; i < emailNum; i++) {
			std::cout << "Email #" << i + 1 << ": " << emails[i] << std::endl;
		}
	}
	T getClassi() const {
		return this->classification;
	}
	void printTablehead() {
		std::cout << std::setw(10) << std::left << "Id" << std::setw(15) << std::left << "FName"
			<< std::setw(15) << std::left << "LName" << std::setw(15) << std::left << "Classi"
			<< std::setw(10) << std::left << "Fav" << std::setw(40) << std::left << "Address"
			<< std::setw(40) << std::left << "Phonenum" << std::endl;
		for (size_t i = 0; i < 156; i++) {
			std::cout << "-";
		}
		std::cout << std::endl;
	}
	void printInfo() {
		std::cout << std::setw(15) << std::left << fName << std::setw(15) << std::left << lName
			<< std::setw(15) << std::left << classification << std::setw(10) << std::left << favorite
			<< std::setw(40) << std::left << address.toString() << std::setw(40) << std::left;
		printMobiles();
		for (size_t i = 0; i < 156; i++) {
			std::cout << "-";
		}
		std::cout << std::endl;
	}
	void printdataPfile(std::ofstream& outfile) {
		if (!outfile.is_open()) {
			throw std::runtime_error("File is not open for writing.");
		}
		outfile << std::setw(15) << std::left << fName
			<< std::setw(15) << std::left << lName
			<< std::setw(15) << std::left << classification
			<< std::setw(10) << std::left << favorite;
		address.printdataAfile(outfile);
		outfile << std::setw(40) << std::left;
		for (size_t i = 0; i < numOfphone; i++) {
			outfile << mobiles[i];
			if (i < numOfphone - 1) {
				outfile << ",";
			}
		}
	}
};
#endif
