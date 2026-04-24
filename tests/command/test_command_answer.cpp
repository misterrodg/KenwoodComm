#include "test_framework.h"
#include "command/ai.h"
#include "command/by.h"
#include "command/dc.h"
#include "command/fa.h"

TEST(CommandAnswer, SwitchPayload_ParsesToState) {
    AI ai;
    CommandResult result = ai.parseAnswer("1");

    ASSERT_TRUE(result.OK());
    ASSERT_STREQ(ai.ToCommand(), "AI1;");
}

TEST(CommandAnswer, BusyPayload_ParsesToState) {
    BY by;
    CommandResult result = by.parseAnswer("1");

    ASSERT_TRUE(result.OK());
    ASSERT_STREQ(by.ToCommand(), "BY1;");
}

TEST(CommandAnswer, DestinationPayload_ParsesToState) {
    DC dc;
    CommandResult result = dc.parseAnswer("1");

    ASSERT_TRUE(result.OK());
    ASSERT_STREQ(dc.ToCommand(), "DC1;");
}

TEST(CommandAnswer, FrequencyPayload_ParsesToState) {
    FA fa;
    CommandResult result = fa.parseAnswer("00014100000");

    ASSERT_TRUE(result.OK());
    ASSERT_STREQ(fa.ToCommand(), "FA00014100000;");
}

TEST(CommandAnswer, InvalidPayload_ReturnsError) {
    BY by;
    CommandResult result = by.parseAnswer("XYZ");

    ASSERT_FALSE(result.OK());
}
