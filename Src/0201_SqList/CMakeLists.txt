# 包含公共库
include_directories(${CMAKE_SOURCE_DIR}/Util)

# add_library 默认生成是静态库，在 Linux 下是 libSqListLib.a;在 Windows 下是 SqListLib.lib
add_library(SqListLib SqList.c)

# 生成可执行文件--方法一
#add_executable(SqList SqList.c SqList-main.c)

# 生成可执行文件--方法二
# 查找当前目录下的所有源文件，并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)
# 生成可执行文件
add_executable(SqList ${DIR_SRCS})

# 链接公共库
target_link_libraries(SqList CommonLib)
