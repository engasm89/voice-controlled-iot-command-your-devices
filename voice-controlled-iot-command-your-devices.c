#include <stdio.h> // Include I/O for voice command logs

// Simulate voice command mapping to actions
void process_command(const char *cmd) { // Process voice command
  if (!cmd) { // Check null
    return; // Abort
  } // End check
  if (cmd[0] == 'O' && cmd[1] == 'N') { // ON command
    printf("Action: TURN ON\n"); // Log
  } else if (cmd[0] == 'O' && cmd[1] == 'F' && cmd[2] == 'F') { // OFF command
    printf("Action: TURN OFF\n"); // Log
  } else { // Unknown
    printf("Action: UNKNOWN (%s)\n", cmd); // Log
  } // End conditions
} // End process_command

int main(void) { // Entry
  printf("Voice-Controlled IoT: Command Your Devices\n"); // Title
  process_command("ON"); // Simulate ON
  process_command("OFF"); // Simulate OFF
  process_command("BRIGHTER"); // Simulate unknown
  return 0; // Exit
} // End main

