#include "windowManager.h"
#include "Character.h"

int main()
{
	Character c;

	int i(0);
	do
	{
		c.update();
		c.giveXp(10);

		std::cout << c.getLevel() << std::endl;
	} while (i++ < 1 || c.getLevel() > 20);

	return EXIT_SUCCESS;
}