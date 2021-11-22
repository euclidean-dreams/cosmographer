file(REMOVE_RECURSE
  "libsocket.a"
  "libsocket.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang C)
  include(CMakeFiles/socket_int.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
