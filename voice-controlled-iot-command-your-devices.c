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

int main(void) { // Entry
  printf("Voice-Controlled IoT: Command Your Devices\n"); // Title
  const char* cmds[] = {"ON","BRIGHT 80","OFF","BRIGHT 30"}; // Sequence
  for (int i = 0; i < 4; ++i) { // Iterate
    const char* res = process_command(cmds[i]); // Execute
    printf("CMD='%s' RES='%s' STATE=%d BRIGHT=%d\n", cmds[i], res, device_on, brightness); // Log
  } // End loop
  return 0; // Exit
} // End main

