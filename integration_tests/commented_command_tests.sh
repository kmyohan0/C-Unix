
#!/bin/bash

echo #thisshouldnotshow
 >> commented_commands_outputs
echo hello  #thisshouldnotshow 
>> commented_commands_outputs
echo A && echo B #&& echo c
>> commented_commands_outputs

