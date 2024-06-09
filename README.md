# KenwoodComm

A command line interface for Kenwood radios using IF-10A/B/C modules.

## Initial Run

When running the program for the first time, it will prompt you for your callsign and radio model. The prompts are case-insensitive, and will always store/use the values in all caps.

- Callsign: Any string between 3 and 6 alphanumeric characters. Only certain radios use this, but it is also used in the welcome lines when the program runs.

- Radio: This controls which commands are available, based on what the radio will accept. Must be one of the following:
  - TS140S
  - TS680S
  - TS711A
  - TS711E
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
Any command that expects only `NONE` for its parameter will ignore anything beyond the command itself.

| Command | Parameters                                                                     |
| ------- | ------------------------------------------------------------------------------ |
| `AI`    | `ON` or `OFF`                                                                  |
| `AT`    | `NONE`                                                                         |
| `DI`    | `NONE`                                                                         |
| `DS`    | `ON`, `OFF`, or `NONE`                                                         |
| `DN`    | `NONE`                                                                         |
| `FA`    | `FREQUENCY` as an integer or double, followed by `HZ`, `KHZ`, `MHZ`, or `GHZ`. |
| `FB`    | `FREQUENCY` as an integer or double, followed by `HZ`, `KHZ`, `MHZ`, or `GHZ`. |
| `FN`    | `VFOA`, `VFOB`, `MEMORY`. If using a TS711 or TS811 `COM` is also available.   |
| `HD`    | `ON`, `OFF`, or `NONE`                                                         |
| `ID`    | `NONE`                                                                         |
| `IF`    | `NONE`                                                                         |
| `LK`    | `ON`, `OFF`, or `NONE`                                                         |
| `LO`    | `NONE`                                                                         |
| `MS`    | `ON`, `OFF`, or `NONE`                                                         |
| `RC`    | `NONE`                                                                         |
| `RD`    | `NONE`                                                                         |
| `RX`    | `NONE`                                                                         |
| `RT`    | `ON` or `OFF`                                                                  |
| `RU`    | `NONE`                                                                         |
| `SC`    | `ON` or `OFF`                                                                  |
| `TX`    | `NONE`                                                                         |
| `UP`    | `NONE`                                                                         |

At the moment, using any other available commands will display `Command "XX" Not Implemented.`, where `XX` is the command.
Using any command outside of the available list will display `Invalid Command`.
No data is sent via the planned serial connection.
