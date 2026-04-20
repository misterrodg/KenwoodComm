#include "test_framework.h"
#include "mock_serial.h"
#include "parameter/model_number.h"
#include "session.h"

// Build a Session backed by MockSerial for a given radio model.
static Session makeSession(const std::string& model, MockSerial*& outMock) {
    ModelNumber mn;
    mn.setModelNumber(model);
    auto mock = std::make_unique<MockSerial>();
    outMock = mock.get();
    return Session(false, mn, std::move(mock));
}

// ---- Dispatcher: parameter validation ----

TEST(Dispatcher, RequiredParam_Missing_ReturnsError) {
    MockSerial* mock = nullptr;
    Session session = makeSession("TS140S", mock);
    // AI requires a parameter; calling without one should print an error and
    // not forward any command to the serial port.
    mock->reset();
    session.CheckCommand("AI");
    ASSERT_TRUE(mock->written.empty());
}

TEST(Dispatcher, NoParam_WithParam_ReturnsError) {
    MockSerial* mock = nullptr;
    Session session = makeSession("TS140S", mock);
    // RX accepts no parameters.
    mock->reset();
    session.CheckCommand("RX someextraarg");
    ASSERT_TRUE(mock->written.empty());
}

// ---- Dispatcher: command routing ----

TEST(Dispatcher, FA_Write_SendsCorrectCommand) {
    MockSerial* mock = nullptr;
    Session session = makeSession("TS140S", mock);
    mock->reset();
    session.CheckCommand("FA 14.1 MHz");
    ASSERT_TRUE(mock->receivedCommand("FA00014100000;"));
}

TEST(Dispatcher, FA_Query_SendsReadCommand) {
    MockSerial* mock = nullptr;
    Session session = makeSession("TS140S", mock);
    mock->nextRead = "FA00014100000;";
    mock->reset();
    session.CheckCommand("FA");
    ASSERT_TRUE(mock->receivedCommand("FA;"));
}

TEST(Dispatcher, RX_NoParam_SendsCommand) {
    MockSerial* mock = nullptr;
    Session session = makeSession("TS140S", mock);
    mock->reset();
    session.CheckCommand("RX");
    ASSERT_TRUE(mock->receivedCommand("RX;"));
}

TEST(Dispatcher, TX_BlockedInSafeMode) {
    ModelNumber mn;
    mn.setModelNumber("TS140S");
    auto mock = std::make_unique<MockSerial>();
    MockSerial* rawMock = mock.get();
    Session session(true /*safeMode*/, mn, std::move(mock));
    rawMock->reset();
    session.CheckCommand("TX");
    ASSERT_TRUE(rawMock->written.empty());
}

// ---- Dispatcher: unavailable command ----

TEST(Dispatcher, CommandNotOnModel_Rejected) {
    MockSerial* mock = nullptr;
    // TS140S does not support CT.
    Session session = makeSession("TS140S", mock);
    mock->reset();
    session.CheckCommand("CT 100.0 Hz");
    ASSERT_TRUE(mock->written.empty());
}

// ---- Session: invalid input ----

TEST(Session, UnknownCommand_Rejected) {
    MockSerial* mock = nullptr;
    Session session = makeSession("TS140S", mock);
    mock->reset();
    session.CheckCommand("ZZ");
    ASSERT_TRUE(mock->written.empty());
}
