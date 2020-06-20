#pragma once
#include <pcl/policies/threadmodel.h>

namespace pcl::vectors
{
	template<class T, class ThreadModel = pcl::policies::thread_unsafe>
	class dzen
	{
	public:
		T& get() { std::lock_guard lg(mThreadModel); return mValue; }
		const T& get() const { std::lock_guard lg(mThreadModel); return mValue; }

		void set(const T& val) { std::lock_guard lg(mThreadModel); mValue = val; }
	private:
		ThreadModel mThreadModel{};
		T mValue{};
	};
}
