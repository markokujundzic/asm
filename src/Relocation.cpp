#include "Relocation.h"
#include "Data.h"
#include "Assembler.h"

Relocation::Relocation(const uint16_t& offset, const uint16_t& value, const string& type, const string& section) : offset(offset), value(value), type(type), section(section), location_counter(0)
{

}

void Relocation::delete_relocations()
{
	for (list<Data*>::iterator it = Assembler::data.begin(); it != Assembler::data.end(); it++)
	{
		for (list<Relocation*>::iterator ite = (*it)->relocations.begin(); ite != (*it)->relocations.end(); ite++)
		{
			delete (*ite);
		}

		(*it)->relocations.clear();
	}
}