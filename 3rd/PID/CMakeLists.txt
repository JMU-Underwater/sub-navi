project(pid)

add_library(${PROJECT_NAME}
            pid.c)

target_include_directories( ${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)
