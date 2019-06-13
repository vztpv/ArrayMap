
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <map>
#include <random>
#include <chrono>
#include "ArrayMap.h"


inline long long Rand() noexcept {
	return rand(); // (rand() & 255) + ((rand() & 255) << 8) + ((rand() & 255) << 16) + ((rand() & 255) << 24);
}

int main(void)
{
	try {
		unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();


		std::vector<int> x(10240000, 0);
		//std::sort(x.begin(), x.end());
		long long max = 0;

		for (int i = 0; i < x.size(); ++i) {
			x[i] = Rand();
			if (x[i] > max) {
				max = x[i];
			}
		}

		int a = clock();
		wiz::ArrayMap<int, int> map;
		for (int i = 0; i < x.size(); ++i) {
			map.lazy_insert(std::make_pair(x[i], x[i] + 1));
			//map[x[i]];
		}
		map[max] = 0;
		int b = clock();

		//map.PrintTree();

		std::cout << b - a << "ms\n";

		std::cout << "------------------------\n";
		a = clock();
		std::map<int, int> map2;
		for (int i = 0; i < x.size(); ++i) {
			map2.insert(std::make_pair(x[i], x[i] + 1));
		}
		b = clock();

		//map2[max]= 0;
		std::cout << b - a << "ms\n";
		std::cout << "------------------------\n";


		std::shuffle(x.begin(), x.end(), std::default_random_engine(seed));

		a = clock();
		for (int i = 0; i < x.size(); ++i) {
			if (map.end() == map.find(x[i])) {
				return -1;
			}
		}
		b = clock();
		std::cout << b - a << "ms\n";
		std::cout << "------------------------\n";




		a = clock();
		for (int i = 0; i < x.size(); ++i) {
			map2.find(x[i]);
		}
		b = clock();
		std::cout << b - a << "ms\n";

		a = clock();
		for(int i=0; i < 1; ++i) {
			auto map1 = wiz::ArrayMap<int, int>();
			for (int i = 0; i < 10000000; ++i) {
				map1.insert(std::make_pair(i, i));
			}
		}
		b = clock();
		std::cout << b - a << "ms\n";
		a = clock();
		for (int i = 0; i < 1; ++i) {
			auto map2 = std::map<int, int>(); 
			for (int i = 0; i < 10000000; ++i) {
				map2.insert(std::make_pair(i, i));
			}
		}
		b = clock();
		std::cout << b - a << "ms\n";

	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << "\n";
	}
	return 0;
}

