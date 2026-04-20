#include "test_framework.h"
#include "command/command_switch.h"
#include "command/command_prefix.h"

// Use AI (Auto Information) as a concrete CommandSwitch instance.

TEST(CommandSwitch, SetSwitch_ON_ReturnsOK) {
    CommandSwitch sw(CommandPrefix::CommandPrefixEnum::AI);
    ASSERT_TRUE(sw.SetSwitch("ON").OK());
}

TEST(CommandSwitch, SetSwitch_OFF_ReturnsOK) {
    CommandSwitch sw(CommandPrefix::CommandPrefixEnum::AI);
    ASSERT_TRUE(sw.SetSwitch("OFF").OK());
}

TEST(CommandSwitch, SetSwitch_Numeric1_ReturnsOK) {
    CommandSwitch sw(CommandPrefix::CommandPrefixEnum::AI);
    ASSERT_TRUE(sw.SetSwitch("1").OK());
}

TEST(CommandSwitch, SetSwitch_Numeric0_ReturnsOK) {
    CommandSwitch sw(CommandPrefix::CommandPrefixEnum::AI);
    ASSERT_TRUE(sw.SetSwitch("0").OK());
}

TEST(CommandSwitch, SetSwitch_Invalid_ReturnsError) {
    CommandSwitch sw(CommandPrefix::CommandPrefixEnum::AI);
    ASSERT_FALSE(sw.SetSwitch("MAYBE").OK());
}

TEST(CommandSwitch, SetSwitch_Empty_ReturnsError) {
    CommandSwitch sw(CommandPrefix::CommandPrefixEnum::AI);
    ASSERT_FALSE(sw.SetSwitch("").OK());
}

TEST(CommandSwitch, ToCommand_Write_ON) {
    CommandSwitch sw(CommandPrefix::CommandPrefixEnum::AI);
    sw.SetSwitch("ON");
    ASSERT_STREQ(sw.ToCommand(), "AI1;");
}

TEST(CommandSwitch, ToCommand_Write_OFF) {
    CommandSwitch sw(CommandPrefix::CommandPrefixEnum::AI);
    sw.SetSwitch("OFF");
    ASSERT_STREQ(sw.ToCommand(), "AI0;");
}

TEST(CommandSwitch, ToCommand_ReadStatus) {
    CommandSwitch sw(CommandPrefix::CommandPrefixEnum::AI);
    ASSERT_STREQ(sw.ToCommand(true), "AI;");
}
