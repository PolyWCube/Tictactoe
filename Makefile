# Variable Configuration
GCC = g++
SRC_DIR = src
BUILD_DIR = build
NAME = program

# Build
build: ${BUILD_DIR}/${NAME}.exe
${BUILD_DIR}/${NAME}.exe: $(SRC_DIR)/entrypoint.cpp $(SRC_DIR)/logic.cpp $(SRC_DIR)/logic.hpp $(SRC_DIR)/visualizer.cpp $(SRC_DIR)/visualizer.hpp
	mkdir ${BUILD_DIR}
	${GCC} ${SRC_DIR}/entrypoint.cpp $(SRC_DIR)/logic.cpp $(SRC_DIR)/visualizer.cpp -o ${BUILD_DIR}/${NAME}.exe
rebuild:
	${MAKE} clean
	${MAKE} build
run:
	${BUILD_DIR}/${NAME}.exe
clean:
	rm -rf ${BUILD_DIR}