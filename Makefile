# Variable Configuration
GCC = g++
BUILD_DIR = build
NAME = program

# Build
build: ${BUILD_DIR}/${NAME}.exe
${BUILD_DIR}/${NAME}.exe: src/entrypoint.cpp src/logic.cpp src/logic.hpp src/visualizer.cpp src/visualizer.hpp
	mkdir -p "${BUILD_DIR}"
	${GCC} "src/entrypoint.cpp" "src/logic.cpp" "src/visualizer.cpp" -o "${BUILD_DIR}/${NAME}.exe"
rebuild:
	${MAKE} clean
	${MAKE} build
run:
	${BUILD_DIR}/${NAME}.exe
clean:
	rm -rf "${BUILD_DIR}"