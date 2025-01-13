#ifndef ADDRESS_H
#define ADDRESS_H
#include <iostream>
#include <string>
#include <sstream>
#include<iomanip>
#include<fstream>
template <typename T>
class Address
{
private:
    T streetNum;
    T state;
    T city;
    T streetName;
public:
    Address() : streetNum(""), streetName(""), state(""), city("") {}
    Address(T num, T sName, T ct, T sta)
        : streetNum(num), streetName(sName), state(sta), city(ct) {}
    Address(const Address& adder) {
        streetNum = adder.streetNum;
        streetName = adder.streetName;
        city = adder.city;
        state = adder.state;
    }
    ~Address() {}
    T getStreetName() const {
        return streetName;
    }
    T getState() const {
        return state;
    }
    T getCity() const {
        return city;
    }
    T getStreetNum() const {
        return streetNum;
    }
    std::string toString() const {
        std::ostringstream oss;
        oss << streetNum << " " << streetName << "," << city << "," << state;
        return oss.str();
    }
    void printdataAfile(std::ofstream& outfile) {
        if (!outfile.is_open()) {
            throw std::runtime_error("File is not open for writing.");
        }
        outfile << std::setw(40) << std::left << toString();
    }
};
#endif // !ADDRESS_H
