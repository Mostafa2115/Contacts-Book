#ifndef CONTACTSBOOK
#define CONTACTSBOOK
#include"Address.h"
#include"Person.h"
#include"Array.h"
#include<string>
template<class T>
class contactsBook {
protected:
	Array <T>* array;
public:
	contactsBook(Array<T>* arr) :array(arr) {}
	~contactsBook() {
		delete array;
	}
	void AddContact(const T& p) {
		array->Append(p);
	}
	void search_Last(std::string last) {
		array->searchByLast(last);
	}
	void search_Classi(std::string classi) {
		array->searchByClass(classi);
	}
	void printAllContacts() {
		array->printAll();
	}
	void printAllFav() {
		array->printFav();
	}
	void printInFile(std::ofstream& outfile) {
		array->displayfile(outfile);
	}
	void printFromFile(const std::string& filename) {
		array->displayFromFile(filename);
	}
	void DeleteContact(size_t index) {
		array->Delete(index);
	}
	void updateContact(const T& p, size_t index) {
		array->Update(p, index);
	}
	void ReverseContacts() {
		array->Reverse();
	}
};
#endif
