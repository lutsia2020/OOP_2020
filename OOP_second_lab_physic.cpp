// OOP_second_lab_physic.cpp: определяет точку входа для консольного приложения.
#include "Case.h"
#include "stdafx.h"
#include <time.h>
#include <thread>
#include <chrono>
using namespace std;

int main() {
	Case A (10000, 2);
	Vec T_init(0.0, 10000);
	T_init[50] = 0.1;
	A.setInitial(T_init);
	// our solution
	clock_t start = clock();
	chrono::seconds dura(1);
	for (int i = 0; i < 1000000; i++) {
		A.step();
		printf("Iteration %d\n", i);
		printf("next\n");
		for (auto x : A.T)
			printf("%d ", x);
		printf("\n");
		this_thread::sleep_for(dura);
		printf("next\n");
	}

	clock_t end = clock();
	double seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("The time: %f seconds\n", seconds);
	A.write("case A.txt");
}

