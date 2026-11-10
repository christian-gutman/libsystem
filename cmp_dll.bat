rmdir /s /q build
cmake -S src/system -B build -A Win32
cmake --build build --config Release
rmdir /s /q build