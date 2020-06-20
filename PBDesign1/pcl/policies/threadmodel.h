#pragma once
#include <mutex>

namespace pcl::policies
{
	/// <summary>
	/// Represents a "tag" to distinguish threading models from other policies.
	/// You must inherit from this to mark your policy as a thread policy.
	/// </summary>
	struct thread_model
	{};

	/// <summary>
	/// A dummy thread policy doing nothing.
	/// </summary>
	class thread_unsafe : thread_model
	{
	public:
		void lock() {}
		void unlock() {}
	};

	/// <summary>
	/// A simple mutex-based thread policy. Can be used with lock_guard since it's a BasicLockable.
	/// </summary>
	class thread_safe : thread_model
	{
	public:
		void lock() { mLock.lock(); }
		void unlock() { mLock.unlock(); }
	private:
		std::mutex mLock;
	};
}
