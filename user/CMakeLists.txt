# 搜索对应目录下的所有文件
aux_source_directory(control control_srcs)
aux_source_directory(peripheral peripheral_srcs)
aux_source_directory(protobuf-commu protobuf_srcs)
aux_source_directory(csv-json-config-sys cfg_sys_srcs)

# 创建可执行文件
add_executable(${PROJECT_NAME} 
    main.c
    arg_parse.c
    jrpc_server.c
    ctrl_routine.c
    ${control_srcs}
    ${cfg_sys_srcs}
    ${protobuf_srcs}
    ${peripheral_srcs})

# 添加头文件搜索路径
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/config_header)

# 添加链接库
target_link_libraries(${PROJECT_NAME}
    m
    pthread
    pid
    cjson
    jsonrpc-c
    log_c
    struct2json
    csv_parser
    nanopb
    wiringpi
    wit_c_sdk
    luckfox_gpio
    ${ev})

# 拷贝框架因数配置文件
file(COPY ${PROJECT_SOURCE_DIR}/user/csv-json-config-sys/config-files/frame_factor.csv DESTINATION ${PROJECT_SOURCE_DIR}/output)
