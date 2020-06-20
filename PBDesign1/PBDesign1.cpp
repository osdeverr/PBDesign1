// PBDesign1.cpp : Defines the entry point for the application.
//

#include <pcl/policies/invalid.h>
#include <pcl/vectors/dzen.h>
#include <pcl/hashing/autohash.h>

#include <fmt/format.h>
#include <fmt/color.h>

enum class level
{
	debug,
	fixme,
	info,
	warn,
	error,
};

template<level Level>
void print_warn_header();

template<>
void print_warn_header<level::debug>()
{
	using namespace fmt;
	print(fg(color::dark_slate_gray), "debug");
}

template<>
void print_warn_header<level::fixme>()
{
	using namespace fmt;
	print(fg(color::magenta), "fixme");
}

template<>
void print_warn_header<level::info>()
{
	using namespace fmt;
	print(fg(color::lime_green), "info");
}

template<>
void print_warn_header<level::warn>()
{
	using namespace fmt;
	print(fg(color::yellow), "warn");
}

template<>
void print_warn_header<level::error>()
{
	using namespace fmt;
	print(fg(color::red), "error");
}

template<level Level, typename... Args>
void logw(const std::string& format, Args... args)
{
	using namespace fmt;
	print_warn_header<Level>();
	print(fg(color::dim_gray), ": ");

	print(format, args...);
	print("\n");
}

using myhash = pcl::hashing::autohash<std::string>;
void DoPlaks(myhash h)
{
	logw<level::info>("Resolved: '{}'", h.resolve());
}

int main()
{
	pcl::vectors::dzen<int> v1; // auto tparam = unsafe
	pcl::vectors::dzen<float, pcl::policies::threading::thread_unsafe> v2;
	pcl::vectors::dzen<long, pcl::policies::threading::thread_safe> v3;

	// pcl::vectors::dzen<long, pcl::policies::invalid> v4;

	v1.set(30);
	v2.set(v1.get());
	v3.set(v2.get());

	logw<level::debug>("v1 = {}; v2 = {}; v3 = {}", v1.get(), v2.get(), v3.get());

	DoPlaks("hi");
}
