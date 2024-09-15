# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "release")
  file(REMOVE_RECURSE
  "CMakeFiles\\ip_tool_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\ip_tool_autogen.dir\\ParseCache.txt"
  "ip_tool_autogen"
  )
endif()
