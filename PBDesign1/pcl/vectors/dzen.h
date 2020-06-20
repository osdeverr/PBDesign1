#pragma once
#include <pcl/policies/threadmodel.h>

namespace pcl::vectors
{
	/// <summary>
	/// Represents a Dzen vector. Exists for the sole reason of shits and giggles.
	/// </summary>
	/// <typeparam name="T">The value type of this Dzen vector.</typeparam>
	/// <typeparam name="ThreadModel">The thread model to use in this Dzen vector: <see cref="pcl::policies::thread_unsafe"/> by default.</typeparam>
	template<class T, class ThreadModel = pcl::policies::thread_unsafe>
	class dzen
	{
	public:
		static_assert(
			std::is_base_of_v<pcl::policies::thread_model, ThreadModel>,
			"The specified ThreadModel does not have the thread_policy tag"
			);

		/// <summary>
		/// Gets a reference to the internal value.
		/// </summary>
		/// <returns>A reference to this Dzen vector's internal value.</returns>
		T& get()
		{
			std::lock_guard lg(mThreadModel);
			return mValue;
		}

		/// <summary>
		/// Gets a const reference to the internal value: overloads get() for const instances of the Dzen vector.
		/// </summary>
		/// <returns>A const reference to this Dzen vector's internal value.</returns>
		const T& get() const
		{
			std::lock_guard lg(mThreadModel);
			return mValue;
		}

		/// <summary>
		/// Sets the internal value of this Dzen vector.
		/// </summary>
		/// <param name="val">The new value of this Dzen vector.</param>
		void set(const T& val)
		{
			std::lock_guard lg(mThreadModel);
			mValue = val;
		}
	private:
		ThreadModel mThreadModel{};
		T mValue{};
	};
}
