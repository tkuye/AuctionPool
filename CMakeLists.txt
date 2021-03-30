cmake_minimum_required(VERSION 3.0.0)
project(AuctionPool VERSION 0.1.0)

set(SOURCE_FILES src/main.cpp)

include(CTest)
enable_testing()

link_directories(src)



ADD_LIBRARY(SrcModule
src/setAuction.cpp
src/User.cpp
src/products.cpp
src/Pool.cpp
src/Pools.cpp
src/randomNum.cpp
src/userHome.cpp
)


target_link_libraries(SrcModule)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(AuctionPool SrcModule)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
