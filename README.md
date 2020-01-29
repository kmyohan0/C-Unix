# CS 100 Programming Project

##Introduction

R'Shell is a UNIX-based user interface that can handle composite lines using connectors like &&, ||, and ;. At the end of assignment, R'Shell should be able to handle composite patterns of the process and utilize them to run linux commands.


##Diagram 



##Class Descriptions

__Parser__

This class will translate user's composite inputs into executable commands for the Linux system. Essentially it means that it will branch down into commands, arguments, and connectors, and store them as a tree. After that, it will run the execute function from the root, followed by the left then right.

__Base__

This class is going to be a super class for all tokens. It will set up getters and setters for left and right processes, and provide a general execute function that handles all Linux commands (i.e. cd, ls, etc.)

__Test__

__Executable__

__Token(Connectors)__

Token class will represent the order of the commands that a user inputs. In execution, it means that each token class will have an order of operation and also be dependent on the previous process.




##Prototype/Research

##Roadmap / Development

1. Design base class
2. Create token classes (simple ones such as executable commands)
    a. Be as thoughtful as possible when creating execute function.
    b. When one token is done, create all possible cases that are related with that token. 
    c. Utilize how linux error code with our project
3. Create Parser class
    a. Make sure to understand how input and output from Linux to cpp or vice versa so that we can take / print exact data that we want. 
4. Create argumentList Class
    a. Understand which arguments can fit into our executable commands. 
5. Create Connector
    a. Probably one of the hardest classes, so make sure to create a test case for each small functions.

