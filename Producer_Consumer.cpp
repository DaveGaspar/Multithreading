#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>

std::condition_variable cv;
std::mutex mtx;

std::vector<int> vec;
const int max_vec_size = 100;

void produce(int val){
	while (val){
		std::unique_lock<std::mutex> ul(mtx);
		cv.wait(ul, [](){return vec.size() < max_vec_size;});
		vec.push_back(val);
		std::cout << "Produced = " << val << std::endl;
		val--;
		ul.unlock();
		cv.notify_one();
	}
}

void consume(){
	while (true){
		std::unique_lock<std::mutex> ul(mtx);
		cv.wait(ul, [](){return vec.size() > 0;});
		int val = vec.back();
		vec.pop_back();
		std::cout << "Consumed = " << val << std::endl;
		ul.unlock();
		cv.notify_one();
	}
}

int main(){
	std::thread producer(produce, 100);
	std::thread consumer(consume);

	producer.join();
	consumer.join();

	return 0;
}