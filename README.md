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

At the moment, using any of the available commands will display `Sending: XX`, where `XX` is the command.
Using any command outside of the available list will display `Invalid Command.`.
At the moment, no data is sent.
