# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/QTPhonebook_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/QTPhonebook_autogen.dir/ParseCache.txt"
  "QTPhonebook_autogen"
  )
endif()
