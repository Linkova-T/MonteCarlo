#include <random>
#include <iostream>
bool InCircle(double x, double y, double r)
{
	bool flag;
	if ((x * x + y * y) < r) {
		flag = true;
	}
	else
	{
		flag = false;
	}
	return flag;
};
double getRandomPoint(int min, int max) {
	std::random_device rd; // uniformly-distributed integer random number generator
	std::mt19937 gen(rd()); //инициализируем Вихрь Мерсенна случайным стартовым числом
	std::uniform_real_distribution<> dis(min, max);//uniform distribution between min and max
	return dis(gen);
};
int main()
{
	int r = 1;
	int Nc = 0;
	int Nmax = 1000000;
	for (int N = 0; N < Nmax; N++)
	{
		double x = getRandomPoint(0, r);
		double y = getRandomPoint(0, r);
		if (InCircle(x, y, r)) {
			Nc = Nc +1;
		}
			
	};
	double P = 4 *((double) Nc / (double)Nmax);
	std::cout << "Sequential version: ";
	std::cout << "Pi = " << P <<"\n";

}
