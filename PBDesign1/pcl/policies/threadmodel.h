#pragma once
#include <mutex>

namespace pcl::policies
{
	struct thread_model
	{};

	class thread_safe : thread_model
	{
	public:
		void lock() { mLock.lock(); }
		void unlock() { mLock.unlock(); }
	private:
		std::mutex mLock;
	};

	class thread_unsafe : thread_model
	{
	public:
		void lock() {}
		void unlock() {}
	};
}
