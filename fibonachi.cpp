#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <functional>

std::mutex mtx;
std::vector<int> vec_fibo = {0, 1};

//without recursion
// void fibonachi(const int n, int& x){
// 	if (n < 0){
// 		return;
// 	}
// 	if (n == 0){
// 		x = 0;
// 		return;
// 	}
// 	mtx.lock();
// 	if (n < vec_fibo.size()){
// 		x = vec_fibo[n];
// 	}
// 	else if (vec_fibo.size() == 2){
// 		int a = 0, b = 1, c = 1;
// 		for (int i = 2; i <= n; i++){
// 			c = a + b;
// 			a = b;
// 			b = c;
// 			vec_fibo.push_back(c);
// 		}
// 		x = c;
// 	}
// 	else{
// 		int a = vec_fibo[vec_fibo.size()-1-1];
// 		int b = vec_fibo[vec_fibo.size()-1];
// 		int c;

// 		for (int i = vec_fibo.size()-1; i <= n; i++){
// 			c = a + b;
// 			a = b;
// 			b = c;
// 			vec_fibo.push_back(c);
// 		}
// 		x = vec_fibo[n];
// 	}
// 	mtx.unlock();
// }

//with recursion

void fibonachi(const int n, int& x){
	if (n < 0){
		return;
	}
	if (n == 0){
		x = 0;
		return;
	}

	std::function<int(const int)> fibo = [&](int const n){
		if (n <= 1){
			return n;
		}
		if (n < vec_fibo.size()){
			return vec_fibo[n];
		}
		else{
			vec_fibo.push_back(fibo(n - 1) + fibo(n - 2));
			return vec_fibo[n];
		}
	};

	mtx.lock();
	x = fibo(n);
	mtx.unlock();
}

int main(){

	int x1, x2, x3, x4, x5, x6, x7, x8, x9, x10, x11, x12, x13, x14, x15, x16, x17, x18, x19, x20;

	std::thread t1(fibonachi, 5, std::ref(x1));
	std::thread t2(fibonachi, 8, std::ref(x2));
	std::thread t3(fibonachi, 3, std::ref(x3));
	std::thread t4(fibonachi, 4, std::ref(x4));
	std::thread t5(fibonachi, 9, std::ref(x5));
	std::thread t6(fibonachi, 5, std::ref(x6));
	std::thread t7(fibonachi, 6, std::ref(x7));
	std::thread t8(fibonachi, 2, std::ref(x8));
	std::thread t9(fibonachi, 9, std::ref(x9));
	std::thread t10(fibonachi, 11, std::ref(x10));
	std::thread t11(fibonachi, 7, std::ref(x11));
	std::thread t12(fibonachi, 12, std::ref(x12));
	std::thread t13(fibonachi, 14, std::ref(x13));
	std::thread t14(fibonachi, 3, std::ref(x14));
	std::thread t15(fibonachi, 9, std::ref(x15));
	std::thread t16(fibonachi, 8, std::ref(x16));
	std::thread t17(fibonachi, 4, std::ref(x17));
	std::thread t18(fibonachi, 1, std::ref(x18));
	std::thread t19(fibonachi, 0, std::ref(x19));
	std::thread t20(fibonachi, 3, std::ref(x20));

	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	t6.join();
	t7.join();
	t8.join();
	t9.join();
	t10.join();
	t11.join();
	t12.join();
	t13.join();
	t14.join();
	t15.join();
	t16.join();
	t17.join();
	t18.join();
	t19.join();
	t20.join();

	std::cout << "Ind: " << "\t";
	for (auto i = 0; i < vec_fibo.size(); i++){
		std::cout << i << "\t";
	}
	std::cout << "\nVec: " << "\t";
	for (auto in : vec_fibo){
		std::cout << in << "\t";
	}
	std::cout << std::endl;

	std::cout << "x1 = " << x1 << std::endl;
	std::cout << "x2 = " << x2 << std::endl;
	std::cout << "x3 = " << x3 << std::endl;
	std::cout << "x4 = " << x4 << std::endl;
	std::cout << "x5 = " << x5 << std::endl;
	std::cout << "x6 = " << x6 << std::endl;
	std::cout << "x7 = " << x7 << std::endl;
	std::cout << "x8 = " << x8 << std::endl;
	std::cout << "x9 = " << x9 << std::endl;
	std::cout << "x10 = " << x10 << std::endl;
	std::cout << "x11 = " << x11 << std::endl;
	std::cout << "x12 = " << x12 << std::endl;
	std::cout << "x13 = " << x13 << std::endl;
	std::cout << "x14 = " << x14 << std::endl;
	std::cout << "x15 = " << x15 << std::endl;
	std::cout << "x16 = " << x16 << std::endl;
	std::cout << "x17 = " << x17 << std::endl;
	std::cout << "x18 = " << x18 << std::endl;
	std::cout << "x19 = " << x19 << std::endl;
	std::cout << "x20 = " << x20 << std::endl;
	return 0;
}