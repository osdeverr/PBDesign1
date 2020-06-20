#pragma once
#include <functional>
#include <unordered_map>

namespace pcl::policies::hashing
{
	/// <summary>
	/// Represents a "tag" to distinguish hashers from other policies.
	/// You must inherit from this to mark your policy as a hasher.
	/// </summary>
	struct hasher
	{};

	/// <summary>
	/// Represents a "tag" to distinguish hash resolvers from other policies.
	/// You must inherit from this to mark your policy as a hash resolver.
	/// </summary>
	struct resolver
	{};

	/// <summary>
	/// A default hasher using std::hash.
	/// </summary>
	template<class Hash, class String>
	class std_hasher : hasher
	{
	public:
		static Hash hash(const String& str)
		{
			return std::hash<String>()(str);
		}
	};

	/// <summary>
	/// A default hash resolver, saving all hashed strings to a map for later resolution.
	/// Generally, std_resolver is enough for most use cases: you would rarely need to implement your own hasher.
	/// </summary>
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

	/// <summary>
	/// A dummy hash resolver saving nothing. Any resolve() calls return an empty string.
	/// </summary>
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
