#include <iostream>
#include "Soldier.h"


using namespace std;

ostream& line(int len, char ch) {
	for (int i = 0; i < len; i++, cout << ch);
	return cout;
}

using namespace justin;

int main() {

	Armory loadout1("HK416", "M9", 3), 
		   loadout2("M4A1", "M1911", 2), 
		   loadout3("FN SCAR", "FN57", 4);
	Armory* loadout4 = new Armory("PEWPEW","pewpew",95);

	soldier Justin("Justin", 24, "Formal ROKMC", loadout1),
		Gideon("Gideon", 22, "SAS", loadout2),
		Alex("Alex", 26, "CIA", loadout3);

	soldier* Carl = new soldier("Carl", 21, "Carl",loadout2);
	Carl->display(cout);
	
	std::cout << "==============[Testing Copy]======================" << std::endl;
	line(51, '-');
	Alex.copy(Justin);
	Alex.display(cout);
	
	std::cout << "==============[Testing Operator +=]===============" << std::endl;
	line(51, '-');
	Justin += 3;
	Justin.display(cout);
	
	std::cout << "==============[Testing Operator ++(prefix)]=======" << std::endl;
	line(51, '-');
	++Justin;
	Justin.display(cout);
	
	std::cout << "==============[Testing Operator ++(postfix)]======" << std::endl;
	line(51, '-');
	Justin++;
	Justin.display(cout);
	
	
	std::cout << "==============[Testing Helper Function]===========" << std::endl;
	if (sameSoldier(Justin,Alex)==true){
		cout << "SAME!!!" << endl;
	}
	else { cout << "Not the same!" << endl; 
	}
	
	std::cout << "==============[Testing Pointer&Nested Class]=======" << std::endl << std::endl;
	std::cout << "=====Normal class=====" << endl;
	Justin.weaponinspection();
	std::cout << "=====Pointer class=====" << endl;
	Carl->weaponinspection();
	std::cout << "==============[Testing whatever the fuck I want]=======" << std::endl;
	
	delete Carl;
	delete loadout4;
	
	cout << Justin << endl;
	cin >> Justin;
	cout << Justin << endl;

}


