#pragma once
#include <functional>
#include <unordered_map>

namespace pcl::policies::hashing
{
	struct hasher
	{};

	struct resolver
	{};

	template<class Hash, class String>
	class std_hasher : hasher
	{
	public:
		static Hash hash(const String& str)
		{
			return std::hash<String>()(str);
		}
	};

	template<class Hash, class String>
	class std_resolver : resolver
	{
	public:
		static void add(Hash hash, const String& res)
		{
			mValues[hash] = res;
		}

		static String resolve(Hash hash)
		{
			return mValues[hash];
		}
	private:
		inline static std::unordered_map<Hash, String> mValues;
	};

	template<class Hash, class String>
	class null_resolver : resolver
	{
	public:
		static void add(Hash hash, const String& res)
		{
		}

		static String resolve(Hash hash)
		{
			return {};
		}
	};
}
