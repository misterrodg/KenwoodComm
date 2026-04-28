#include "parameter/rit_frequency.h"
#include "test_framework.h"

TEST(RITFrequency, ParseIntegerHz) {
    RITFrequency rit;

    ASSERT_TRUE(rit.setRITFrequency("00000Hz").OK());
    ASSERT_EQ(rit.getRITFrequencyInHz(), (short int)0);
}