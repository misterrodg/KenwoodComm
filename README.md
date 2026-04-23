# KenwoodComm

A command line interface for Kenwood radios using IF-10A/B/C/D modules.

## Running the Program

Run the program from the command line with:

```
KenwoodComm
```

### Profiles

An optional `profile=<radio_model>` argument can be passed to load the program using a given profile. This checks for an existing profile, and if it is not found, will walk you through creating a new profile. This is helpful for people who have multiple radios that they wish to use via the command line.

The first time the program runs, it will set up a default profile for you. See [Initial Run](#initial-run) for details.

```
KenwoodComm profile=TS940S
```

### Local Mode

An optional `local` argument can be passed to set the program in local mode. This skips establishing a serial connection for test purposes.

```
KenwoodComm local
```

### Safe Mode

An optional `safe` argument can be passed to set the program in safe mode. This disables the `TX` command so that you can test using the commands with your radio, without worrying about accidentally transmitting in the process.

```
KenwoodComm safe
```

You can confirm that you are in safe mode by looking for the `SAFE` at the beginning of the command line:

```
SAFE ::
```

## Initial Run

When running the program for the first time, it will prompt you for your callsign and radio model. The prompts are case-insensitive, and will always store/use the values in all caps.

- Callsign: Any string between 3 and 6 alphanumeric characters. Only certain radios use this, but it is also used in the welcome lines when the program runs.

- Radio: This controls which commands are available, based on what the radio will accept. Must be one of the following:
  - TS50S
  - TS60S
  - TS140S
  - TS680S
  - TS711A
  - TS711E
  - TS790A
  - TS790E
  - TS811A
  - TS811B
  - TS811E
  - TS940S

- Serial Port: This is the serial port being used to communicate with the radio. You will need to find this information for your specific setup, but it will be similar to:
  - Windows: `COM3` (or `COM4`, etc.)
  - Linux: `/dev/ttyUSB0` (or `/dev/ttyACM0`)

## Available Commands

- `commands`: Displays a list of the available commands specific to the radio that you have selected.
- `commandhelp`: Displays the same list as above, with the meaning of the command identifiers.
- `exit`: Closes the terminal connection and exits the program.

### Control Commands

All commands are case-insensitive, and will always be translated to all caps.
Any command that accepts `ON` or `OFF` will also accept `1` or `0` as well.
Any command that expects only `NONE` for its parameter will ignore anything beyond the command itself.

| Command | Description      | Parameters                                                                                                                                |
| ------- | ---------------- | ----------------------------------------------------------------------------------------------------------------------------------------- |
| `AI`    | Auto Information | `ON` / `OFF` (or `1` / `0`)                                                                                                               |
| `AT`    | Antenna Tuner    | `NONE`                                                                                                                                    |
| `BY`    | Busy             | `NONE`                                                                                                                                    |
| `CN`    | CTCSS Number     | `CTCSS NUMBER` as an integer between `01` and `39` (with a leading zero, as necessary), or the `CTCSS FREQUENCY` as a double (`100.0`).\* |
| `CT`    | CTCSS            | `ON` / `OFF` (or `1` / `0`), or `NONE`                                                                                                    |
| `DI`    | DCS ID           | `NONE`                                                                                                                                    |
| `DS`    | DCS              | `ON` / `OFF` (or `1` / `0`), or `NONE`                                                                                                    |
| `DN`    | Down             | `NONE`                                                                                                                                    |
| `FA`    | Frequency A      | `FREQUENCY` as an integer or double, followed by `HZ`, `KHZ`, `MHZ`, or `GHZ`.                                                            |
| `FB`    | Frequency B      | `FREQUENCY` as an integer or double, followed by `HZ`, `KHZ`, `MHZ`, or `GHZ`.                                                            |
| `FN`    | Function         | `VFOA` / `VFOB` / `MEMORY` (or `A` / `B` / `M`, or `0` / `1` / `2`). If using a TS711 or TS811 `COM` (or `C` or `3`) is also available.   |
| `HD`    | Scan Hold        | `ON` / `OFF` (or `1` / `0`), or `NONE`                                                                                                    |
| `ID`    | Model Number ID  | `NONE`                                                                                                                                    |
| `IF`    | Information      | `NONE`                                                                                                                                    |
| `LK`    | Lock             | `ON` / `OFF` (or `1` / `0`), or `NONE`                                                                                                    |
| `LO`    | Local Control    | `NONE`                                                                                                                                    |
| `LT`    | Auto Lock Tune   | `ON` / `OFF` (or `1` / `0`), or `NONE`                                                                                                    |
| `MC`    | Memory Channel   | `MEMORY CHANNEL` as an integer (with a leading zero). If using a TS940, `MEMORY BANK` is also required before the channel.                |
| `MR`    | Memory Read      | `SPLIT SPECIFICATION`, `MEMORY BANK` (TS940) and `MEMORY CHANNEL`                                                                         |
| `MD`    | Mode             | `LSB` / `USB` / `CW` / `FM` / `AM` / `FSK` / `CWN` (or `1` / `2` / `3` / `4` / `5` / `6` / `7`), depending on your radio capabilities.    |
| `MS`    | Memory Scan      | `ON` / `OFF` (or `1` / `0`), or `NONE`                                                                                                    |
| `MT`    | Mute             | `ON` / `OFF` (or `1` / `0`), or `NONE`                                                                                                    |
| `RC`    | RIT Clear        | `NONE`                                                                                                                                    |
| `RD`    | RIT Down         | `NONE`                                                                                                                                    |
| `RX`    | Receive          | `NONE`                                                                                                                                    |
| `RT`    | RIT              | `ON` / `OFF` (or `1` / `0`)                                                                                                               |
| `RU`    | RIT Up           | `NONE`                                                                                                                                    |
| `SC`    | Scan             | `ON` / `OFF` (or `1` / `0`)                                                                                                               |
| `SM`    | S Meter          | `NONE`                                                                                                                                    |
| `SP`    | Split            | `ON` / `OFF` (or `1` / `0`)                                                                                                               |
| `ST`    | Step             | `ON` / `OFF` (or `1` / `0`)                                                                                                               |
| `TN`    | Tone Number      | `TONE NUMBER` as an integer between `01` and `38` (with a leading zero, as necessary), or the `TONE FREQUENCY` as a double (`100.0`).\*   |
| `TO`    | Tone             | `ON` / `OFF` (or `1` / `0`)                                                                                                               |
| `TX`    | Transmit         | `NONE`                                                                                                                                    |
| `UP`    | Up               | `NONE`                                                                                                                                    |
| `VR`    | Voice Recall     | `NONE`                                                                                                                                    |
| `XT`    | XIT              | `ON` / `OFF` (or `1` / `0`)                                                                                                               |

\*Note: Kenwood defines this parameter in the IF-10 documents as an integer value between 01 and 37, but their list of frequencies in various radio manuals contains 39 entries (or simply lists the min and max value: `67.0` - `1750.0`). The current mapping is based on the IF-10D manual, which lists them on page 16.

At the moment, using any other available commands will display `Command "XX" Not Implemented.`, where `XX` is the command.
Using any command outside of the available list will display `Invalid Command`.
No data is sent via the planned serial connection.
