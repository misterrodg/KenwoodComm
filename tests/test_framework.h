#pragma once

#include <functional>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

struct TestFailure {
    std::string message;
};

struct TestCase {
    std::string suite;
    std::string name;
    std::function<void()> fn;
};

class TestRegistry {
public:
    static TestRegistry& instance() {
        static TestRegistry reg;
        return reg;
    }

    void add(const char* suite, const char* name, std::function<void()> fn) {
        tests_.push_back({suite, name, fn});
    }

    int runAll() {
        int passed = 0, failed = 0;
        std::string currentSuite;
        for (const auto& t : tests_) {
            if (t.suite != currentSuite) {
                currentSuite = t.suite;
                std::cout << "\n[" << currentSuite << "]\n";
            }
            try {
                t.fn();
                std::cout << "  PASS  " << t.name << "\n";
                ++passed;
            } catch (const TestFailure& e) {
                std::cout << "  FAIL  " << t.name << "\n";
                std::cout << "        " << e.message << "\n";
                ++failed;
            } catch (const std::exception& e) {
                std::cout << "  FAIL  " << t.name << "\n";
                std::cout << "        Exception: " << e.what() << "\n";
                ++failed;
            }
        }
        std::cout << "\n----------------------------------------\n";
        std::cout << passed << " passed, " << failed << " failed\n";
        return (failed == 0) ? 0 : 1;
    }

private:
    std::vector<TestCase> tests_;
};

struct TestRegistrar {
    TestRegistrar(const char* suite, const char* name,
                  std::function<void()> fn) {
        TestRegistry::instance().add(suite, name, fn);
    }
};

// ---------------------------------------------------------------------------
// TEST macro
// ---------------------------------------------------------------------------
#define TEST(suite, name)                                                      \
    static void test_##suite##_##name();                                       \
    static TestRegistrar registrar_##suite##_##name(#suite, #name,             \
                                                    test_##suite##_##name);    \
    static void test_##suite##_##name()

// ---------------------------------------------------------------------------
// Internal helper: convert any value to a string for assertion messages.
// Falls back to the numeric value for enum classes, which have no operator<<.
// ---------------------------------------------------------------------------
namespace test_detail {
template <typename T>
std::string debugStr(const T& v) {
    if constexpr (std::is_enum_v<T>) {
        return std::to_string(
            static_cast<std::underlying_type_t<T>>(v));
    } else {
        std::ostringstream _oss;
        _oss << v;
        return _oss.str();
    }
}
} // namespace test_detail

// ---------------------------------------------------------------------------
// Assertion macros
// ---------------------------------------------------------------------------
#define ASSERT_TRUE(expr)                                                      \
    do {                                                                       \
        if (!(expr)) {                                                         \
            std::ostringstream _oss;                                           \
            _oss << "ASSERT_TRUE(" #expr ") failed  [" __FILE__ ":"            \
                 << __LINE__ << "]";                                           \
            throw TestFailure{_oss.str()};                                     \
        }                                                                      \
    } while (0)

#define ASSERT_FALSE(expr)                                                     \
    do {                                                                       \
        if (expr) {                                                            \
            std::ostringstream _oss;                                           \
            _oss << "ASSERT_FALSE(" #expr ") failed  [" __FILE__ ":"           \
                 << __LINE__ << "]";                                           \
            throw TestFailure{_oss.str()};                                     \
        }                                                                      \
    } while (0)

#define ASSERT_EQ(a, b)                                                        \
    do {                                                                       \
        auto _a = (a);                                                         \
        auto _b = (b);                                                         \
        if (!(_a == _b)) {                                                     \
            std::ostringstream _oss;                                           \
            _oss << "ASSERT_EQ(" #a ", " #b ") failed: got ("                  \
                 << test_detail::debugStr(_a) << ") vs ("                      \
                 << test_detail::debugStr(_b) << ")  [" __FILE__ ":"           \
                 << __LINE__ << "]";                                           \
            throw TestFailure{_oss.str()};                                     \
        }                                                                      \
    } while (0)

#define ASSERT_NE(a, b)                                                        \
    do {                                                                       \
        auto _a = (a);                                                         \
        auto _b = (b);                                                         \
        if (_a == _b) {                                                        \
            std::ostringstream _oss;                                           \
            _oss << "ASSERT_NE(" #a ", " #b ") failed: both equal ("           \
                 << test_detail::debugStr(_a) << ")  [" __FILE__ ":"           \
                 << __LINE__ << "]";                                           \
            throw TestFailure{_oss.str()};                                     \
        }                                                                      \
    } while (0)

#define ASSERT_STREQ(a, b)                                                     \
    do {                                                                       \
        std::string _a = (a);                                                  \
        std::string _b = (b);                                                  \
        if (_a != _b) {                                                        \
            std::ostringstream _oss;                                           \
            _oss << "ASSERT_STREQ(" #a ", " #b ") failed: got \"" << _a        \
                 << "\" vs \"" << _b << "\"  [" __FILE__ ":" << __LINE__       \
                 << "]";                                                       \
            throw TestFailure{_oss.str()};                                     \
        }                                                                      \
    } while (0)
