#include "command_dispatcher.h"
#include "command/command_prefix.h"
#include "core/parameter_validator.h"
#include "radio_profile.h"
#include "session.h"

CommandDispatcher::CommandDispatcher(Session* session,
                                     RadioProfile* radioProfile)
    : session(session), radioProfile(radioProfile) {
    // AI: Auto Information - requires parameter
    registry[CommandPrefix::CommandPrefixEnum::AI] = {
        CommandMetaData::REQUIRED_PARAMETER, false, false,
        [](Session* s) -> CommandResult {
            CommandResult result = s->ai.SetSwitch(s->lastParameter);
            if (!result.OK())
                return result;
            s->write(s->ai.ToCommand());
            return OK();
        }};

    // AT: Antenna Tuner - no parameter
    registry[CommandPrefix::CommandPrefixEnum::AT] = {
        CommandMetaData::NO_PARAMETER, false, false,
        [](Session* s) -> CommandResult {
            s->write(s->at.ToCommand());
            return OK();
        }};

    // BY: Band Select - no parameter, expects response
    registry[CommandPrefix::CommandPrefixEnum::BY] = {
        CommandMetaData::NO_PARAMETER, true, false,
        [](Session* s) -> CommandResult {
            s->write(s->by.ToCommand(), true);
            return OK();
        }};

    // CN: CTCSS Tone Number - requires parameter
    registry[CommandPrefix::CommandPrefixEnum::CN] = {
        CommandMetaData::REQUIRED_PARAMETER, false, false,
        [](Session* s) -> CommandResult {
            CommandResult result = s->cn.SetTone(s->lastParameter);
            if (!result.OK())
                return result;
            s->write(s->cn.ToCommand());
            return OK();
        }};

    // CT: CTCSS Tone - requires parameter or read status
    registry[CommandPrefix::CommandPrefixEnum::CT] = {
        CommandMetaData::OPTIONAL_PARAMETER, false, false,
        [](Session* s) -> CommandResult {
            if (s->lastParameter.empty()) {
                s->write(s->ct.ToCommand(true), true);
            } else {
                CommandResult result = s->ct.SetSwitch(s->lastParameter);
                if (!result.OK())
                    return result;
                s->write(s->ct.ToCommand());
            }
            return OK();
        }};

    // DI: Display Information - no parameter
    registry[CommandPrefix::CommandPrefixEnum::DI] = {
        CommandMetaData::NO_PARAMETER, false, false,
        [](Session* s) -> CommandResult {
            s->write(s->di.ToCommand());
            return OK();
        }};

    // DS: Display Select - optional parameter
    registry[CommandPrefix::CommandPrefixEnum::DS] = {
        CommandMetaData::OPTIONAL_PARAMETER, false, false,
        [](Session* s) -> CommandResult {
            if (s->lastParameter.empty()) {
                s->write(s->ds.ToCommand(true), true);
            } else {
                CommandResult result = s->ds.SetSwitch(s->lastParameter);
                if (!result.OK())
                    return result;
                s->write(s->ds.ToCommand());
            }
            return OK();
        }};

    // DN: Down - no parameter
    registry[CommandPrefix::CommandPrefixEnum::DN] = {
        CommandMetaData::NO_PARAMETER, false, false,
        [](Session* s) -> CommandResult {
            s->write(s->dn.ToCommand());
            return OK();
        }};

    // FA: Frequency A - optional parameter, read status supported
    registry[CommandPrefix::CommandPrefixEnum::FA] = {
        CommandMetaData::OPTIONAL_PARAMETER, false, false,
        [](Session* s) -> CommandResult {
            if (s->lastParameter.empty()) {
                s->write(s->fa.ToCommand(true), true);
            } else {
                CommandResult result = s->fa.SetFrequency(s->lastParameter);
                if (!result.OK())
                    return result;
                s->write(s->fa.ToCommand());
            }
            return OK();
        }};

    // FB: Frequency B - optional parameter, read status supported
    registry[CommandPrefix::CommandPrefixEnum::FB] = {
        CommandMetaData::OPTIONAL_PARAMETER, false, false,
        [](Session* s) -> CommandResult {
            if (s->lastParameter.empty()) {
                s->write(s->fb.ToCommand(true), true);
            } else {
                CommandResult result = s->fb.SetFrequency(s->lastParameter);
                if (!result.OK())
                    return result;
                s->write(s->fb.ToCommand());
            }
            return OK();
        }};

    // FN: Function - requires parameter
    registry[CommandPrefix::CommandPrefixEnum::FN] = {
        CommandMetaData::REQUIRED_PARAMETER, false, false,
        [](Session* s) -> CommandResult {
            CommandResult result = s->fn.SetFunction(
                s->radioProfile->GetModelNumber(), s->lastParameter);
            if (!result.OK())
                return result;
            s->write(s->fn.ToCommand());
            return OK();
        }};

    // HD: Handicap - optional parameter
    registry[CommandPrefix::CommandPrefixEnum::HD] = {
        CommandMetaData::OPTIONAL_PARAMETER, false, false,
        [](Session* s) -> CommandResult {
            if (s->lastParameter.empty()) {
                s->write(s->hd.ToCommand(true), true);
            } else {
                CommandResult result = s->hd.SetSwitch(s->lastParameter);
                if (!result.OK())
                    return result;
                s->write(s->hd.ToCommand());
            }
            return OK();
        }};

    // ID: Identification - no parameter, expects response
    registry[CommandPrefix::CommandPrefixEnum::ID] = {
        CommandMetaData::NO_PARAMETER, true, false,
        [](Session* s) -> CommandResult {
            s->write(s->id.ToCommand(), true);
            return OK();
        }};

    // IF: Information - no parameter, expects response
    registry[CommandPrefix::CommandPrefixEnum::IF] = {
        CommandMetaData::NO_PARAMETER, true, false,
        [](Session* s) -> CommandResult {
            s->write(s->information.ToCommand(), true);
            return OK();
        }};

    // LK: Lock - optional parameter
    registry[CommandPrefix::CommandPrefixEnum::LK] = {
        CommandMetaData::OPTIONAL_PARAMETER, false, false,
        [](Session* s) -> CommandResult {
            if (s->lastParameter.empty()) {
                s->write(s->lk.ToCommand(true), true);
            } else {
                CommandResult result = s->lk.SetSwitch(s->lastParameter);
                if (!result.OK())
                    return result;
                s->write(s->lk.ToCommand());
            }
            return OK();
        }};

    // LO: Local - no parameter
    registry[CommandPrefix::CommandPrefixEnum::LO] = {
        CommandMetaData::NO_PARAMETER, false, false,
        [](Session* s) -> CommandResult {
            s->write(s->lo.ToCommand());
            return OK();
        }};

    // LT: Clarifier TX - optional parameter
    registry[CommandPrefix::CommandPrefixEnum::LT] = {
        CommandMetaData::OPTIONAL_PARAMETER, false, false,
        [](Session* s) -> CommandResult {
            if (s->lastParameter.empty()) {
                s->write(s->lt.ToCommand(true), true);
            } else {
                CommandResult result = s->lt.SetSwitch(s->lastParameter);
                if (!result.OK())
                    return result;
                s->write(s->lt.ToCommand());
            }
            return OK();
        }};

    // MC: Memory Channel - requires parameter
    registry[CommandPrefix::CommandPrefixEnum::MC] = {
        CommandMetaData::REQUIRED_PARAMETER, false, false,
        [](Session* s) -> CommandResult {
            CommandResult result = s->mc.SetMemory(
                s->radioProfile->GetModelNumber(), s->lastParameter);
            if (!result.OK())
                return result;
            s->write(s->mc.ToCommand());
            return OK();
        }};

    // MD: Mode - requires parameter
    registry[CommandPrefix::CommandPrefixEnum::MD] = {
        CommandMetaData::REQUIRED_PARAMETER, false, false,
        [](Session* s) -> CommandResult {
            CommandResult result = s->md.SetMode(
                s->radioProfile->GetModelNumber(), s->lastParameter);
            if (!result.OK())
                return result;
            s->write(s->md.ToCommand());
            return OK();
        }};

    // MS: Monitor - optional parameter
    registry[CommandPrefix::CommandPrefixEnum::MS] = {
        CommandMetaData::OPTIONAL_PARAMETER, false, false,
        [](Session* s) -> CommandResult {
            if (s->lastParameter.empty()) {
                s->write(s->ms.ToCommand(true), true);
            } else {
                CommandResult result = s->ms.SetSwitch(s->lastParameter);
                if (!result.OK())
                    return result;
                s->write(s->ms.ToCommand());
            }
            return OK();
        }};

    // MT: Monitor Tone - optional parameter
    registry[CommandPrefix::CommandPrefixEnum::MT] = {
        CommandMetaData::OPTIONAL_PARAMETER, false, false,
        [](Session* s) -> CommandResult {
            if (s->lastParameter.empty()) {
                s->write(s->mt.ToCommand(true), true);
            } else {
                CommandResult result = s->mt.SetSwitch(s->lastParameter);
                if (!result.OK())
                    return result;
                s->write(s->mt.ToCommand());
            }
            return OK();
        }};

    // RC: RIT Clear - no parameter
    registry[CommandPrefix::CommandPrefixEnum::RC] = {
        CommandMetaData::NO_PARAMETER, false, false,
        [](Session* s) -> CommandResult {
            s->write(s->rc.ToCommand());
            return OK();
        }};

    // RD: RIT Decrement - no parameter
    registry[CommandPrefix::CommandPrefixEnum::RD] = {
        CommandMetaData::NO_PARAMETER, false, false,
        [](Session* s) -> CommandResult {
            s->write(s->rd.ToCommand());
            return OK();
        }};

    // RT: RIT/XIT Toggle - requires parameter
    registry[CommandPrefix::CommandPrefixEnum::RT] = {
        CommandMetaData::REQUIRED_PARAMETER, false, false,
        [](Session* s) -> CommandResult {
            CommandResult result = s->rt.SetSwitch(s->lastParameter);
            if (!result.OK())
                return result;
            s->write(s->rt.ToCommand());
            return OK();
        }};

    // RU: RIT Increment - no parameter
    registry[CommandPrefix::CommandPrefixEnum::RU] = {
        CommandMetaData::NO_PARAMETER, false, false,
        [](Session* s) -> CommandResult {
            s->write(s->ru.ToCommand());
            return OK();
        }};

    // RX: Receive - no parameter, expects response
    registry[CommandPrefix::CommandPrefixEnum::RX] = {
        CommandMetaData::NO_PARAMETER, false, false,
        [](Session* s) -> CommandResult {
            s->write(s->rx.ToCommand());
            return OK();
        }};

    // SC: Scan - requires parameter
    registry[CommandPrefix::CommandPrefixEnum::SC] = {
        CommandMetaData::REQUIRED_PARAMETER, false, false,
        [](Session* s) -> CommandResult {
            CommandResult result = s->sc.SetSwitch(s->lastParameter);
            if (!result.OK())
                return result;
            s->write(s->sc.ToCommand());
            return OK();
        }};

    // SP: Speaker - requires parameter
    registry[CommandPrefix::CommandPrefixEnum::SP] = {
        CommandMetaData::REQUIRED_PARAMETER, false, false,
        [](Session* s) -> CommandResult {
            CommandResult result = s->sp.SetSwitch(s->lastParameter);
            if (!result.OK())
                return result;
            s->write(s->sp.ToCommand());
            return OK();
        }};

    // ST: Status - requires parameter
    registry[CommandPrefix::CommandPrefixEnum::ST] = {
        CommandMetaData::REQUIRED_PARAMETER, false, false,
        [](Session* s) -> CommandResult {
            CommandResult result = s->st.SetSwitch(s->lastParameter);
            if (!result.OK())
                return result;
            s->write(s->st.ToCommand());
            return OK();
        }};

    // TN: Tone Number - requires parameter
    registry[CommandPrefix::CommandPrefixEnum::TN] = {
        CommandMetaData::REQUIRED_PARAMETER, false, false,
        [](Session* s) -> CommandResult {
            CommandResult result = s->tn.SetTone(s->lastParameter);
            if (!result.OK())
                return result;
            s->write(s->tn.ToCommand());
            return OK();
        }};

    // TO: Tone - requires parameter
    registry[CommandPrefix::CommandPrefixEnum::TO] = {
        CommandMetaData::REQUIRED_PARAMETER, false, false,
        [](Session* s) -> CommandResult {
            CommandResult result = s->to.SetSwitch(s->lastParameter);
            if (!result.OK())
                return result;
            s->write(s->to.ToCommand());
            return OK();
        }};

    // TX: Transmit - no parameter, DISABLED in safe mode, expects response
    registry[CommandPrefix::CommandPrefixEnum::TX] = {
        CommandMetaData::NO_PARAMETER, false, true,
        [](Session* s) -> CommandResult {
            s->write(s->tx.ToCommand());
            return OK();
        }};

    // UP: Up - no parameter
    registry[CommandPrefix::CommandPrefixEnum::UP] = {
        CommandMetaData::NO_PARAMETER, false, false,
        [](Session* s) -> CommandResult {
            s->write(s->up.ToCommand());
            return OK();
        }};

    // VR: VFO RX - no parameter
    registry[CommandPrefix::CommandPrefixEnum::VR] = {
        CommandMetaData::NO_PARAMETER, false, false,
        [](Session* s) -> CommandResult {
            s->write(s->vr.ToCommand());
            return OK();
        }};

    // XT: External Frequency Reference - requires parameter
    registry[CommandPrefix::CommandPrefixEnum::XT] = {
        CommandMetaData::REQUIRED_PARAMETER, false, false,
        [](Session* s) -> CommandResult {
            CommandResult result = s->xt.SetSwitch(s->lastParameter);
            if (!result.OK())
                return result;
            s->write(s->xt.ToCommand());
            return OK();
        }};
}

