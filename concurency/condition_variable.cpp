#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <algorithm>
#include <condition_variable>

using namespace std;

mutex mtx;
condition_variable cv;
bool ready = false;

void do_print_id(int id) {
	unique_lock <mutex> lck(mtx);
	while (!ready) // 如果标志位不为 true, 则等待...
		cv.wait(lck); // 当前线程被阻塞, 当全局标志位变为 true 之后,
	cout << "thread " << id << " -.- " << this_thread::get_id() << '\n';
}

void go() {
	unique_lock <mutex> lck(mtx);
	ready = true; // 设置全局标志位为 true.
	cv.notify_all(); // 唤醒所有线程.
}

int main() {
	vector<thread> threads;
	for (int i = 0; i < 4; ++i)
		threads.push_back(thread(do_print_id, i));
	cout << "4 threads ready to race...\n";
	go(); // go!
	for_each(threads.begin(), threads.end(), mem_fn(&thread::join));
	return 0;
}