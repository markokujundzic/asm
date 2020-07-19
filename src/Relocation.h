#ifndef _relocation_h_
#define _relocation_h_

#include <string>

using namespace std;

class Relocation
{
public:
	Relocation(const uint16_t& offset, const uint16_t& value, const string& type, const string& section);

	static void delete_relocations();

	uint16_t offset;
	uint16_t value;

	string type;
	string section;

	uint16_t location_counter;

	// LOCAL + PC_RELOCATION        -> SYMBOL VALUE - NEXT INSTRUCTION OFFSET
	// LOCAL + ABSOLUTE RELOCATION  -> SYMBOL VALUE

	// GLOBAL + PC_RELOCATION       -> - NEXT INSTRUCTION OFFSET
	// GLOBAL + ABSOLUTE RELOCATION -> 0
};

#endif