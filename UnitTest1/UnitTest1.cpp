#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include "CppUnitTest.h"
#include "../lab2.2/String.h"
#include "../lab2.2/String.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab22
{
    TEST_CLASS(UnitTestString)
    {
    public:
        TEST_METHOD(TestDefaultConstructor)
        {
            String s;
            Assert::AreEqual(0, s.GetLength());
            Assert::AreEqual(std::string(""), std::string(s.GetStr()));
        }

        TEST_METHOD(TestInitConstructor)
        {
            String s("Слава Україні");
            Assert::AreEqual(std::string("Слава Україні"), std::string(s.GetStr()));
            Assert::IsTrue(s.GetLength() > 0);
        }

        TEST_METHOD(TestCopyConstructor)
        {
            String s1("Дрогобич");
            String s2 = s1;
            Assert::AreEqual(std::string(s1.GetStr()), std::string(s2.GetStr()));
            Assert::AreEqual(s1.GetLength(), s2.GetLength());
        }
    };
}