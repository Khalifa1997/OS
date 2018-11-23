#include <iostream>
#include <istream>
#include <fstream>
#include <sstream>
#include <ostream>
#include <string>
#include <random>
using namespace std;
float roundd(float var)
{
	// we use array of chars to store number 
	// as a string. 
	char str[40];

	// Print in string the value of var  
	// with one decimal point 
	sprintf_s(str, "%.1f", var);

	// scan string value in var  
	sscanf_s(str, "%f", &var);

	return var;
}
int main(){
	string Inputfile = "input1.txt";
	ifstream input(Inputfile, ios::in);
	string temp;
	int n;	
	float a, b; //mean and stdiv of arrival
	float x, y; //mean and stdiv of burst
	float z; //lamda
	if (input.is_open())
	{
		getline(input, temp);
		//n
		stringstream ss(temp);
		ss >> n;
		ss.str("");
		ss.clear();

		// a,b
		getline(input, temp);
		ss << temp;
		ss >> a>> b;
		ss.str("");
		ss.clear();

		//x,y
		getline(input, temp);
		ss << temp;
		ss >> x >> y;
		ss.str("");
		ss.clear();

		//z
		
		getline(input, temp);
		ss << temp;
		ss >>z;
		ss.str("");
		ss.clear();
	}
	std::random_device rd;

	// Mersenne twister PRNG, initialized with seed from previous random device instance
	std::mt19937 generator(rd());
	std::normal_distribution<float> arrival(a, b);
	std::normal_distribution<float> burst(x, y);
	std::poisson_distribution<int> prio(z);
	string Outputfile = "output.txt";
	ofstream output(Outputfile, ios::out);
	output << n << endl;
	for (size_t i = 0; i < n; i++)
	{
		float arrive = roundd(arrival(generator));
		float burstt = roundd(burst(generator));
		output << i + 1 << " " << abs(arrive) << " " << abs(burstt) << " " << prio(generator) << endl;
	}
	
	system("pause");

}