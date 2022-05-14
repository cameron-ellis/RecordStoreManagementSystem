# Record Store Management System
A terminal based management app specialized for record stores. Has employee and customer logins. Uses the library [Json for Modern C++ by nlohmann](https://github.com/nlohmann/json) for dealing with Inventory stock. Built and developed on WSL2 Ubuntu version 20.04, Docker container also built on Ubuntu version 20.04.
## Docker Container Instructions:
Docker containter can be built using provided Dockerfile
Alternatively dockerhub repo with image provided: [Dockerhub](https://hub.docker.com/repository/docker/coryhaberberger/record-store-management-system)

 - **List item**
## Inventory Class Description:
 - **The foundational code that handles the operations on the system inventory.**
 - **Implemented as a singleton so that only one shared inventory can be in exist at a time.**
 - **Inventory file works using Inventory.json to first load in the inventory. When the inventory is destroyed it exports the current inventory to the same file.**
 - **Json file operation performed using the external library [Json for Modern C++ by nlohmann]**
## Menu Class Description:
### Menu Functions:
 - **List item**
## Customer and Employee Interface Class Description:
### Customer and Employee Interface Functions:
 - **List item**
## Testing, Coverage, and Memory Leak Checking:
## Link to YouTube Video of Demo:

## Team Members:
- **Cameron**
- **Chandler Tabor**
- **Cory**

## Dependencies:

## How to run:

# Program Usage:
- **Upon program start, user will be prompted to log in as a Customer or Employee.**
- **Once a selection has been made, the user can do various actions based on the prompts on the screen, such as searching the inventory, making a purchase, or adding an item depending on the options chosen.**
- **Users can log out and log back into a different option at any time, without stopping the program.**
- **Reciepts are printed after purchase inside the directory the program was ran.**

# Locally run:
- **After cloning the repository, the main program is ran out of the build directory.**
- **Navigate to the build directory and run 'cmake ..' to update the make file, then run 'make' to compile the program.**
- **Run the command './runSystem' to start the program. From there the main menu will pop up with the possible options.**

# Testing directory:
- **Directory used to run system tests as well as gcov. Run the following commands to perform the tests:**
- **make**
- **make run**
- **make gcov**
- **After the commands above are run, the testing results and the the gcov results will be printed.**

# Docker:
- Docker containter can be built using provided Dockerfile
Alternatively dockerhub repo with image provided: [Dockerhub](https://hub.docker.com/repository/docker/coryhaberberger/record-store-management-system)
Since this is a terminal application, "run interactive" will need to be selected in order to use program with docker.
