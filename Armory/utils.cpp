#include "utils.h"
#include "Soldier.h"
#include "Armory.h"

namespace justin {

	void display(soldier soldier) {
		cout << "Soldier name : " << soldier.getsolname()<< endl;
		cout << "Age          : " << soldier.getage() << endl;
		cout << "Description  : " << soldier.getdesc() << endl;
		cout << "----------Firearm----------" << endl;
		//cout << "PrimaryWeapon : " << soldier.firearm.getpri()<<endl;

			char* primary;
		int prilen;
		char* secondary;
	}


}

char* getpri();
char* getsec();
int getmag();