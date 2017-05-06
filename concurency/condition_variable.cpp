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
	while (!ready) // �����־λ��Ϊ true, ��ȴ�...
		cv.wait(lck); // ��ǰ�̱߳�����, ��ȫ�ֱ�־λ��Ϊ true ֮��,
	cout << "thread " << id << " -.- " << this_thread::get_id() << '\n';
}

void go() {
	unique_lock <mutex> lck(mtx);
	ready = true; // ����ȫ�ֱ�־λΪ true.
	cv.notify_all(); // ���������߳�.
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