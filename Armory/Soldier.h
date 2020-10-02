#pragma once
#include <iostream>
#include "Armory.h"

namespace justin {

	class soldier {
		char* name;
		int age;
		char* desc;
		Armory* firearm;
	public:
		soldier();
		soldier(const char* soldname, int solage, const char* descr, Armory& arm);
		//~soldier();
		void setsol(std::istream& is);
		void setname(std::istream& is);
		void setage(std::istream& is);
		void setdesc(std::istream& is);
		void setarm(Armory&arm);
		char* getsolname();
		int getage();
		char* getdesc();
		void weaponinspection();
		char* getsolpri();
		char* getsolsec();
		int getsolmag();
		bool isempty();
		void setempty();

		void display(std::ostream& os) const;

		soldier& copy(soldier& a);
		operator bool()const;
		soldier& operator +=(int a);
		soldier& operator++(); //prefix
		soldier operator++(int); //postfix
	};

	bool sameSoldier(soldier a, soldier b);
	
	std::ostream& operator<<(std::ostream& os, const soldier& sol);
	std::istream& operator>>(std::istream& is, soldier& sol);
}