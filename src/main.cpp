#include "Assembler.h"
#include "Error.h"
#include "Lexer.h"

#include <iostream>
#include <regex>

using namespace std;

int main(int argc, const char *argv[])
{
	static constexpr int _min_num_of_args =      4;
	static constexpr int _correct_execution =    1;
	static constexpr int _incorrect_execution = -1;

	static const regex command_regex("-o");
	static const regex input_file_regex(".*\\.s$");
	static const regex output_file_regex(".*\\.o$"); 

	try
	{
		if (argc < _min_num_of_args)
		{
			throw Error("Error: argument count is lower than 4.");
		}

		static const string command =         argv[1];
		static const string output_filename = argv[2];
		static const string input_filename =  argv[3];

		if (!regex_match(command, command_regex))
		{
			throw Error("Error: program must be executed in the following order: assembler -o output_file.o input_file.s ");
		}

		if (!regex_match(input_filename, input_file_regex))
		{
			throw Error("Error: input file must be an assembler (.s) file.");
		} 

		if (!regex_match(output_filename, output_file_regex))
		{
			throw Error("Error: output file must be an object (.o) file.");
		}

		Lexer::tokenize_input_file(input_filename);

		Assembler::single_pass();

		Lexer::write_to_output(output_filename);

		Symbol::delete_symbol_table();

		Relocation::delete_relocations();

		UnknownSymbol::delete_unknown_symbols();

		Data::delete_data();
	}
	catch (const Error& error)
	{
		cerr << error.what() << endl;

		Symbol::delete_symbol_table();

		Relocation::delete_relocations();

		UnknownSymbol::delete_unknown_symbols();

		Data::delete_data();

		return _incorrect_execution;
	}

	return _correct_execution;
}