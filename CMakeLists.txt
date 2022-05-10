cmake_minimum_required(VERSION 3.16) 


#find_package(nlohmann_json 3.10.5 REQUIRED)

#Customer.cpp Employee.cpp Interface.cpp InterfaceCreator.cpp 
add_executable(runSystem main.cpp Inventory.cpp)
#target_link_libraries(runSystem PRIVATE nlohmann_json::nlohmann_json)