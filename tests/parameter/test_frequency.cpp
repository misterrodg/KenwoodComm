#include "parameter/frequency.h"
#include "test_framework.h"

// ---- valid input ----

TEST(Frequency, ParseMHz) {
    Frequency f;
    ASSERT_TRUE(f.setFrequency("14.1 MHz"));
    ASSERT_EQ(f.getFrequencyInHz(), (uint64_t)14100000);
}

TEST(Frequency, ParseKHz) {
    Frequency f;
    ASSERT_TRUE(f.setFrequency("14200 kHz"));
    ASSERT_EQ(f.getFrequencyInHz(), (uint64_t)14200000);
}

TEST(Frequency, ParseHz) {
    Frequency f;
    ASSERT_TRUE(f.setFrequency("7000000 Hz"));
    ASSERT_EQ(f.getFrequencyInHz(), (uint64_t)7000000);
}

TEST(Frequency, ParseCaseInsensitiveUnit) {
    Frequency f;
    ASSERT_TRUE(f.setFrequency("144.200 MHZ"));
    ASSERT_EQ(f.getFrequencyInHz(), (uint64_t)144200000);
}

// ---- formatted output ----

TEST(Frequency, GetFrequencyString_LeadingZeros) {
    Frequency f;
    f.setFrequency("14.1 MHz");
    ASSERT_STREQ(f.getFrequencyString(), "00014100000");
}

TEST(Frequency, GetFrequencyString_SevenMHz) {
    Frequency f;
    f.setFrequency("7 MHz");
    ASSERT_STREQ(f.getFrequencyString(), "00007000000");
}

// ---- invalid input ----

TEST(Frequency, Invalid_NoUnit) {
    Frequency f;
    ASSERT_FALSE(f.setFrequency("14100000"));
}

TEST(Frequency, Invalid_Empty) {
    Frequency f;
    ASSERT_FALSE(f.setFrequency(""));
}

TEST(Frequency, Invalid_UnknownUnit) {
    Frequency f;
    ASSERT_FALSE(f.setFrequency("14.1 THz"));
}

TEST(Frequency, Invalid_Letters) {
    Frequency f;
    ASSERT_FALSE(f.setFrequency("abc MHz"));
}
