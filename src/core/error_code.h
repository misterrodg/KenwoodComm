#ifndef ERROR_CODE_H
#define ERROR_CODE_H

#include <string_view>

namespace core {

enum class ErrorCode {
    CommandError,
    CommandDisabledSafeMode,
    CommandNoParameterAllowed,
    CommandNotAvailable,
    CommandNotImplemented,
    EmptyResponse,
    FunctionNotAvailable,
    InvalidCommand,
    InvalidCallSign,
    InvalidCommandPrefix,
    InvalidFormat,
    InvalidFrequency,
    InvalidFrequencyUnit,
    InvalidFunction,
    InvalidMemoryBank,
    InvalidMemoryChannel,
    InvalidMode,
    InvalidPassband,
    InvalidRitFrequency,
    InvalidStepFrequency,
    InvalidSwitchParameter,
    InvalidToneFrequency,
    MissingTerminator,
    ModeNotAvailable,
    ParameterEmpty,
    ParameterInvalid,
    RadioError,
    SerialConfigurationFailed,
    SerialOpenFailed,
    SerialWriteFailed,
    ValueOutOfRange,
};

inline std::string_view ToString(ErrorCode code) {
    switch (code) {
    case ErrorCode::CommandError:
        return "COMMAND_ERROR";
    case ErrorCode::CommandDisabledSafeMode:
        return "CMD_DISABLED_SAFE_MODE";
    case ErrorCode::CommandNoParameterAllowed:
        return "CMD_NO_PARAMETER_ALLOWED";
    case ErrorCode::CommandNotAvailable:
        return "CMD_NOT_AVAILABLE";
    case ErrorCode::CommandNotImplemented:
        return "CMD_NOT_IMPLEMENTED";
    case ErrorCode::EmptyResponse:
        return "EMPTY_RESPONSE";
    case ErrorCode::FunctionNotAvailable:
        return "FUNCTION_NOT_AVAILABLE";
    case ErrorCode::InvalidCommand:
        return "INVALID_COMMAND";
    case ErrorCode::InvalidCallSign:
        return "INVALID_CALL_SIGN";
    case ErrorCode::InvalidCommandPrefix:
        return "INVALID_COMMAND_PREFIX";
    case ErrorCode::InvalidFormat:
        return "INVALID_FORMAT";
    case ErrorCode::InvalidFrequency:
        return "INVALID_FREQUENCY";
    case ErrorCode::InvalidFrequencyUnit:
        return "INVALID_FREQUENCY_UNIT";
    case ErrorCode::InvalidFunction:
        return "INVALID_FUNCTION";
    case ErrorCode::InvalidMemoryBank:
        return "INVALID_MEMORY_BANK";
    case ErrorCode::InvalidMemoryChannel:
        return "INVALID_MEMORY_CHANNEL";
    case ErrorCode::InvalidMode:
        return "INVALID_MODE";
    case ErrorCode::InvalidPassband:
        return "INVALID_PASSBAND";
    case ErrorCode::InvalidRitFrequency:
        return "INVALID_RIT_FREQUENCY";
    case ErrorCode::InvalidStepFrequency:
        return "INVALID_STEP_FREQUENCY";
    case ErrorCode::InvalidSwitchParameter:
        return "INVALID_SWITCH_PARAMETER";
    case ErrorCode::InvalidToneFrequency:
        return "INVALID_TONE_FREQUENCY";
    case ErrorCode::MissingTerminator:
        return "MISSING_TERMINATOR";
    case ErrorCode::ModeNotAvailable:
        return "MODE_NOT_AVAILABLE";
    case ErrorCode::ParameterEmpty:
        return "PARAM_EMPTY";
    case ErrorCode::ParameterInvalid:
        return "PARAM_INVALID";
    case ErrorCode::RadioError:
        return "RADIO_ERROR";
    case ErrorCode::SerialConfigurationFailed:
        return "SERIAL_CONFIGURATION_FAILED";
    case ErrorCode::SerialOpenFailed:
        return "SERIAL_OPEN_FAILED";
    case ErrorCode::SerialWriteFailed:
        return "SERIAL_WRITE_FAILED";
    case ErrorCode::ValueOutOfRange:
        return "VALUE_OUT_OF_RANGE";
    }

    return "COMMAND_ERROR";
}

} // namespace core

#endif