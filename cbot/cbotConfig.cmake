add_library(cbot SHARED IMPORTED)
find_library(cbot_LIBRARY_PATH cbot)
set_target_properties(cbot PROPERTIES
    IMPORTED_LOCATION "${cbot_LIBRARY_PATH}"
    INTERFACE_INCLUDE_DIRECTORIES "/usr/include/cbot"
)
