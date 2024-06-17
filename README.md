# KenwoodComm

A command line interface for Kenwood radios using IF-10A/B/C modules.

## Running the Program

Run the program from the command line with:

```
KenwoodComm
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

## Available Commands

- `commands`: Displays a list of the available commands specific to the radio that you have selected.
- `commandhelp`: Displays the same list as above, with the meaning of the command identifiers.
- `exit`: Closes the terminal connection and exits the program.

### Control Commands

All commands are case-insensitive, and will always be translated to all caps.
Any command that accepts `ON` or `OFF` will also accept `1` or `0` as well.
Any command that expects only `NONE` for its parameter will ignore anything beyond the command itself.

| Command | Parameters                                                                                                                                |
| ------- | ----------------------------------------------------------------------------------------------------------------------------------------- |
| `AI`    | `ON` / `OFF` (or `1` / `0`)                                                                                                               |
| `AT`    | `NONE`                                                                                                                                    |
| `BY`    | `NONE`                                                                                                                                    |
| `CN`    | `CTCSS NUMBER` as an integer between `01` and `39` (with a leading zero, as necessary), or the `CTCSS FREQUENCY` as a double (`100.0`).\* |
| `CT`    | `ON` / `OFF` (or `1` / `0`), or `NONE`                                                                                                    |
| `DI`    | `NONE`                                                                                                                                    |
| `DS`    | `ON` / `OFF` (or `1` / `0`), or `NONE`                                                                                                    |
| `DN`    | `NONE`                                                                                                                                    |
| `FA`    | `FREQUENCY` as an integer or double, followed by `HZ`, `KHZ`, `MHZ`, or `GHZ`.                                                            |
| `FB`    | `FREQUENCY` as an integer or double, followed by `HZ`, `KHZ`, `MHZ`, or `GHZ`.                                                            |
| `FN`    | `VFOA` / `VFOB` / `MEMORY` (or `A` / `B` / `M`, or `0` / `1` / `2`). If using a TS711 or TS811 `COM` (or `C` or `3`) is also available.   |
| `HD`    | `ON` / `OFF` (or `1` / `0`), or `NONE`                                                                                                    |
| `ID`    | `NONE`                                                                                                                                    |
| `IF`    | `NONE`                                                                                                                                    |
| `LK`    | `ON` / `OFF` (or `1` / `0`), or `NONE`                                                                                                    |
| `LO`    | `NONE`                                                                                                                                    |
| `LT`    | `ON` / `OFF` (or `1` / `0`), or `NONE`                                                                                                    |
| `MC`    | `MEMORY CHANNEL` as an integer (with a leading zero). If using a TS940, `MEMORY BANK` is also required before the channel.                |
| `MD`    | `LSB` / `USB` / `CW` / `FM` / `AM` / `FSK` / `CWN` (or `1` / `2` / `3` / `4` / `5` / `6` / `7`), depending on your radio capabilities.    |
| `MS`    | `ON` / `OFF` (or `1` / `0`), or `NONE`                                                                                                    |
| `MT`    | `ON` / `OFF` (or `1` / `0`), or `NONE`                                                                                                    |
| `RC`    | `NONE`                                                                                                                                    |
| `RD`    | `NONE`                                                                                                                                    |
| `RX`    | `NONE`                                                                                                                                    |
| `RT`    | `ON` / `OFF` (or `1` / `0`)                                                                                                               |
| `RU`    | `NONE`                                                                                                                                    |
| `SC`    | `ON` / `OFF` (or `1` / `0`)                                                                                                               |
| `SP`    | `ON` / `OFF` (or `1` / `0`)                                                                                                               |
| `ST`    | `ON` / `OFF` (or `1` / `0`)                                                                                                               |
| `TN`    | `TONE NUMBER` as an integer between `01` and `38` (with a leading zero, as necessary), or the `TONE FREQUENCY` as a double (`100.0`).\*   |
| `TO`    | `ON` / `OFF` (or `1` / `0`)                                                                                                               |
| `TX`    | `NONE`                                                                                                                                    |
| `UP`    | `NONE`                                                                                                                                    |
| `VR`    | `NONE`                                                                                                                                    |
| `XT`    | `ON` / `OFF` (or `1` / `0`)                                                                                                               |

\*Note: Kenwood defines this parameter in the IF-10 documents as an integer value between 01 and 37, but their list of frequencies in various radio manuals contains 39 entries (or simply lists the min and max value: `67.0` - `1750.0`). The current mapping is based on the TS-870 manual, which lists them on page 85.

At the moment, using any other available commands will display `Command "XX" Not Implemented.`, where `XX` is the command.
Using any command outside of the available list will display `Invalid Command`.
No data is sent via the planned serial connection.
