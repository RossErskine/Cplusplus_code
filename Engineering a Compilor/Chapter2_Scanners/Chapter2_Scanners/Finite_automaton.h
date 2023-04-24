#include <iostream>
#include <string>

using namespace std;

enum class State
{
	zero,one,two,three,four,five,six,seven,eight,nine,ten,eleven,
	twelve,thirteen,fourteen,fifteen,sixteen,seventeen,eighteen,
	ninteen,twenty,twentyone
};

bool searchState(const string& text)
{
	State activeState = State::zero;
	int s = 0, count = 0;;
	bool run = true;
	
	for (int i = 0; i != text.length(); ++i)
	{
		unsigned char ch = text[i];		//converted for (isalpha and isdigit)
		switch (activeState)
		{
		case State::zero:		//================ s0 ===//
			if (!isalpha(ch)){cout << "se "; break;}
			else if(text[i]=='s'){
				activeState = State::one;
				cout << "s0s "; break;
			}
			else if (text[i] == 'd'){
				activeState = State::six;
				cout << "s0d "; break;
			}
			else if (text[i] == 'b'){
				activeState = State::fifteen;
				cout << "s0b "; break;
			}else {
				cout << "se ";
				break;
			}
			break;
		case State::one:		//================ s1 ===//
			if (text[i] == 't'){
				activeState = State::two;
				cout << "s1 "; break;
			}else{
				activeState = State::zero;
				cout << "se "; break;
			}
			break;
		case State::two:		//================ s2 ===//
			if (text[i] == 'a') {			
				activeState = State::three;
				cout << " s2";
				break;
			}else{
				activeState = State::zero;
				cout << "se "; break;
			}
			break;
		case State::three:		//================ s3 ===//
			if (text[i] == 'r') {			
				activeState = State::four;
				cout << " s3"; break;
			}else{
				activeState = State::zero;
				cout << "se "; break;
			}
			break;
		case State::four:		//================ s4 ===//
			if (text[i] == 't') {			
				activeState = State::five;
				cout << " s4 ";break;
			}else{
				activeState = State::zero;
				cout << "se "; break;
			}
			break;
		case State::six:	//================ s6 ===//
			if (text[i] == 'd') {
				activeState = State::seven;
				cout << " s6 "; break;
			}else{
				activeState = State::zero;
				cout << "se "; break;
			} break;

		case State::seven:	//================ s7 ===//
			if (text[i] == '(') {
				activeState = State::eight;
				cout << "s7 "; break;
			}else {
				activeState = State::zero;
				cout << "se "; break;
			} break;

		case State::eight:	//================ s8 ===//
			if (text[i] == ')') {
				if (i != text.length()-1)
				{
					activeState = State::nine;
					cout << "s8-9 "; break;
				}
				else {
					activeState = State::ten;
					cout << "s8-10 "; break;
				}
			}
			else {
				activeState = State::zero;
				cout << "se "; break;
			} break;
		case State::nine:	//================ s9 ===//
			if (text[i] == 't') {
				activeState = State::eleven;
				cout << "s9 "; break;
			}else{
				activeState = State::zero;
				cout << "se "; break;
			} break;

		case State::eleven:	//================ s11 ===//
			if (text[i] == 't') {
				activeState = State::twelve;
				cout << "s11 "; break;
			}
			else {
				activeState = State::zero;
				cout << "se "; break;
			} break;

		case State::twelve:		//================ s12 ===//
			if (text[i] == '(') {
				activeState = State::thirteen;
				cout << "s12 "; break;
			}
			else {
				activeState = State::zero;
				cout << "se "; break;
			} break;

		case State::thirteen:	//=============== s13 ===//
			if (text[i] == ')') {
				activeState = State::fourteen;
				cout << "s13 "; break;
			}
			else {
				activeState = State::zero;
				cout << "se "; break;
			} break;

		case State::fifteen:	//=============== s15 ===//
			if (text[i] == 'e') {
				activeState = State::sixteen;
				cout << "s15 "; break;
			}
			else {
				activeState = State::zero;
				cout << "se "; break;
			} break;

		case State::sixteen:	//=============== s16 ===//
			if (text[i] == 'g') {
				activeState = State::seventeen;
				cout << "s16 "; break;
			}
			else {
				activeState = State::zero;
				cout << "se "; break;
			} break;

		case State::seventeen:	//=============== s17 ===//
			if (text[i] == 'i') {
				activeState = State::eighteen;
				cout << "s17 "; break;
			}
			else {
				activeState = State::zero;
				cout << "se "; break;
			} break;

		case State::eighteen:	//=============== s18 ===//
			if (text[i] == 'n') {
				activeState = State::ninteen;
				cout << "s18 "; break;
			}
			else {
				activeState = State::zero;
				cout << "se "; break;
			} break;

		case State::ninteen:	//=============== s19 ===//
			if (text[i] == '{') {
				activeState = State::twenty;
				cout << "s19 "; break;
			}
			else {
				activeState = State::zero;
				cout << "se "; break;
			} break;

		case State::twenty:	//=============== s20 ===//
			if (text[i] == '}') {
				activeState = State::twentyone;
				cout << "s20 "; break;
			}
			break;

		default:
			activeState = State::zero;
			cout << "se ";
			break;
			
		}
		
		
	}
	//==accepting states ==//
	if (activeState == State::five){
		cout << "s5 ";
		return true;
	}
	if (activeState == State::ten) {
		cout << "s10 ";
		return true;
	}
	if (activeState == State::fourteen) {
		cout << "s14 ";
		return true;
	}
	if (activeState == State::twentyone) {
		cout << "s21 ";
		return true;
	}else {
		return false;
	}
		
}
void search(const string& text)
{
	if (searchState(text)) {
		cout << "\nlanguage accepted\n";
	}else {
		cout << "\nlanguage not accepted!\n";

	}
}
void runFA()
{
	string text1 = "start";
	string text2 = "dd()";
	string text3 = "dd()tt()";
	string text4 = "begin{}";
	string text5 = "begin{dave}";
	search(text1);
	search(text2);
	search(text3);
	search(text4);
	search(text5);
	
}