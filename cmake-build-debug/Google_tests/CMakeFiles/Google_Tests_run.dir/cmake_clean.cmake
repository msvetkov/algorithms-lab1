file(REMOVE_RECURSE
  "Google_Tests_run.pdb"
  "Google_Tests_run.exe"
  "Google_Tests_run.exe.manifest"
  "libGoogle_Tests_run.dll.a"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/Google_Tests_run.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
