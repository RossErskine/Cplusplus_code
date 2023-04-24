#include <iostream>
#include <fstream>
#include <vector>

std::vector<char> finite_alphabet = {'0','1','2','3','4','5','6','7','8','9'};

enum class State
{
	s0 = 0, s1, s2, se
};



// == operators == //
State operator++(State& st)
{
	st = State(int(st) + 1);
	return st;
}

// == recogniser transition function == //
State rec_trans_funct(State st, char ch)
{
	for (int i = 0; i != finite_alphabet.size(); ++i)
	{
		if ((ch == finite_alphabet[i])&& (st != State::se))
		{
			if ((st == State::s0)&& (ch == '0'))
			{
				st = State::s1; 
				return st;
			}
			else
			{
				st = State::s2;
				return st;
			}
				
		}
		
	}
	st = State::se;
	return st;
	
	
}

void nextChar(std::istream& instrm, char& ch)
{
	instrm >> ch;
	//if (!instrm.good()) throw "nextChar: not good!";
	
}

void dataFile(const std::vector<char>& input, const std::string& filename)
{
	// == creation of data file == //
	std::ofstream ost{ filename };
	if (!ost)throw"cannot open output file", filename;
	for (char i : input)
	{
		ost << i;
	}
	ost << '\n';
	ost.close();
}

void recognise_int()
{
	std::vector<char> input = { 'd'};
	const std::string data = "data.input";
	dataFile(input, data);				// create data file

	std::ifstream ist{ data };			// open file for input
	if (!ist)throw"cannot open input file", data;

	char ch;
	nextChar(ist, ch);
	State currState = State::s0;
	
	while ((!ist.eof()) && (currState != State::se))
	{
		currState = rec_trans_funct(currState, ch);
		nextChar(ist, ch);
		std::cout << int(currState) << ":"<<ch<<std::endl;
	}
	if ((currState == State::s1) || (currState == State::s2))
	{
		std::cout << "Unsigned integer accepted!";
	}
	else if(currState == State::se)
	{
		std::cout << "Unsigned integer not-accepted!";
	}

	ist.close();
}

void runRecogniser()
{
	recognise_int();

}
