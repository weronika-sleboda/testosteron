#include "test_object.h"

namespace testosteron
{

	TestObject::TestObject
	(

		const std::string const theFunctionName,
		const bool const theExpectedBoolResult,
		const std::string const theWantedOutputDescription,
		const std::string const theUnwantedOutputDescription

	) :

		functionName { theFunctionName },
		expectedBoolResult { theExpectedBoolResult },
		wantedOutputDescription { theWantedOutputDescription },
		unwantedOutputDescription { theUnwantedOutputDescription }

	//*** Constructor Body

	{} 

	const std::string const TestObject::getFunctionName() const
	{

		return functionName;

	}

	const bool const TestObject::hasPassed()
	{

		return expectedBoolResult;

	}

	const std::string const TestObject::getOutputDescription() const
	{

		if (expectedBoolResult)
		{

			return "Result: " + wantedOutputDescription;

		}

		else
		{

			return "Result: " + unwantedOutputDescription;

		}

	}

}