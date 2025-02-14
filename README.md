# Shell of Mine

A simple custom shell implementation in C that provides basic shell functionalities such as executing commands, handling files, and managing directories.

## Features

- Execute basic commands like `help`, `clr`, `exit`, and `say`
- File operations: `clone`, `cut`, `read`, `del`
- Directory operations: `list`, `cwp`
- Date and time retrieval
- Open external programs

## Installation

### Prerequisites

- GCC Compiler
- Windows OS (uses Windows-specific functions like `CreateProcess` and `cls` for clearing the terminal)

### Build Instructions

1. Clone the repository:
   ```sh
   git clone https://github.com/Ertugrulmutlu/shell_of_mine.git
   cd shell_of_mine
   ```
2. Compile the source code:
   ```sh
   gcc main.c .\read_command.c .\parser.c .\execute.c -o shell.exe
   ```
3. Run the shell:
   ```sh
   ./shell
   ```

## Usage

When the shell starts, it prompts the user to enter commands.

### Available Commands

| Command | Description                                          |
| ------- | ---------------------------------------------------- |
| `help`  | Displays help information for commands               |
| `clr`   | Clears the terminal screen                           |
| `say`   | Echoes back the provided text                        |
| `exit`  | Exits the shell                                      |
| `cwp`   | Displays the current working directory               |
| `date`  | Shows the current date and time                      |
| `clone` | Copies a file to a new location                      |
| `cut`   | Moves a file to a new location                       |
| `read`  | Reads the contents of a file                         |
| `del`   | Deletes a specified file                             |
| `list`  | Lists files and directories in a specified directory |
| `open`  | Opens an external program                            |

### Example Usage

- Display help for a specific command:
  ```sh
  help -date
  ```
- Clone a file:
  ```sh
  clone myfile.txt C:\backup newfile.txt
  ```
- List directory contents:
  ```sh
  list C:\Users
  ```

## Contributing

Feel free to fork this project and submit pull requests. Issues and feature requests are welcome.
