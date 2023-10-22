#include "CppUnitTest.h"
#include "GameObjectLib.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
    TEST_CLASS(Vector2Test)
    {
    public:
        TEST_METHOD(TestAddition)
        {
            Vector2<float, float> vec1(3.0f, 4.0f);
            Vector2<float, float> vec2(1.0f, 2.0f);
            Vector2<float, float> result = vec1 + vec2;

            Assert::AreEqual(result.x, 4.0f, L"Addition Test 1 failed.");
            Assert::AreEqual(result.y, 6.0f, L"Addition Test 2 failed.");
        }

        TEST_METHOD(TestSubtraction)
        {
            Vector2<float, float> vec1(3.0f, 4.0f);
            Vector2<float, float> vec2(1.0f, 2.0f);
            Vector2<float, float> result = vec1 - vec2;

            Assert::AreEqual(result.x, 2.0f, L"Subtraction Test 1 failed.");
            Assert::AreEqual(result.y, 2.0f, L"Subtraction Test 2 failed.");
        }

        TEST_METHOD(TestMultiplication)
        {
            Vector2<float, float> vec(3.0f, 4.0f);
            Vector2<float, float> result = vec * 2.0f;

            Assert::AreEqual(result.x, 6.0f, L"Multiplication Test 1 failed.");
            Assert::AreEqual(result.y, 8.0f, L"Multiplication Test 2 failed.");
        }

        TEST_METHOD(TestDivision)
        {
            Vector2<float, float> vec(3.0f, 4.0f);
            Vector2<float, float> result = vec / 2.0f;

            Assert::AreEqual(result.x, 1.5f, L"Division Test 1 failed.");
            Assert::AreEqual(result.y, 2.0f, L"Division Test 2 failed.");
        }

        TEST_METHOD(TestEquality)
        {
            Vector2<float, float> vec1(3.0f, 4.0f);
            Vector2<float, float> vec2(3.0f, 4.0f);
            Vector2<float, float> vec3(2.0f, 4.0f);

            Assert::IsTrue(vec1 == vec3, L"Equality Test 1 failed.");
            Assert::IsFalse(vec1 == vec2, L"Equality Test 2 failed.");
        }

        TEST_METHOD(TestMagnitude)
        {
            Vector2<float, float> vec(3.0f, 4.0f);
            double magnitude = vec.Magnitude();

            Assert::AreEqual(magnitude, 5.0, 0.0001, L"Magnitude Test failed.");
        }

        TEST_METHOD(TestNormalization)
        {
            Vector2<float, float> vec(3.0f, 4.0f);
            Vector2<double, double> normalized = vec.Normalize();

            double magnitude = normalized.Magnitude();

            Assert::AreEqual(normalized.x, 0.6, 0.0001, L"Normalization Test 1 failed.");
            Assert::AreEqual(normalized.y, 0.8, 0.0001, L"Normalization Test 2 failed.");
            Assert::AreEqual(magnitude, 1.0, 0.0001, L"Normalization Test 3 failed.");
        }

        TEST_METHOD(TestStaticProperties)
        {
            Vector2<float, float> one = Vector2<float, float>::One();
            Vector2<float, float> zero = Vector2<float, float>::Zero();
            Vector2<float, float> up = Vector2<float, float>::Up();
            Vector2<float, float> down = Vector2<float, float>::Down();
            Vector2<float, float> left = Vector2<float, float>::Left();
            Vector2<float, float> right = Vector2<float, float>::Right();
            Vector2<float, float> negInf = Vector2<float, float>::NegativeInfinity();
            Vector2<float, float> posInf = Vector2<float, float>::PositiveInfinity();

            Assert::AreEqual(one.x, 1.0f, 0.0001, L"One Static Property Test 1 failed.");
            Assert::AreEqual(one.y, 1.0f, 0.0001, L"One Static Property Test 2 failed.");
            Assert::AreEqual(zero.x, 0.0f, 0.0001, L"Zero Static Property Test 1 failed.");
            Assert::AreEqual(zero.y, 0.0f, 0.0001, L"Zero Static Property Test 2 failed.");
            Assert::AreEqual(up.x, 0.0f, 0.0001, L"Up Static Property Test 1 failed.");
            Assert::AreEqual(up.y, 1.0f, 0.0001, L"Up Static Property Test 2 failed.");
            Assert::AreEqual(down.x, 0.0f, 0.0001, L"Down Static Property Test 1 failed.");
            Assert::AreEqual(down.y, -1.0f, 0.0001, L"Down Static Property Test 2 failed.");
            Assert::AreEqual(left.x, -1.0f, 0.0001, L"Left Static Property Test 1 failed.");
            Assert::AreEqual(left.y, 0.0f, 0.0001, L"Left Static Property Test 2 failed.");
            Assert::AreEqual(right.x, 1.0f, 0.0001, L"Right Static Property Test 1 failed.");
            Assert::AreEqual(right.y, 0.0f, 0.0001, L"Right Static Property Test 2 failed.");
            Assert::AreEqual(negInf.x, std::numeric_limits<float>::min(), 0.0001, L"NegativeInfinity Static Property Test 1 failed.");
            Assert::AreEqual(negInf.y, std::numeric_limits<float>::min(), 0.0001, L"NegativeInfinity Static Property Test 2 failed.");
            Assert::AreEqual(posInf.x, std::numeric_limits<float>::max(), 0.0001, L"PositiveInfinity Static Property Test 1 failed.");
            Assert::AreEqual(posInf.y, std::numeric_limits<float>::max(), 0.0001, L"PositiveInfinity Static Property Test 2 failed.");
        }

        TEST_METHOD(TestProperties)
        {
            Vector2<float, float> vec(3.0f, 4.0f);

            Assert::AreEqual(vec.X(), 3.0f, 0.0001, L"X Property Test failed.");
            Assert::AreEqual(vec.Y(), 4.0f, 0.0001, L"Y Property Test failed.");
        }
    };

    TEST_CLASS(containerTests)
    {
    public:

        TEST_METHOD(TestPushBack)
        {
            container<int> cont;
            cont.push_back(1);
            cont.push_back(2);

            Assert::AreEqual(cont[0], 1);
            Assert::AreEqual(cont[1], 2);
        }

        TEST_METHOD(TestSizeAndCapacity)
        {
            container<int> cont;
            Assert::IsTrue(cont.empty());
            Assert::AreEqual(cont.getSize(), static_cast<size_t>(0));
            Assert::AreEqual(cont.getCapacity(), static_cast<size_t>(0));

            cont.push_back(1);
            Assert::IsFalse(cont.empty());
            Assert::AreEqual(cont.getSize(), static_cast<size_t>(1));
            Assert::AreNotEqual(cont.getCapacity(), static_cast<size_t>(0));
        }

        TEST_METHOD(TestIndexOutOfRange)
        {
            container<int> cont;
            try {
                int value = cont[0];
            }
            catch (std::out_of_range& e) {
                Assert::IsTrue(strcmp(e.what(), "Index out of range") == 0);
            }
        }
    };
}
