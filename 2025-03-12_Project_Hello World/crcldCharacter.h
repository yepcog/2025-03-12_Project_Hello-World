#pragma once
//#include "crcldSword.h"
class crcldSword;

class crcldCharacter {
public:
	//E0833: pointer or reference to incomplete type "..." is not allowed
	//int crcldGetDamage() { return Weapon->Damage; } //always forget return semicolons =_=
	int crcldGetDamage();
	crcldSword* Weapon;
};
