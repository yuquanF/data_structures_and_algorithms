# 包含公共库
include_directories(${CMAKE_SOURCE_DIR}/Util)
include_directories(${CMAKE_SOURCE_DIR}/Src/0201_SqList)

# 查找当前目录下的所有源文件，并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)
# 生成可执行文件
add_executable(Union ${DIR_SRCS})

# 链接公共库
target_link_libraries(Union SqListLib CommonLib)
