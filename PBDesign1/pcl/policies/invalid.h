#pragma once

namespace pcl::policies
{
	/// <summary>
	/// Can be used to test classes' behavior when invalid policies are passed.
	/// Most of the basic PCL classes are going to throw a compile error.
	/// </summary>
	struct invalid
	{};
}
