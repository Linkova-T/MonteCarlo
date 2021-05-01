#include <random>
#include <iostream>
bool InCircle(double x, double y, double r)
{
	return ((x * x + y * y) <= r);
};
double circle(double x, double radius)
{
	double y = radius * radius - x * x;
	return y;
};
double getRandomPoint(int min, int max) {
	std::random_device rd; // uniformly-distributed integer random number generator
	std::mt19937 gen(rd()); //инициализируем Вихрь Мерсенна случайным стартовым числом
	std::uniform_real_distribution<> dis(min, max);//uniform distribution between min and max
	return dis(gen);
};
int main()
{
	int r = 102400;
	int Nc = 0;
	int Nmax = 204800;
	/*for (int N = 0; N < Nmax; N++)
	{
		double x = getRandomPoint(0, 2*r);
		double y = getRandomPoint(0, 2*r);
		if (InCircle(x, y, r))
			Nc += 1;
		//std::cout << Ncir << " ";
	};
	double P = 4 * Nc / Nmax;
	std::cout << "Pi = " << P <<"\n";*/
	double Ncirc = 0;
	int i = 0;
	while ( i < Nmax)
	{
		double x = getRandomPoint(0, 2 * r);
		double y = getRandomPoint(0, 2 * r);
		if (y * y <= circle(x, (Nmax / 2)))  //Условие принадлежности точки к кругу
		{
			Ncirc++;
		}
		i++;
	}

	double Pi = (Ncirc / Nmax) * 4*4;
	std::cout << Pi;
}