#pragma once

namespace justin {
	class Armory {
		char* primary;
		char* secondary;
		int magazine;

	public:
		Armory();
		Armory(const char* pri, const char* sec, int mag);
		//~Armory();

		//Functions
		void setprimary(const char* pri,int a);
		void setsecondary(const char* sec, int a);
		void setmagazine(int mag);

		char* getpri();
		char* getsec();
		int getmag();
		bool isempty();
		void setempty();
		void display(std::ostream& os)const;
		Armory& copyarmory(Armory& ar);
	};
	std::ostream& operator<<(std::ostream& os, const Armory& Arm);
}