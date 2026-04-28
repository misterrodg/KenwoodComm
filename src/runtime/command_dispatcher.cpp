#include "command_dispatcher.h"
#include "command/command_prefix.h"
#include "radio_profile.h"
#include "session.h"

CommandDispatcher::CommandDispatcher(Session* session,
                                     RadioProfile* radioProfile)
    : session(session), radioProfile(radioProfile) {
    // AI: Auto Information - requires parameter
    registry[CommandPrefix::CommandPrefixEnum::AI] = {
        CommandMetaData::SafeMode::ALLOWED,
        [](Session* s) -> CommandBase* { return &s->ai; },
        [this](Session* s) -> CommandResult {
            return dispatchSet(s->ai, s->lastParameter);
        }};

    // AT: Antenna Tuner - no parameter
    registry[CommandPrefix::CommandPrefixEnum::AT] = {
        CommandMetaData::SafeMode::ALLOWED,
        [](Session* s) -> CommandBase* { return &s->at; },
        [](Session* s) -> CommandResult {
            s->write(s->at.ToCommand());
            return OK();
        }};

    // BY: Band Select - no parameter, expects response
    registry[CommandPrefix::CommandPrefixEnum::BY] = {
        CommandMetaData::SafeMode::ALLOWED,
        [](Session* s) -> CommandBase* { return &s->by; },
        [](Session* s) -> CommandResult {
            s->write(s->by.ToCommand(), true);
            return OK();
        }};

    // CN: CTCSS Tone Number - requires parameter or read status
    registry[CommandPrefix::CommandPrefixEnum::CN] = {
        CommandMetaData::SafeMode::ALLOWED,
        [](Session* s) -> CommandBase* { return &s->cn; },
        [this](Session* s) -> CommandResult {
            if (s->lastParameter.empty()) {
                return dispatchRead(s->cn);
            }

            return dispatchSet(s->cn, s->lastParameter);
        }};

    // CT: CTCSS Tone - requires parameter or read status
    registry[CommandPrefix::CommandPrefixEnum::CT] = {
        CommandMetaData::SafeMode::ALLOWED,
        [](Session* s) -> CommandBase* { return &s->ct; },
        [this](Session* s) -> CommandResult {
            if (s->lastParameter.empty()) {
                return dispatchRead(s->ct);
            }

            return dispatchSet(s->ct, s->lastParameter);
        }};

    // DC: Destination Code - optional parameter
    registry[CommandPrefix::CommandPrefixEnum::DC] = {
        CommandMetaData::SafeMode::ALLOWED,
        [](Session* s) -> CommandBase* { return &s->dc; },
        [this](Session* s) -> CommandResult {
            if (s->lastParameter.empty()) {
                return dispatchRead(s->dc);
            }

            return dispatchSet(s->dc, s->lastParameter);
        }};

    // DI: Display Information - no parameter
    registry[CommandPrefix::CommandPrefixEnum::DI] = {
        CommandMetaData::SafeMode::ALLOWED,
        [](Session* s) -> CommandBase* { return &s->di; },
        [](Session* s) -> CommandResult {
            s->write(s->di.ToCommand());
            return OK();
        }};

    // DS: Display Select - optional parameter
    registry[CommandPrefix::CommandPrefixEnum::DS] = {
        CommandMetaData::SafeMode::ALLOWED,
        [](Session* s) -> CommandBase* { return &s->ds; },
        [this](Session* s) -> CommandResult {
            if (s->lastParameter.empty()) {
                return dispatchRead(s->ds);
            }

            return dispatchSet(s->ds, s->lastParameter);
        }};

    // DN: Down - no parameter
    registry[CommandPrefix::CommandPrefixEnum::DN] = {
        CommandMetaData::SafeMode::ALLOWED,
        [](Session* s) -> CommandBase* { return &s->dn; },
        [](Session* s) -> CommandResult {
            s->write(s->dn.ToCommand());
            return OK();
        }};

    // FA: Frequency A - optional parameter, read status supported
    registry[CommandPrefix::CommandPrefixEnum::FA] = {
        CommandMetaData::SafeMode::ALLOWED,
        [](Session* s) -> CommandBase* { return &s->fa; },
        [this](Session* s) -> CommandResult {
            if (s->lastParameter.empty()) {
                return dispatchRead(s->fa);
            }

            return dispatchSet(s->fa, s->lastParameter);
        }};

    // FB: Frequency B - optional parameter, read status supported
    registry[CommandPrefix::CommandPrefixEnum::FB] = {
        CommandMetaData::SafeMode::ALLOWED,
        [](Session* s) -> CommandBase* { return &s->fb; },
        [this](Session* s) -> CommandResult {
            if (s->lastParameter.empty()) {
                return dispatchRead(s->fb);
            }

            return dispatchSet(s->fb, s->lastParameter);
        }};

    // FN: Function - requires parameter
    registry[CommandPrefix::CommandPrefixEnum::FN] = {
        CommandMetaData::SafeMode::ALLOWED,
        [](Session* s) -> CommandBase* { return &s->fn; },
        [this](Session* s) -> CommandResult {
            s->fn.setModelNumber(s->radioProfile->GetModelNumber());
            return dispatchSet(s->fn, s->lastParameter);
        }};

    // HD: Handicap - optional parameter
    registry[CommandPrefix::CommandPrefixEnum::HD] = {
        CommandMetaData::SafeMode::ALLOWED,
        [](Session* s) -> CommandBase* { return &s->hd; },
        [this](Session* s) -> CommandResult {
            if (s->lastParameter.empty()) {
                return dispatchRead(s->hd);
            }

            return dispatchSet(s->hd, s->lastParameter);
        }};

    // ID: Identification - no parameter, expects response
    registry[CommandPrefix::CommandPrefixEnum::ID] = {
        CommandMetaData::SafeMode::ALLOWED,
        [](Session* s) -> CommandBase* { return &s->id; },
        [](Session* s) -> CommandResult {
            s->write(s->id.ToCommand(), true);
            return OK();
        }};

    // IF: Information - no parameter, expects response
    registry[CommandPrefix::CommandPrefixEnum::IF] = {
        CommandMetaData::SafeMode::ALLOWED,
        [](Session* s) -> CommandBase* { return &s->information; },
        [](Session* s) -> CommandResult {
            s->write(s->information.ToCommand(), true);
            return OK();
        }};

    // LK: Lock - optional parameter
    registry[CommandPrefix::CommandPrefixEnum::LK] = {
        CommandMetaData::SafeMode::ALLOWED,
        [](Session* s) -> CommandBase* { return &s->lk; },
        [this](Session* s) -> CommandResult {
            if (s->lastParameter.empty()) {
                return dispatchRead(s->lk);
            }

            return dispatchSet(s->lk, s->lastParameter);
        }};

    // LO: Local - no parameter
    registry[CommandPrefix::CommandPrefixEnum::LO] = {
        CommandMetaData::SafeMode::ALLOWED,
        [](Session* s) -> CommandBase* { return &s->lo; },
        [](Session* s) -> CommandResult {
            s->write(s->lo.ToCommand());
            return OK();
        }};

    // LT: Clarifier TX - optional parameter
    registry[CommandPrefix::CommandPrefixEnum::LT] = {
        CommandMetaData::SafeMode::ALLOWED,
        [](Session* s) -> CommandBase* { return &s->lt; },
        [this](Session* s) -> CommandResult {
            if (s->lastParameter.empty()) {
                return dispatchRead(s->lt);
            }

            return dispatchSet(s->lt, s->lastParameter);
        }};

    // MC: Memory Channel - requires parameter
    registry[CommandPrefix::CommandPrefixEnum::MC] = {
        CommandMetaData::SafeMode::ALLOWED,
        [](Session* s) -> CommandBase* { return &s->mc; },
        [this](Session* s) -> CommandResult {
            s->mc.setModelNumber(s->radioProfile->GetModelNumber());
            return dispatchSet(s->mc, s->lastParameter);
        }};

    // MD: Mode - requires parameter
    registry[CommandPrefix::CommandPrefixEnum::MD] = {
        CommandMetaData::SafeMode::ALLOWED,
        [](Session* s) -> CommandBase* { return &s->md; },
        [this](Session* s) -> CommandResult {
            s->md.setModelNumber(s->radioProfile->GetModelNumber());
            return dispatchSet(s->md, s->lastParameter);
        }};

    // MS: Monitor - optional parameter
    registry[CommandPrefix::CommandPrefixEnum::MS] = {
        CommandMetaData::SafeMode::ALLOWED,
        [](Session* s) -> CommandBase* { return &s->ms; },
        [this](Session* s) -> CommandResult {
            if (s->lastParameter.empty()) {
                return dispatchRead(s->ms);
            }

            return dispatchSet(s->ms, s->lastParameter);
        }};

    // MT: Monitor Tone - optional parameter
    registry[CommandPrefix::CommandPrefixEnum::MT] = {
        CommandMetaData::SafeMode::ALLOWED,
        [](Session* s) -> CommandBase* { return &s->mt; },
        [this](Session* s) -> CommandResult {
            if (s->lastParameter.empty()) {
                return dispatchRead(s->mt);
            }

            return dispatchSet(s->mt, s->lastParameter);
        }};

    // RC: RIT Clear - no parameter
    registry[CommandPrefix::CommandPrefixEnum::RC] = {
        CommandMetaData::SafeMode::ALLOWED,
        [](Session* s) -> CommandBase* { return &s->rc; },
        [](Session* s) -> CommandResult {
            s->write(s->rc.ToCommand());
            return OK();
        }};

    // RD: RIT Decrement - no parameter
    registry[CommandPrefix::CommandPrefixEnum::RD] = {
        CommandMetaData::SafeMode::ALLOWED,
        [](Session* s) -> CommandBase* { return &s->rd; },
        [](Session* s) -> CommandResult {
            s->write(s->rd.ToCommand());
            return OK();
        }};

    // RT: RIT/XIT Toggle - requires parameter
    registry[CommandPrefix::CommandPrefixEnum::RT] = {
        CommandMetaData::SafeMode::ALLOWED,
        [](Session* s) -> CommandBase* { return &s->rt; },
        [this](Session* s) -> CommandResult {
            return dispatchSet(s->rt, s->lastParameter);
        }};

    // RU: RIT Increment - no parameter
    registry[CommandPrefix::CommandPrefixEnum::RU] = {
        CommandMetaData::SafeMode::ALLOWED,
        [](Session* s) -> CommandBase* { return &s->ru; },
        [](Session* s) -> CommandResult {
            s->write(s->ru.ToCommand());
            return OK();
        }};

    // RX: Receive - no parameter, expects response
    registry[CommandPrefix::CommandPrefixEnum::RX] = {
        CommandMetaData::SafeMode::ALLOWED,
        [](Session* s) -> CommandBase* { return &s->rx; },
        [](Session* s) -> CommandResult {
            s->write(s->rx.ToCommand());
            return OK();
        }};

    // SC: Scan - requires parameter
    registry[CommandPrefix::CommandPrefixEnum::SC] = {
        CommandMetaData::SafeMode::ALLOWED,
        [](Session* s) -> CommandBase* { return &s->sc; },
        [this](Session* s) -> CommandResult {
            return dispatchSet(s->sc, s->lastParameter);
        }};

    // SP: Speaker - requires parameter
    registry[CommandPrefix::CommandPrefixEnum::SP] = {
        CommandMetaData::SafeMode::ALLOWED,
        [](Session* s) -> CommandBase* { return &s->sp; },
        [this](Session* s) -> CommandResult {
            return dispatchSet(s->sp, s->lastParameter);
        }};

    // ST: Status - requires parameter
    registry[CommandPrefix::CommandPrefixEnum::ST] = {
        CommandMetaData::SafeMode::ALLOWED,
        [](Session* s) -> CommandBase* { return &s->st; },
        [this](Session* s) -> CommandResult {
            return dispatchSet(s->st, s->lastParameter);
        }};

    // TN: Tone Number - requires parameter
    registry[CommandPrefix::CommandPrefixEnum::TN] = {
        CommandMetaData::SafeMode::ALLOWED,
        [](Session* s) -> CommandBase* { return &s->tn; },
        [](Session* s) -> CommandResult {
            CommandResult result = s->tn.SetTone(s->lastParameter);
            if (!result.OK())
                return result;
            s->write(s->tn.ToCommand());
            return OK();
        }};

    // TO: Tone - requires parameter
    registry[CommandPrefix::CommandPrefixEnum::TO] = {
        CommandMetaData::SafeMode::ALLOWED,
        [](Session* s) -> CommandBase* { return &s->to; },
        [this](Session* s) -> CommandResult {
            return dispatchSet(s->to, s->lastParameter);
        }};

    // TX: Transmit - no parameter, DISABLED in safe mode, expects response
    registry[CommandPrefix::CommandPrefixEnum::TX] = {
        CommandMetaData::SafeMode::DISABLED,
        [](Session* s) -> CommandBase* { return &s->tx; },
        [](Session* s) -> CommandResult {
            s->write(s->tx.ToCommand());
            return OK();
        }};

    // UP: Up - no parameter
    registry[CommandPrefix::CommandPrefixEnum::UP] = {
        CommandMetaData::SafeMode::ALLOWED,
        [](Session* s) -> CommandBase* { return &s->up; },
        [](Session* s) -> CommandResult {
            s->write(s->up.ToCommand());
            return OK();
        }};

    // VR: VFO RX - no parameter
    registry[CommandPrefix::CommandPrefixEnum::VR] = {
        CommandMetaData::SafeMode::ALLOWED,
        [](Session* s) -> CommandBase* { return &s->vr; },
        [](Session* s) -> CommandResult {
            s->write(s->vr.ToCommand());
            return OK();
        }};

    // XT: External Frequency Reference - requires parameter
    registry[CommandPrefix::CommandPrefixEnum::XT] = {
        CommandMetaData::SafeMode::ALLOWED,
        [](Session* s) -> CommandBase* { return &s->xt; },
        [this](Session* s) -> CommandResult {
            return dispatchSet(s->xt, s->lastParameter);
        }};
}

