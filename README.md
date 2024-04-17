# System Call Monitoring Tool
## Overview

The System Call Monitoring Tool is a utility designed to track and analyze system calls made by processes running on a Unix-based operating system. It provides developers, system administrators, and security professionals with insights into the behavior of programs at the system call level.
Features

    Real-time Monitoring: Monitor system calls in real-time as they occur.
    Process Filtering: Selectively monitor specific processes or groups of processes.
    System Call Analysis: Collect data on the types and frequency of system calls being made.
    Logging: Record system call activity for further analysis and auditing.
    User-friendly Interface: Intuitive command-line interface for ease of use.

## Installation
## Prerequisites

    Unix-based operating system (e.g., Linux, macOS)
    C compiler (e.g., GCC)

## Installation Steps

    Clone the repository: git clone https://github.com/yourusername/system-call-monitor.git
    Navigate to the project directory: cd system-call-monitor
    Compile the monitoring tool: gcc monitor.c -o monitor
    Run the tool: ./monitor

## Usage

    Run the compiled executable with appropriate permissions (e.g., sudo ./monitor) to access system call data.
    Specify any desired options such as process filtering or logging.
    Monitor system call activity in real-time or review logged data after monitoring sessions.

## Examples
## Basic Usage

### bash

./monitor

### Monitor Specific Process

bash

./monitor -p firefox

### Log System Call Activity

bash

./monitor -l system_calls.log

## Contributing

Contributions are welcome! If you'd like to contribute to this project, please fork the repository and submit a pull request with your proposed changes.
License

This project is licensed under the MIT License - see the LICENSE file for details.
Acknowledgments

    This tool utilizes system call interception techniques.
    Special thanks to Bharath for their contributions to this project.

## Contact

For questions or feedback, please contact Kovith at kovithkovi123@gmail.com
