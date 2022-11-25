
#include "Zombie.hpp"

void	randomChump( std::string name ) {

	Zombie* zombie;

	zombie = newZombie( name );

	zombie->announce();

	delete zombie;
}