CommandResult CommandDispatcher::dispatchSet(CommandBase& command,
                                             const std::string& parameter) {
    CommandResult setResult = command.set(parameter);
    if (!setResult.OK()) {
        return setResult;
    }

    core::Result<std::string> commandResult = command.buildSetCommand();
    if (!commandResult.OK()) {
        return commandResult.error();
    }

    session->write(commandResult.value());
    return OK();
}

CommandResult CommandDispatcher::dispatchRead(CommandBase& command) {
    core::Result<std::string> commandResult = command.buildReadCommand();
    if (!commandResult.OK()) {
        return commandResult.error();
    }

    session->write(commandResult.value(), true);
    return OK();
}

CommandResult
CommandDispatcher::Dispatch(CommandPrefix::CommandPrefixEnum command,
                            const std::string& param) {
    if (!radioProfile->IsCommandAvailable(command)) {
        std::string commandString = CommandPrefix::CommandToString(command);
        return Error(core::ErrorCode::CommandNotAvailable,
                     "SerialCommand \"" + commandString +
                         "\" not available on this model");
    }

    auto it = registry.find(command);

    if (it == registry.end()) {
        return Error(core::ErrorCode::CommandNotImplemented,
                     "SerialCommand not implemented");
    }

    const CommandMetaData& metadata = it->second;
    CommandBase* cmd = metadata.commandRef(session);

    if (metadata.safeMode == CommandMetaData::SafeMode::DISABLED &&
        session->safeMode) {
        std::string commandString = CommandPrefix::CommandToString(command);
        return Error(core::ErrorCode::CommandDisabledSafeMode,
                     "SerialCommand \"" + commandString +
                         "\" disabled in SAFE MODE");
    }

    if (cmd->supportsSet() && !cmd->supportsRead() && param.empty()) {
        std::string commandString = CommandPrefix::CommandToString(command);
        return Error(core::ErrorCode::ParameterEmpty,
                     "SerialCommand \"" + commandString +
                         "\" requires a parameter");
    }

    if (!cmd->supportsSet() && !param.empty()) {
        std::string commandString = CommandPrefix::CommandToString(command);
        return Error(core::ErrorCode::CommandNoParameterAllowed,
                     "SerialCommand \"" + commandString +
                         "\" accepts no parameters. Ignoring \"" + param +
                         "\" and sending standard " + commandString +
                         " command");
    }

    session->lastParameter = param;

    return metadata.handler(session);
}

CommandResult
CommandDispatcher::RouteAnswer(CommandPrefix::CommandPrefixEnum cmd,
                               const std::string& payload) {
    auto it = registry.find(cmd);
    if (it == registry.end()) {
        return Error(core::ErrorCode::CommandNotImplemented,
                     "SerialCommand not implemented");
    }

    CommandBase* command = it->second.commandRef(session);
    if (!command->supportsAnswer()) {
        return OK();
    }

    CommandResult result = command->parseAnswer(payload);
    if (!result.OK() &&
        result.error().code ==
            core::ToString(core::ErrorCode::CommandNotImplemented)) {
        return OK();
    }

    return result;
}

std::string CommandDispatcher::GetAnswerDisplayValue(
    CommandPrefix::CommandPrefixEnum cmd) const {
    auto it = registry.find(cmd);
    if (it == registry.end()) {
        return "";
    }

    CommandBase* command = it->second.commandRef(session);
    if (!command) {
        return "";
    }

    return command->getDisplayValue();
}
