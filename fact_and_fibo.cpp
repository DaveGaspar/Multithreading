#include <iostream>
#include <thread>

void fact(const int n, int& x){
	x = 1;
	if (n < 0){
		// throw "Negative input!";
		x = -1;
		return;
	}
	for (int i = 2; i <= n; i++){
		x *= i;
	}
}

void fibo(const int n, int& x){
	int a = 0, b = 1, c = 1;
	if (n < 0){
		// throw "Negative input!";
		x = -1;
		return;
	}
	if (n == 0){
		x = 0;
		return;
	}
	for (int i = 2; i <= n; i++){
        c = a + b;
        a = b;
        b = c;
    }
	x = c;

}

int main(){

	int n = 4, fa, fi;

	// try
	// {
		std::thread t1(fact, n, std::ref(fa));
		std::thread t2(fibo, n, std::ref(fi));

		std::cout << "Factorial of n = " << fa << std::endl;
		std::cout << "Fibonachi of n = " << fi << std::endl;

		t1.join();
		t2.join();
	// }
	// catch(const char * c)
	// {
	// 	std::cerr << c << std::endl;
	// }

	if (fa == -1 || fi == -1){
		std::cerr << "Negative input!" << std::endl;
	}

	return 0;
}