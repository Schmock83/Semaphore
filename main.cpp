#include <iostream>
#include <vector>
#include <future>

#define WITH_SEMAPHORE 1

#if WITH_SEMAPHORE
#include "Semaphore.h"

Semaphore s1{ 2 };
#endif

void func1() {
#if WITH_SEMAPHORE
	s1.aquire();
#endif
	for (int c = int('a'); c <= int('z'); c++) {
		std::cout << char(c) << " ";
	}
#if WITH_SEMAPHORE
	s1.release();
#endif
}

void func2() {
#if WITH_SEMAPHORE
	s1.aquire();
#endif
	for (int c = int('A'); c <= int('Z'); c++) {
		std::cout << char(c) << " ";
	}
#if WITH_SEMAPHORE
	s1.release();
#endif
}

void func3() {
#if WITH_SEMAPHORE
	s1.aquire();
#endif
	for (int i = 0; i <= 32; i++) {
		std::cout << i << " ";
	}
#if WITH_SEMAPHORE
	s1.release();
#endif
}

int main() {
	std::vector<std::future<void>> threads;
	threads.emplace_back(std::async(std::launch::async, func1));
	threads.emplace_back(std::async(std::launch::async, func2));
	threads.emplace_back(std::async(std::launch::async, func3));

	return 0;
}