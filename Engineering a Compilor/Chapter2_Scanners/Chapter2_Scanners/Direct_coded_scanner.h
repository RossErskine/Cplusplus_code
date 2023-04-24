#include <vector>
#include <string>
#include <iostream>
#include <fstream>

namespace dcs
{
	
	
	enum class State
	{
		s0 = 0, s1, s2, s3, s4, s5, s6, sA, se
	};
	
	
	const std::vector<char> finite_alphabet = { 'a','b','c' };
	State currState = State::se;
																// a,		b,		c,		other
	std::vector<std::vector<State>> transition_table = {	{State::s1,State::s2,State::s3,State::se,},		//s0
															{State::se,State::s4,State::se,State::se,},		//s1
															{State::se,State::se,State::s5,State::se,},		//s2
															{State::s6,State::se,State::se,State::se,},		//s3
															{State::se,State::se,State::sA,State::se,},		//s4
															{State::sA,State::se,State::se,State::se,},		//s5
															{State::se,State::sA,State::se,State::se,},		//s6
															{State::se,State::se,State::se,State::se,},		//s7
															{State::se,State::se,State::se,State::se,},		//s8
															{State::se,State::se,State::se,State::se,}		//s9
	};

	bool in_alpha(char ch)
	{
		for (int i =0;i != finite_alphabet.size(); ++i)
		{
			if (ch == finite_alphabet[i]) return true;
		}
		return false;
	}

	bool nextChar(std::istream& instrm, char& ch) 
	{
		instrm >> ch;
		if (instrm.fail())return false;
		if (!in_alpha(ch))
		{
			currState = State::se;
			std::cin.putback(ch);
		}
		
		if (instrm.eof())return false;
		if(instrm.good())return true;
		return true;
	}

	int search_fin_alpha(const char& ch)
	{
		for (int i = 0; i != finite_alphabet.size();++i)
		{
			if (finite_alphabet[i] == ch)return i;
		}
		
	}
	State searchState(const int& row, const int& col)
	{
		State tempState;
		tempState = transition_table[row][col];
		return tempState;
	}

	void runDCS()
	{
		// == creation of data file == //
		std::vector<char> input = { 'd','a','b','c','c','a','b' };

		const std::string data = "data.input";
		std::ofstream ost{ data };
		if (!ost)throw"cannot open output file", data;
		for (char i : input)
		{
			ost << i;
		}
		ost << '\n';
		ost.close();
		
		
		std::ifstream ist{ data };			// open file for input
		if (!ist)throw"cannot open input file", data;
		
		int row = 0, col = 0;
		std::vector<char> s;
		char ch;
		
		while (nextChar(ist, ch))
		{
			
			if (in_alpha(ch))	// in finite alphabet
			{
				
				if (currState == State::se) 
				{
					currState = State::s0;
				}
				 
				row = int(currState);
				col = search_fin_alpha(ch);

				currState = searchState(row, col);
				s.push_back(ch);

				// == accepting states == //
				if (currState == State::sA)
				{
					for (char c : s)
					{
						std::cout << c;
					}
					std::cout << ": Regular expression found!";
					currState = State::se;
					s.clear();
				}
				else if (currState == State::se)s.clear();
					
			}
			
		}
					
		/*if (currState == State::se)
		{
			std::cout << "No regular expression found!";
			return;
		}*/
		ist.close();
		
	}
																						
}
