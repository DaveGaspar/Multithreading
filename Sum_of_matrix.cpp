#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include "../Template_matrix/Matrix.h"

const int core_count = std::thread::hardware_concurrency();

int main(){

	int sum = 0;
	
	Matrix<int> matrix(8,8);
	matrix.init();
	matrix.print();

	std::cout << "Cores count = " << core_count << std::endl;
	
	auto start = std::chrono::high_resolution_clock::now();
	
	std::vector<std::thread> thread_vec(core_count);

	for (int i = 0; i < core_count; ++i){
		thread_vec[i] = std::thread([](Matrix<int> matrix, int core, int& sum){
			int range = matrix.get_row() / core_count;
			for (int i = core * range; i < (core + 1) * range; ++i){
				for (int j = 0; j < matrix.get_column(); ++j){
					sum += matrix[i][j];
				}
			}
		}, matrix, i, std::ref(sum));
	}

	for (int i = 0; i < core_count; ++i){
		thread_vec[i].join();
	}

	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

	std::cout << "Sum of matrix elements = " << sum << std::endl;
    std::cout << "Execution time: " << duration.count() << " microseconds" << std::endl;

	return 0;
}