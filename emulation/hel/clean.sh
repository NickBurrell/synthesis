#!/bin/bash
killall qemu-system-arm;
rm -rf CMakeFiles CMakeCache.txt cmake_install.cmake Makefile CMakeDoxyfile.in CMakeDoxygenDefaults.cmake GoogleTest-prefix vm-package vm-package.tar.gz bin/tests/* build/* lib/asio lib/wpilib lib/ctre lib/lib lib/lib64 lib/GoogleTest lib/GoogleBench docs/html/* docs/latex/* vm_lock
