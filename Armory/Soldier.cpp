#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include "Soldier.h"
#include "Armory.h"


namespace justin {
	using namespace std;
	int counter = 1;

	soldier::soldier() {
		setempty();
	}

	soldier::soldier(const char* soldname, int solage, const char* descr, Armory& arm) {
		//Dynamic memory allocating 
		name = new char[strlen(soldname)];
		desc = new char[strlen(descr)];

		//name and description setting 
		strcpy(name, soldname);
		age = solage;
		strcpy(desc, descr);

		setarm(arm);
	}
	//Soldier setting 
	void soldier::setsol(istream& is){
		setname(is);
		setage(is);
		setdesc(is);
		counter--;
	}
	/*
	soldier::~soldier() {
		//cout << "Good bye " << name << " !" << endl;
		delete name,desc;
	*/

	//Soldier info setting 
	void soldier::setname(std::istream& is) {
		char nam[25] = "\0";
		cout << "-------------------------------" << endl;
		cout << "Enter name of the soldier : ";
		is >> nam;

		while (nam[0] == '\0') {
			cout << "Wrong entry, try it again" << endl;
			is >> nam;
		}

		strcpy(name, nam);
		cout << "Name confirmed : " << name << endl;
	}

	void soldier::setage(std::istream& is) {
		cout << "Enter the age of the soldier : ";
		is >> age;

		while (!operator bool()){
			cout <<"Age should be at least 20 to enlist" << endl;
			is >> age;
		} 
		
	}
	void soldier::setdesc(std::istream& is) {
		char des[100] = "\0";
		cout << "-------------------------------" << endl;
		cout << "Description? : ";
		is >> des;

		while (des[0] == '\0') {
			cout << "Wrong entry, try it again" << endl;
			is >> des;
		}

		strcpy(desc, des);
		cout << "Description confirmed : " <<"["<<desc<<"]"<< endl;
	}

	void soldier::setarm(Armory& arm) {
		firearm = new Armory;
		firearm->setprimary(arm.getpri(),20);
		firearm->setsecondary(arm.getsec(),20);
		firearm->setmagazine(arm.getmag());
	};

	char* soldier::getsolname() {
		return name;
	}

	int soldier::getage() {
		return age;
	}

	char* soldier::getdesc() {
		return desc;
	}

	//Get soldier Firearm

	void soldier::weaponinspection(){
		cout << "==========================================" << endl;
		cout << "==============WEAPON INSPECTION===========" << endl;
		cout << "==========================================" << endl;
		cout << "Gear up "<<getsolname()<<" !, Time to check your loadout" << endl;
		getsolpri();
		getsolsec();
		getsolmag();
		cout << "==========================================" << endl;
	}
	char* soldier::getsolpri() {
		cout << getsolname() << "'s primary weapon is " << firearm->getpri() << endl;
		return firearm->getpri();
	}
	char* soldier::getsolsec() {
		cout << getsolname() << "'s secondary weapon is " << firearm->getsec() << endl;
		return firearm->getsec();
	}
	int soldier::getsolmag() {
		cout << getsolname()<< " has " << firearm->getmag()<<" magazines" << endl;
		return firearm->getmag();
	}

	bool soldier::isempty() {
		return(name[0] == '\0' || age == 0 || desc == 0);
	}

	void soldier::setempty() {
		name[0] = '\0';
		age = 0;
		desc = 0;
	}

	void soldier::display(std::ostream& os) const{
		os << "----------------------------" << endl;
		os << "Soldier Profile / no : " <<counter  <<"    |" <<endl;
		os << "----------------------------" << endl;
		os << "Soldier name : " << name << endl;
		os << "Age          : " << age << endl;
		os << "Description  : " << desc << endl;
		os << "----------------------------" << endl;
		os << "Firearm                     |" << endl;
		firearm->display(os);
		os << endl<<endl;
		counter++;
	}

	soldier& soldier::copy(soldier& a) {
		name = new char[strlen(a.name)+1];
		age = a.age;
		desc = new char[strlen(a.desc)+1];
		strcpy(name, a.name);
		strcpy(desc, a.desc);
		firearm->setprimary(a.firearm->getpri(), 20);
		firearm->setsecondary(a.firearm->getsec(), 20);
		firearm->setmagazine(a.firearm->getmag());
		return*this;
	}
	
	soldier::operator bool()const {
			return(age > 20);
	}

	soldier &soldier::operator+=(int a){
		age += a;
		return *this;
	}
	soldier& soldier::operator++() {
		age += 1;
		return *this;
	}
	
	soldier soldier::operator ++(int) {
		soldier temp = *this;
		++(*this);
		return temp;
	}

	bool sameSoldier(soldier a, soldier b) {

		if (strcmp(a.getdesc(), b.getdesc())==0) {
			return true;
		}

		else {
			return false;
		}
	}
	
	ostream& operator<<(ostream& os, const soldier& sol) {
		sol.display(os);
		return os;
	}

	istream& operator>>(istream& is, soldier& sol) {
		sol.setsol(is);
		cout << endl << endl;
		return is;
	}	
}
