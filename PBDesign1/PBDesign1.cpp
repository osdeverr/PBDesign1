// PBDesign1.cpp : Defines the entry point for the application.
//

#include <pcl/vectors/dzen.h>

int main()
{
	pcl::vectors::dzen<int> v1; // auto tparam = unsafe
	pcl::vectors::dzen<float, pcl::policies::thread_unsafe> v2;
	pcl::vectors::dzen<char, pcl::policies::thread_safe> v3;

	v1.set(30);
	v2.set(v1.get());
	v3.set(v2.get());

	__debugbreak();
}
