cmake_minimum_required(VERSION 3.10) 

#find_package(nlohmann_json 3.10.5 REQUIRED)

add_executable(runSystem main.cpp Customer.cpp Employee.cpp Inventory.cpp RecordInterfaceFactory.cpp)
#target_link_libraries(runSystem PRIVATE nlohmann_json::nlohmann_json)