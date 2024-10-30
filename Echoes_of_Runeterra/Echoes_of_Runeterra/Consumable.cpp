#include "Consumable.h"
#include <fstream>

Consumable::Consumable() : m_name("Default Consumable Name"), m_hp(0), m_defense(0), m_speed(0)
{
}

Consumable::~Consumable()
{
}

void cons_read(std::string _filePath, std::vector<Consumable> _vector)
{
	std::ifstream file(_filePath);

	if (file)
	{
		int c(0);
		std::string tmpName;
		bool readName(true);
		while (c = file.get())
		{
			if (c == '\n')
			{

			}
			if (c == ',')
			{
				if (readName)
				{
					
				}
			}
			else if (readName)
			{
				tmpName += c;
			}
		}
	}
	else
		std::cerr << "Error while opening a file" << std::endl;
}
