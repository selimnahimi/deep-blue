# CMake generated Testfile for 
# Source directory: /home/camper/deep-blue/src
# Build directory: /home/camper/deep-blue/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(/home/camper/deep-blue/src/tests/test1 "sh" "-c" "/home/camper/deep-blue/build/test.out Pa2a3 >/home/camper/deep-blue/src/tests/test1.out")
add_test(/home/camper/deep-blue/src/tests/test1_compare "/usr/bin/cmake" "-E" "compare_files" "/home/camper/deep-blue/src/tests/test1.out" "/home/camper/deep-blue/src/tests/test1.exp")
add_test(/home/camper/deep-blue/src/tests/test2 "sh" "-c" "/home/camper/deep-blue/build/test.out Pa2a3 >/home/camper/deep-blue/src/tests/test2.out")
add_test(/home/camper/deep-blue/src/tests/test2_compare "/usr/bin/cmake" "-E" "compare_files" "/home/camper/deep-blue/src/tests/test2.out" "/home/camper/deep-blue/src/tests/test2.exp")
subdirs("lib")
