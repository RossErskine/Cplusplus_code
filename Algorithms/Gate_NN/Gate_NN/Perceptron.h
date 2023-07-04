#include <vector>
#include <random>
#include <iostream>

namespace NN_lib
{
	class Perceptron
	{
	public:
		// == constructor == //
		Perceptron(int num);
		
		// == modifying operations == //
		int feedForward(std::vector<int> inputs);
		void train(std::vector<int> inputs, int desired);

	private:
		int numOfInputs;
		float sum_of_errors;
		std::vector<float> weights;
		float learning_const = 0.01f; // learning constant
		
	};

	// === helper functions === //
	float randfloat(float min, float max);		// generates random number

	
}
