#!/bin/bash

# Function to check if the script is run as root
check_root() {
    if [ "$EUID" -ne 0 ]; then
        echo "This script must be run as root. Please rerun with sudo."
        exit 1
    fi
}

# Function to compile the C program
compile_program() {
    SOURCE_FILE="serveo.c"
    OUTPUT_FILE="serveo"

    echo "Compiling $SOURCE_FILE..."
    gcc $SOURCE_FILE -o $OUTPUT_FILE

    if [ $? -eq 0 ]; then
        echo "Compilation successful!"
    else
        echo "Compilation failed. Please check for errors."
        exit 1
    fi
}

# Function to install the compiled binary
install_program() {
    OUTPUT_FILE="serveo"
    INSTALL_DIR="/usr/bin"

    echo "Installing $OUTPUT_FILE to $INSTALL_DIR..."
    mv $OUTPUT_FILE $INSTALL_DIR

    if [ $? -eq 0 ]; then
        echo "Installation successful!"
    else
        echo "Installation failed. Please check for errors."
        exit 1
    fi
}

# Function to clean up the source files
clean_up() {
    SOURCE_FILE="serveo.c"

    echo "Cleaning up source files..."
    rm -f $SOURCE_FILE

    if [ $? -eq 0 ]; then
        echo "Cleanup successful!"
    else
        echo "Cleanup failed. Please check for errors."
    fi
}

# Main function
main() {
    check_root

    echo "Starting installation process..."

    compile_program
    install_program
    clean_up

    echo "Installation process completed!"
}

# Run the main function
main
