#pragma once
#include "hdrSword.h"

class hdrCharacter { //:public Actor {
public:
	void hdrEquip(hdrSword* Weapon);
	void Attack();

	virtual void hdrFunctionA();

	void hdrGreet();

private:
	hdrSword* mWeapon;

	void hdrFunctionB(); //override;
};
