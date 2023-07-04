#include "Perceptron.h"

namespace NN_lib
{
	// ========================= member functions ============================== //
	// === constructor === //
	Perceptron::Perceptron(int num): numOfInputs(num ), sum_of_errors(0)
	{
		//weights.resize(numOfInputs);
		for (int i = 0; i != numOfInputs; i++)
		{
			float rnd = randfloat(-1, 1);
			weights.push_back(rnd);
		}
	}
	// == indentify/classify input pattern == //
	// == a single perceptron == //
	int Perceptron::feedForward(std::vector<int> inputs)
	{
		// === summation function === // 
		float sum = 0;
		
		// == output layer == //
		for (int i = 0; i != numOfInputs; i++)
		{
			sum += inputs[i] * weights[i];
		}
		//sum += 1 * weights[numOfInputs-1];

		// === activation function === //
		//double sigmoid = 1 / (1 + exp(-sum));

		//std::cout << "Sig: " << sigmoid;

		if (sum >= 0)
			return 1;
		else
			return 0;
	}

	// == train network based on input patterns with desired result == //
	// == squared error == //
	void Perceptron::train(std::vector<int> inputs, int desired)
	{
		int guess = feedForward(inputs); // classify input pattern

		float error = desired - guess;	// calculate error value 

		for (int i = 0; i != weights.size(); i++)	// adjust weights
		{
			weights[i] +=  error * inputs[i] * learning_const; //  learning constant value
		}
		std::cout << "\t Error: " << learning_const * error * 1;
		//weights[weights.size() - 1] += learning_const * error * 1;

	}

	// ======================== helper functions =============================== //
	float randfloat(float min, float max)// generates random number
	{
		static std::default_random_engine ran;
		return std::uniform_real_distribution<>{min, max}(ran);
	}
	
}
