# 包含公共库
include_directories(${CMAKE_SOURCE_DIR}/Util)

add_library(SqListLib SqList.c)

# 生成可执行文件
add_executable(SqList SqList.h SqList.c SqList-main.c)

# 链接公共库
target_link_libraries(SqList CommonLib)
