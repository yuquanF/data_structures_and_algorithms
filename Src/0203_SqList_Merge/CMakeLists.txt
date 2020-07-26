# 包含公共库
include_directories(${CMAKE_SOURCE_DIR}/Util)
include_directories(${CMAKE_SOURCE_DIR}/Src/0201_SqList)

# 生成可执行文件
add_executable(Merge Merge.h Merge.c Merge-main.c)

# 链接公共库
target_link_libraries(Merge SqListLib CommonLib)