CommandResult
CommandDispatcher::Dispatch(CommandPrefix::CommandPrefixEnum command,
                            const std::string& param) {
    if (!radioProfile->IsCommandAvailable(command)) {
        std::string commandString = CommandPrefix::CommandToString(command);
        return Error("CMD_NOT_AVAILABLE", "SerialCommand \"" + commandString +
                                              "\" not available on this model");
    }

    auto it = registry.find(command);

    if (it == registry.end()) {
        return Error("CMD_NOT_IMPLEMENTED", "SerialCommand not implemented");
    }

    const CommandMetaData& metadata = it->second;

    if (metadata.disabledInSafeMode && session->safeMode) {
        std::string commandString = CommandPrefix::CommandToString(command);
        return Error("CMD_DISABLED_SAFE_MODE", "SerialCommand \"" +
                                                   commandString +
                                                   "\" disabled in SAFE MODE");
    }

    if (metadata.parameterMode == CommandMetaData::REQUIRED_PARAMETER) {
        core::Result<void> validation =
            ParameterValidator::validateNotEmpty(param, "parameter");
        if (!validation.OK()) {
            std::string commandString = CommandPrefix::CommandToString(command);
            return Error(validation.error().code,
                         "SerialCommand \"" + commandString +
                             "\" requires a parameter");
        }
    }

    if (metadata.parameterMode == CommandMetaData::NO_PARAMETER &&
        !param.empty()) {
        std::string commandString = CommandPrefix::CommandToString(command);
        return Error("CMD_NO_PARAMETER_ALLOWED",
                     "SerialCommand \"" + commandString +
                         "\" accepts no parameters. Ignoring \"" + param +
                         "\" and sending standard " + commandString +
                         " command");
    }

    session->lastParameter = param;

    return metadata.handler(session);
}
