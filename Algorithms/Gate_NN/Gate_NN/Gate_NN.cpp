#include "Perceptron.h"
#include <iostream>

int main()
{
	try
	{
		using namespace NN_lib;

		// making and AND gate NN
		// training data - 0, 0 input 0 should it activate?
		std::vector<std::vector<int>> trainingSets = {
			{0, 0, 0},
			{0, 1, 0},
			{1, 0, 0},
			{1, 1, 1}
		};
		int input_number = 3;		// input each time 2 plus 1 bias
		Perceptron perceptron(2); // constructor

		std::cout << "\nTraining...";

		float error = 0;
		for (int i = 0; i < 50; i++)
		{
			std::cout << "\n " << i;
			for (int j = 0; j != trainingSets.size(); j++)
			{
				std::cout << "\nTrained: " << j << '\t';
				std::vector<int> temp = {
					trainingSets[j][0],
					trainingSets[j][1],
					1 // bias
				};
				perceptron.train(temp, trainingSets[j][2]);
				
			}

		}

		std::cout << "\n==============Test ======================" << '\n';
		// test after training
		for (int i = 0; i != trainingSets.size(); i++)
		{
			std::cout << "\nTrainingSet: " << i << ": ";
			std::vector<int> temp = {
					trainingSets[i][0],
					trainingSets[i][1],
					1 //bias
			};
			int result = perceptron.feedForward(temp);
			std::cout << "\t - Output:" << result;
		}
		
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
