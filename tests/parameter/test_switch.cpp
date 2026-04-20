#include "parameter/switch.h"
#include "test_framework.h"

TEST(Switch, ON_String) {
    ASSERT_EQ(Switch::StringToSwitch("ON"), Switch::SwitchEnum::ON);
}

TEST(Switch, OFF_String) {
    ASSERT_EQ(Switch::StringToSwitch("OFF"), Switch::SwitchEnum::OFF);
}

TEST(Switch, One_MapsToOn) {
    ASSERT_EQ(Switch::StringToSwitch("1"), Switch::SwitchEnum::ON);
}

TEST(Switch, Zero_MapsToOff) {
    ASSERT_EQ(Switch::StringToSwitch("0"), Switch::SwitchEnum::OFF);
}

TEST(Switch, Unknown_Invalid) {
    ASSERT_EQ(Switch::StringToSwitch("INVALID"), Switch::SwitchEnum::UNKNOWN);
}

TEST(Switch, Unknown_Empty) {
    ASSERT_EQ(Switch::StringToSwitch(""), Switch::SwitchEnum::UNKNOWN);
}

TEST(Switch, ToBoolString_On) {
    ASSERT_STREQ(Switch::SwitchToBoolString(Switch::SwitchEnum::ON), "1");
}

TEST(Switch, ToBoolString_Off) {
    ASSERT_STREQ(Switch::SwitchToBoolString(Switch::SwitchEnum::OFF), "0");
}

TEST(Switch, ToString_On) {
    ASSERT_STREQ(Switch::SwitchToString(Switch::SwitchEnum::ON), "ON");
}

TEST(Switch, ToString_Off) {
    ASSERT_STREQ(Switch::SwitchToString(Switch::SwitchEnum::OFF), "OFF");
}
