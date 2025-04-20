#pragma once

class hdrSword {
public:
	void hdrEquip();
	void hdrUnequip();
	int hdrGetDamage() { return Damage; };

public: //had to switch from private: (for incomplete types)
	int Damage{ 10 };
};