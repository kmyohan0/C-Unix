# CS 100 Programming Project

# Project Information
Winter Quarter 2020<br/>
Kevin To - 862066820<br/>
Yohan Kim - 862073880

# Introduction
R'Shell is a UNIX-based command line user interface that can handle composite lines using connectors like &&, ||, and ;. At the end of assignment, R'Shell should be able to handle composite patterns of the process and utilize them to run linux commands. To start however, we are first building our program through a composite design pattern. The inputs are taken from the user and split and divided up into the classes, whether it be a connector, executable, etc. This functionality will be done through our parser class, which will sort these into the several classes that we have. The composite design pattern that we decided to follow is shown through our implementation of a Base class, which will act as a super class for all tokens - meaning all other subclasses will inherit from the Base class. by implementing our program in a composite pattern, we hope that implementing and adding new features in the future will be efficient and simple.  

# Diagram

![Diagram for Assignment #1](https://github.com/cs100/assignment-cout-ideas/blob/master/images/R'Shell%20Assignment%201.png?raw=true)



# Class Descriptions

## __Parser__:
This class will translate user's composite inputs into executable commands for the Linux system. Essentially it means that it will branch down into commands, arguments, and connectors, and store them as a tree. After that, it will run the execute function from the root, followed by the left then right.

## __Base__:
This class is going to be a super class for all tokens. It will set up getters and setters for left and right processes, and provide a general execute function that handles all Linux commands (i.e. cd, ls, etc.)

## __Test__:
This class will handle all the test classes that we make. This class will input general test cases, edge cases, and possibly incorrect cases so that we can test the functionality of our code.

## __Executable__:
This class handles all the executables. That means it will handle all Linux commands such as cd, ls, etc.

## __Token(Connectors)__:
Token class will represent the order of the commands that a user inputs. In execution, it means that each token class will have an order of operation and also be dependent on the previous process.

  * __And__: We would require a waitPid() command because concerning the connector &&, the left process or child, must be completed before the right child is run. Similar to an if then statement, if the left child process can be completed, then run the right child process. If the left child process can't be completed, don't run the right child process. 

  * __Or__: The opposite logic of the andToken sub-class, the right process will only be prompted to run if the left process fails, as it only requires one process to be "true". Following the if then statement logic again, if the left child process can't be completed, attempt to run the right child process. 

  * __Next__: This is a class that tells the program to move onto the next process that the vector contains. If the vector is at the end of the element, then it can wait for user to input another command or exit the shell program. 

  * __Quit__: This class will be short; It will take in the user's exit command, and run exit(1) so that the while loop from the main function is exited, and end the program. 


# Prototype/Research

All prototype functions are in the prototype directory. For parsing method, we decided to use it like this: 

First, parse user input into each words.
Second, translate those words into tokens, and convert from infix to postfix.
Third, create a tree based on the postfix words. 
Fourth, run execute function from root, then left, and right.

By this way, it will be an efficient (in terms of memory and run-time) method of handling this project. Other ways (We thought of using one vector with all executions in it), will be too complicated to create an specific behaviors and outcomes, especially when handling with connectors. 

From coding prototypes of `execvp()`, `fork()`, and`waitpid()`, we was able to understand that all those codes follow each other. From my finding, we believe that we can use those functions only on our `execute()` function, and probably connector classes since those are dependent on previous processes.

Also, we've tried using connectors in shell too. We found out that first command is the one that changes the behavior of second command. That means, if we are using `||` connector and first command is successful, then whether second command is valuable or not, it will not run it. 

# Development and Testing Roadmap

To get our program to full functionality with the greatest effiency possible, the tasks ordered below need to be completed. Note that this list is extremely relative at this moment, and is subject to changes in the future as we continue to build our classes and dive further into our development process for the program. This list will include the construction of classes, as well as testing them before they are commited to our master branch. Linked below with each task will be the associated issues in GitHub.

## Designing our Base Class
This class will be essential to the functionality of our program, and is a good choice as the first development task that we need to work on. Following a composite pattern, this class will serve as a super-class to all of our tokens and because of that is required to be constructed first. 

* Creating Base class
https://github.com/cs100/assignment-cout-ideas/issues/5

* Integration Testing for Base class
https://github.com/cs100/assignment-cout-ideas/issues/9



## Parser Class

The functions of this class will be especially important in the functionality and operation of our program. This class is already being developed as a result of Assignmnent 1, and will need to be completed in Assignment 2. Because this function will be a main part and potentially the first class committed to master branch, unit testing is essential and potential changes for this class are to be anticipated. 

* Creating our Parser class 
https://github.com/cs100/assignment-cout-ideas/issues/4

## Creating our Token Classes

These token classes will be the sub-classes inheriting from the Base class and will focus on executable commands. When one token class is completed, it is important to acknowledge all possible cases that are related with each token. 

* Creating token classes

* Unit testing token classes 

* Integration Testing for our token classes 

## Create argumentList Class
Note: Could be changed, related to our executables class.

## Create Connector Class 
Note: could be changed, could just be tokens.







