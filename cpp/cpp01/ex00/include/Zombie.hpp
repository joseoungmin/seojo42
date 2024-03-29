#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class	Zombie
{
	private:
		std::string	_name;

	public:
		void	announce(void);
		
		Zombie();
		Zombie(std::string name);
		~Zombie();
};

void	randomChump(std::string name);
Zombie* newZombie(std::string name);

#endif
