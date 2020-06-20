#pragma once
#include <pcl/policies/hashing.h>
#include <string>

namespace pcl::hashing
{
	/// <summary>
	/// Represents a hash, implicitly constructible from a string.
	/// </summary>
	/// <typeparam name="String">The string type to hash</typeparam>
	/// <typeparam name="Hash">The resulting hash type</typeparam>
	/// <typeparam name="Hasher">The hasher to use</typeparam>
	/// <typeparam name="Resolver">The hash resolver to use</typeparam>
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

		using hash_type = Hash;
		using string_type = String;

		static_assert(
			std::is_base_of_v<pcl::policies::hashing::hasher, hasher>,
			"The specified Hasher does not have the hashing::hasher tag"
			);

		static_assert(
			std::is_base_of_v<pcl::policies::hashing::resolver, resolver>,
			"The specified Resolver does not have the hashing::resolver tag"
			);

		/// <summary>
		/// Hashes a string. The argument is implicitly converted to <see cref="string_type"/>; thus, autohash is only constructible from types convertible to it.
		/// </summary>
		/// <typeparam name="T">The type to construct this object from</typeparam>
		/// <param name="s">The string to hash</param>
		template<class T, class U = std::enable_if_t<std::is_convertible_v<T, string_type>>>
		autohash(const T& s)
			: mHash(hasher::hash(s))
		{
			resolver::add(mHash, s);
		}

		/// <summary>
		/// Constructs this object from a raw hash value.
		/// </summary>
		/// <param name="h">The hash value</param>
		autohash(const hash_type h)
			: mHash(h)
		{}

		/// <summary>
		/// Returns the hash value contained within this object.
		/// </summary>
		/// <returns>The hash value</returns>
		hash_type hash() const
		{
			return mHash;
		}

		/// <summary>
		/// Tries to resolve the hash contained within this object using the resolver specified in template arguments. Returns an empty string if the hash cannot be resolved.
		/// </summary>
		/// <returns>The original hashed string or an empty string</returns>
		string_type resolve() const
		{
			return resolver::resolve(mHash);
		}

	private:
		hash_type mHash;
	};
}
