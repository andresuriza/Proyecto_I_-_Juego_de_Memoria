# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/Proyecto_I_UI_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Proyecto_I_UI_autogen.dir/ParseCache.txt"
  "Proyecto_I_UI_autogen"
  )
endif()
