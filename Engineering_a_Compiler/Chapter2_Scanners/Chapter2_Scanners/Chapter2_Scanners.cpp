//#include "Finite_automaton.h"
//#include "Direct_coded_scanner.h"
#include "Recogniser.h"

int main()
{
	try
	{
		//using namespace dcs;
		runRecogniser();
		//runDCS();
		//runFA();
		return 0;
	}
	catch (const char* msg)
	{
		std::cerr << msg << std::endl;

	}
	catch (...)
	{
		std::cerr << "exception\n";
	}
}


