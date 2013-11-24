#include <stdexcept>

#include "TestClass.h"

namespace lhsTest
{
	void TestClass::Assert(bool test, std::string msg)
	{
		if (!test)
			throw new std::runtime_error(msg.append("\n\n").c_str());
	}
}