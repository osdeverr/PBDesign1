// PBDesign1.cpp : Defines the entry point for the application.
//

#include <pcl/policies/invalid.h>
#include <pcl/vectors/dzen.h>
#include <pcl/hashing/autohash.h>

using myhash = pcl::hashing::autohash<std::string>;
void DoPlaks(myhash h)
{
	std::printf("Resolved: %s", h.resolve().c_str());
}

int main()
{
	pcl::vectors::dzen<int> v1; // auto tparam = unsafe
	pcl::vectors::dzen<float, pcl::policies::threading::thread_unsafe> v2;
	pcl::vectors::dzen<char, pcl::policies::threading::thread_safe> v3;

	// pcl::vectors::dzen<long, pcl::policies::invalid> v4;

	v1.set(30);
	v2.set(v1.get());
	v3.set(v2.get());

	DoPlaks("hi");

	__debugbreak();
}
