#pragma once
#include <pcl/policies/hashing.h>
#include <string>

namespace pcl::hashing
{
	template<
		class String = std::string,
		class Hash = size_t,
		template<class, class> class Hasher = pcl::policies::hashing::std_hasher,
		template<class, class> class Resolver = pcl::policies::hashing::std_resolver
	>
	class autohash
	{
	public:
		using hasher = Hasher<Hash, String>;
		using resolver = Resolver<Hash, String>;

		static_assert(
			std::is_base_of_v<pcl::policies::hashing::hasher, hasher>,
			"The specified Hasher does not have the hashing::hasher tag"
			);

		static_assert(
			std::is_base_of_v<pcl::policies::hashing::resolver, resolver>,
			"The specified Resolver does not have the hashing::resolver tag"
			);

		template<class T, class U = std::enable_if_t<std::is_convertible_v<T, String>>>
		autohash(const T& s)
			: mHash(hasher::hash(s))
		{
			resolver::add(mHash, s);
		}

		autohash(const Hash h)
			: mHash(h)
		{}

		Hash hash() const
		{
			return mHash;
		}

		String resolve() const
		{
			return resolver::resolve(mHash);
		}

	private:
		Hash mHash;
	};
}
