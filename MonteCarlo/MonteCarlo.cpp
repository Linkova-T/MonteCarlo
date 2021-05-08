#include <random>
#include <iostream>
#include <future>
bool InCircle(double x, double y, double r)
{
	bool flag;
	if ((x * x + y * y) <= r) {
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
	std::mt19937 gen(rd()); // Mersen
	std::uniform_real_distribution<> dis(min, max);//uniform distribution between min and max
	return dis(gen);
};

int CountPoints(int n) {
	int points_in_circle = 0;
	for (auto i = 0; i < n; ++i) {
		double x = getRandomPoint(0, 1.0);
		double y = getRandomPoint(0, 1.0);
		if(InCircle(x,y,1))
		{
			++points_in_circle;
		}
	}
	return points_in_circle;
};
int main()
{//sequential
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
//parallel
	int p, n;
	p = 1000000;
	n = 10;
	int per_thread = p / n;
	std::vector<std::future<int>> futures;
	for (int t = 0; t < n; ++t) {
		futures.emplace_back(async(std::launch::async, CountPoints, per_thread));
	}

	int all_points_inside = 0;
	for (std::future<int>& f : futures) {
		all_points_inside += f.get();
	}

	double pi = 4.0 * (double)all_points_inside / (double)p;

	std::cout << "Parallel version: ";
	std::cout << "Pi = "<< pi << "\n";
	return 0;
}
