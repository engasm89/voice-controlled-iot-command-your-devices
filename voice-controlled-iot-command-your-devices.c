/*
 * Course: Voice Controlled Iot Command Your Devices
 * Platform: Embedded Systems
 * Author: Ashraf S A AlMadhoun
 * 
 * Description:
 * This code demonstrates the core concepts taught in the "Voice Controlled Iot Command Your Devices" course.
 * It provides a practical implementation that students can study, modify, and
 * use as a foundation for their own projects.
 * 
 * Learning Objectives:
 * - Understand the fundamental principles covered in this course
 * - Practice implementing the concepts with real code
 * - Build a working example that can be extended
 * 
 * Hardware Requirements:
 * - Development board (Embedded Systems)
 * - Components as specified in CIRCUIT.md
 * - USB cable for programming
 * 
 * Pin Connections:
 * Refer to CIRCUIT.md for detailed wiring diagrams and pin assignments.
 * 
 * Usage:
 * 1. Review the code structure and comments
 * 2. Connect hardware according to CIRCUIT.md
 * 3. Upload code to your development board
 * 4. Monitor serial output for debugging
 * 
 * Course Link: https://www.udemy.com/course/voice-controlled-iot-command-your-devices/
 * Repository: https://github.com/engasm89/voice-controlled-iot-command-your-devices
 * 
 * Copyright (c) 2025 Ashraf S A AlMadhoun
 * Licensed under MIT License
 */

// Interpret simple voice commands and map to IoT actions
#include <stdio.h> // Logs
#include <string.h> // Parsing

static int device_on = 0; // Device state
static int brightness = 50; // Brightness 0..100

const char* process_command(const char *cmd) { // Process command
  if (!cmd) return "ERR"; // Null guard
  if (!strcmp(cmd, "ON")) { device_on = 1; return "OK"; } // Turn on
  if (!strcmp(cmd, "OFF")) { device_on = 0; return "OK"; } // Turn off
  if (!strncmp(cmd, "BRIGHT ", 8)) { // Set brightness
    int val = atoi(cmd + 8); // Parse value
    if (val < 0) val = 0; if (val > 100) val = 100; // Clamp
    brightness = val; return "OK"; // Apply
  } // End brightness
  return "UNKNOWN"; // Unknown
}

int main(void) { // Program entry point
  printf("Voice-Controlled IoT: Command Your Devices\n"); // Title
  const char* cmds[] = {"ON","BRIGHT 80","OFF","BRIGHT 30"}; // Sequence
  for (int i = 0; i < 4; ++i) { // Iterate
    const char* res = process_command(cmds[i]); // Execute
    printf("CMD='%s' RES='%s' STATE=%d BRIGHT=%d\n", cmds[i], res, device_on, brightness); // Log
  } // End loop
  return 0; // Exit
} // End of main function

