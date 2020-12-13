#pragma once

#include <mutex>
#include <condition_variable>

class Semaphore
{
private:
	unsigned int max_thread_count;
	std::mutex semaphore_mtx;
	std::condition_variable semaphore_cv;
public:
	Semaphore(unsigned int max_thread_count);
	void aquire();
	void release();
};
