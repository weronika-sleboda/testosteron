#ifndef TEST_OBJECT_H
#define TEST_OBJECT_H

#include <string>

namespace testosteron
{

	class TestObject
	{

	public:

		TestObject
		(

			const std::string const theFunctionName,
			const bool const theExpectedBoolResult,
			const std::string const theWantedOutputDescription,
			const std::string const theUnwantedOutputDescription

		);

		const std::string const getFunctionName() const;
		const bool const hasPassed();
		const std::string const getOutputDescription() const;

	private:


		const std::string const functionName;
		const bool const expectedBoolResult;
		const std::string const wantedOutputDescription;
		const std::string const unwantedOutputDescription;

	};

}

#endif