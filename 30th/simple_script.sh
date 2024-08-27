#!/bin/bash

# File: example_script.sh

# Define the log file path
LOGFILE="daemon_log.txt"

# Get the current date and time
CURRENT_TIME=$(date)

# Write the current date and time to the log file
echo "Script executed at: $CURRENT_TIME" >> "$LOGFILE"

