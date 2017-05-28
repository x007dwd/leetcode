project(leetcode)

add_executable(leetcode main.cpp)

add_executable(ReExp ReExp.cpp)

add_executable(FlatBinTree FlatBinTree.cpp)

add_executable(rmLinkList rmLinkList.cpp)

install(TARGETS leetcode RUNTIME DESTINATION bin)
