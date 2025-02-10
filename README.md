# Bank System

## Overview

This project is a simple bank system simulation written in C++. It includes classes for managing bank accounts, handling transactions, and logging activities. The system supports multiple clients performing random transactions on different bank accounts concurrently.

## Features

- **Bank Account Management**: Create and manage multiple bank accounts.
- **Concurrent Transactions**: Simulate multiple clients performing deposits, withdrawals, and balance checks concurrently.
- **Logging**: Log transaction details and generate a transaction report.

## Classes

- **Bank**: Manages a collection of bank accounts.
- **BankAccount**: Represents a single bank account with methods for deposit and withdrawal.
- **Logger**: Singleton class for logging transaction details and generating reports.

## Dependencies

- C++ Standard Library
- CMake (version 3.28 or higher)

## Building the Project

1. **Clone the repository**:
    ```sh
    git clone <repository-url>
    cd <repository-directory>
    ```

2. **Create a build directory**:
    ```sh
    mkdir build
    cd build
    ```

3. **Run CMake**:
    ```sh
    cmake ..
    ```

4. **Build the project**:
    ```sh
    cmake --build .
    ```

## Running the Project

After building the project, you can run the executable:

```sh
./src/main
```

## Project Structure

- `src/`: Contains the source code files.
- `headers/`: Contains the header files.
- `CMakeLists.txt`: CMake configuration file.
- `README.md`: Project documentation.

## License

This project is licensed under the MIT License. See the `LICENSE` file for details.