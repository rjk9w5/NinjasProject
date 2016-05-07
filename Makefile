###############################################################################
# -->Makefile<--
###############################################################################

###############################################################################
#
# Programmer :  Russley Shaw
# Modified by:  Russley Shaw
# Assignment :  Program 6
#
# Instructor :  Clayton Price
# Course     :  CS5201
# Semester   :  Spring 2016
#
###############################################################################

###############################################################################
# This makefile will build an executable for the assignment.
###############################################################################

.PHONY: all clean depend_tester depend_driver

# Uncomment this to use g++. clang++ was found to be noticably faster for this
# project with -O3 flag compared to g++ with either -O3 or -Ofast flags...
# CXX = g++
CXX = clang++

### Flags
CXXFLAGS = -g -O3 -Wall -Wextra -W -pedantic-errors -std=c++11

### Compiler includes
CXX_INCLUDES = . include RLib
CXX_INCLUDES := $(addprefix -I, $(CXX_INCLUDES))

### Directories
OBJECTS_DIR = obj
SOURCES_DIR = src
INCLUDES_DIR = include
TESTS_DIR = tests

### Source files (.cpp)
ALL_SOURCES  := $(wildcard $(SOURCES_DIR)/*.cpp)
DRIVER_SOURCES := $(filter-out $(SOURCES_DIR)/tester.cpp, $(ALL_SOURCES) )
TESTER_SOURCES := $(filter-out $(SOURCES_DIR)/driver.cpp, $(ALL_SOURCES) )

### Include files (.h) (.hpp)
HEADERS_H := $(wildcard $(INCLUDES_DIR)/*.h)
HEADERS_HPP := $(wildcard $(SOURCES_DIR)/*.hpp)

TESTERS_H := $(wildcard $(TESTS_DIR)/*.h)

### Object files
DRIVER_OBJECTS := $(DRIVER_SOURCES:$(SOURCES_DIR)/%.cpp=$(OBJECTS_DIR)/%.o)
TESTER_OBJECTS := $(TESTER_SOURCES:$(SOURCES_DIR)/%.cpp=$(OBJECTS_DIR)/%.o)

### Executable names
DRIVER_EXE = driver
TESTER_EXE = tester

################################################################################
# Targets
################################################################################

all: drive test

### Default target
default: drive

drive: $(DRIVER_EXE)

test: $(TESTER_EXE)
	./$(TESTER_EXE)

callgrind: $(TESTER_EXE)
	valgrind --tool=callgrind ./$(TESTER_EXE)

### Main targets
$(TESTER_EXE): $(TESTER_OBJECTS) $(TESTERS_H)
	@ echo "======== Building $@..."
	$(CXX) $(CXXFLAGS) $(TESTER_OBJECTS) -o $@
	@ echo "======== Built $@!"
	@ echo ""

$(DRIVER_EXE): $(DRIVER_OBJECTS)
	@ echo "======== Building $@..."
	$(CXX) $(CXXFLAGS) $(DRIVER_OBJECTS) -o $@
	@ echo "======== Built $@!"
	@ echo ""

### Directory creation
$(OBJECTS_DIR)/:
	@ echo "======== Making $@ dir..."
	mkdir $(OBJECTS_DIR)
	@ echo "======== Made $@ dir!"
	@ echo ""

$(OBJECTS_DIR)/%.o: $(OBJECTS_DIR)/ $(SOURCES_DIR)/%.cpp
	@ echo "======== Building $@..."
	$(CXX) $(CXXFLAGS) $(CXX_INCLUDES) -c $(word 2, $^) -o $@
	@ echo "======== Built $@!"
	@ echo ""

### Clean
clean:
	@ echo "======== Cleaning up..."
	- rm -f core
	- rm -f $(DRIVER_EXE)
	- rm -f $(TESTER_EXE)
	- rm -f depend_driver
	- rm -f depend_tester
	- rm -f $(DRIVER_OBJECTS)
	- rm -f $(TESTER_OBJECTS)
	- rm -f callgrind.out.*
	@ echo "======== Cleaned!"
	@ echo ""

# Automatically generate dependencies and include them in Makefile
depend_driver:
	@ echo "======== Generating $@..."
	$(CXX) -std=c++11 -MM $(CXX_INCLUDES) $(DRIVER_SOURCES) > $@
	@ echo "======== Generated $@!"
	@ echo ""

# Automatically generate dependencies and include them in Makefile
depend_tester:
	@ echo "======== Generating $@..."
	$(CXX) -std=c++11 -MM $(CXX_INCLUDES) $(TESTER_SOURCES) > $@
	@ echo "======== Generated $@!"
	@ echo ""

-include depend_driver
-include depend_tester
# Put a dash in front of include when using gnu make.
# It stops gmake from warning us that the file
# doesn't exist yet, even though it will be properly
# made and included when all is said and done.
