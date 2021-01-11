add_library(cbot STATIC IMPORTED)
find_library(CBOT_LIBRARY_PATH cbot HINTS "${CMAKE_CURRENT_LIST_DIR}/../../")
set_target_properties(cbot PROPERTIES IMPORTED_LOCATION "${CBOT_LIBRARY_PATH}")
