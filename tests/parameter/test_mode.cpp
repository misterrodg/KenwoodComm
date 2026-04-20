#include "test_framework.h"
#include "parameter/mode.h"

TEST(Mode, LSB_String) {
    ASSERT_EQ(Mode::StringToMode("LSB"), Mode::ModeEnum::LSB);
}

TEST(Mode, USB_String) {
    ASSERT_EQ(Mode::StringToMode("USB"), Mode::ModeEnum::USB);
}

TEST(Mode, CW_String) {
    ASSERT_EQ(Mode::StringToMode("CW"), Mode::ModeEnum::CW);
}

TEST(Mode, FM_String) {
    ASSERT_EQ(Mode::StringToMode("FM"), Mode::ModeEnum::FM);
}

TEST(Mode, AM_String) {
    ASSERT_EQ(Mode::StringToMode("AM"), Mode::ModeEnum::AM);
}

TEST(Mode, FSK_String) {
    ASSERT_EQ(Mode::StringToMode("FSK"), Mode::ModeEnum::FSK);
}

TEST(Mode, CWN_String) {
    ASSERT_EQ(Mode::StringToMode("CWN"), Mode::ModeEnum::CWN);
}

// Numeric aliases
TEST(Mode, Numeric_1_IsLSB) {
    ASSERT_EQ(Mode::StringToMode("1"), Mode::ModeEnum::LSB);
}

TEST(Mode, Numeric_2_IsUSB) {
    ASSERT_EQ(Mode::StringToMode("2"), Mode::ModeEnum::USB);
}

TEST(Mode, Numeric_4_IsFM) {
    ASSERT_EQ(Mode::StringToMode("4"), Mode::ModeEnum::FM);
}

TEST(Mode, Unknown_Invalid) {
    ASSERT_EQ(Mode::StringToMode("SSB"), Mode::ModeEnum::UNKNOWN);
}

TEST(Mode, Unknown_Empty) {
    ASSERT_EQ(Mode::StringToMode(""), Mode::ModeEnum::UNKNOWN);
}

TEST(Mode, ModeToIntString_LSB) {
    ASSERT_STREQ(Mode::ModeToIntString(Mode::ModeEnum::LSB), "1");
}

TEST(Mode, ModeToIntString_USB) {
    ASSERT_STREQ(Mode::ModeToIntString(Mode::ModeEnum::USB), "2");
}

TEST(Mode, ModeToString_CW) {
    ASSERT_STREQ(Mode::ModeToString(Mode::ModeEnum::CW), "CW");
}
