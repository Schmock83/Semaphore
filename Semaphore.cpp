#include "Semaphore.h"

Semaphore::Semaphore(unsigned int max_thread_count)
	:max_thread_count(max_thread_count)
{
}

void Semaphore::aquire()
{
	std::unique_lock<std::mutex> lk(semaphore_mtx);
	if (max_thread_count == 0)
		semaphore_cv.wait(lk);

	//after wait
	--max_thread_count;
}

void Semaphore::release()
{
	++max_thread_count;
	semaphore_cv.notify_one();
}