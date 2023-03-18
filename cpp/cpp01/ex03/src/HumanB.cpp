#include "HumanB.hpp"

HumanB::HumanB(std::string name)
: _name(name), _weapon(NULL) {}

void	HumanB::setWeapon(Weapon &weapon) {
	_weapon = &weapon;
}

void	HumanB::attack() {
	std::cout << _name << " attacks with their " << _weapon->getType() << "\n";
}
HumanB::~HumanB(){
	std::cout << _name << " destroyed\n";
}