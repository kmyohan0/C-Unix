#!/bin/bash

echo hello; echo world  >> multiple_command_outputs
ls -a; echo world >> multiple_command_outputs
echo "hello"; ls >> multiple_command_outputs
echo hello; echo whatsup; echo ryan >> multiple_command_outputs
ls; ls -a >> multiple_command_outputs
echo "hello world"; echo again; >> multiple_command_outputs
ls -a; ls; echo FINALLY;  >> multiple_command_outputs
echo A && echo B >> connector_commands_output
echo this || echo notthis >> connector_commands_output
ls && ls -a >> connector_commands_output
echo A && echo B && echo C >> connector_commands_output
echo A || echo B || echo C >> connector_commands_output
echo correct || echo sodontoutputthis >> connector_commands_output
echa error || echo this should print >> connector_commands_output
exit >> connector_commands_output
