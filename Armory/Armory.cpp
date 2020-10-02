#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "Armory.h"

using namespace std;

namespace justin {
	
	Armory::Armory() {
		setempty();
	}

	Armory::Armory(const char* pri, const char* sec, int mag) {
		setprimary(pri,20);
		setsecondary(sec,20);
		setmagazine(mag);
	}

	/*
	Armory::~Armory() {
		delete primary, secondary;
	}*/

	void Armory::setprimary(const char* pri,int a) {
		primary = new char[a];
		strcpy(primary, pri);
	}

	void Armory::setsecondary(const char* sec,int a) {
		secondary = new char[a];
		strcpy(secondary, sec);
	}

	void Armory::setmagazine(int mag) {
		magazine = mag;
	}

	char* Armory::getpri() {
		return primary;
	}

	char* Armory::getsec() {
		return secondary;
	}

	int Armory::getmag() {
		return magazine;
	}

	bool Armory::isempty() {
		return(primary[0] == '\0' || secondary[0] == '\0' || magazine == 0);
	}
	
	void Armory::setempty() {
		primary = nullptr;
		secondary = nullptr;
		magazine = 0;
	}

	void Armory::display(std::ostream& os)const {
		os << "----------------------------" << endl;
		os << "Weapons list" << endl;
		os << "PrimaryWeapon   : " << primary << endl;
		os << "SecondaryWeapon : " << secondary << endl;
		os << "Magazine        : " << magazine << endl;
		os << "----------------------------" << endl;
	}

	Armory& Armory::copyarmory(Armory& ar) {
		primary = new char[strlen(ar.primary)];
		secondary = new char[strlen(ar.secondary)];
		magazine = ar.magazine;
		strcpy(primary, ar.primary);
		strcpy(secondary, ar.secondary);
		return *this;
	}

	ostream& operator<<(std::ostream& os, const Armory& Arm) {
		Arm.display(os);
		return os;
	}
};

