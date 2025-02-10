I:
cd I:\code\UEVR-
git submodule update --init --recursive
cmake -S . -B build ./build -G "Visual Studio 17 2022" -A x64 -DCMAKE_BUILD_TYPE=Release
cmake --build ./build --config Release --target uevr