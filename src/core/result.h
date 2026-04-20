#ifndef RESULT_H
#define RESULT_H

#include <algorithm>
#include <string>
#include <variant>

namespace core {

struct Error {
    std::string code;
    std::string message;
};

template <typename T> class Result {
public:
    Result(const T& value) : value_(value) {
    }
    Result(T&& value) : value_(std::move(value)) {
    }
    Result(const Error& error) : value_(error) {
    }
    Result(Error&& error) : value_(std::move(error)) {
    }

    bool OK() const {
        return std::holds_alternative<T>(value_);
    }
    const T& value() const {
        return std::get<T>(value_);
    }
    const Error& error() const {
        return std::get<Error>(value_);
    }

private:
    std::variant<T, Error> value_;
};

// SPECIALIZATION: void
template <> class Result<void> {
public:
    Result() : value_(std::monostate{}) {
    }
    Result(const Error& error) : value_(error) {
    }
    Result(Error&& error) : value_(std::move(error)) {
    }

    bool OK() const {
        return std::holds_alternative<std::monostate>(value_);
    }
    void value() const {
    }
    const Error& error() const {
        return std::get<Error>(value_);
    }

private:
    std::variant<std::monostate, Error> value_;
};

} // namespace core

#endif
