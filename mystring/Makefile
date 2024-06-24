
CXX	=	cl
CXXFLAGS=	-nologo -W3 -O1 -EHsc -DNO_DEBUG
INCLUDE	=	-Iinclude -I"C:\Program Files (x86)\Microsoft Visual Studio\2019\Professional\VC\Tools\MSVC\14.29.30133\include" -I"C:\Program Files (x86)\Windows Kits\10\Include\10.0.22000.0\ucrt"

SOURCE_DIR = src
TEST_DIR = test
OBJ_DIR = bin

#commands
RM      =   del /Q
RMDIR   =   rmdir


HEADERS = string.h 
SOURCES = $(SOURCE_DIR)/string.cpp
MAINPROGRAM = $(SOURCE_DIR)/usemystring.cpp
TESTSOURCES = $(TEST_DIR)/unittest.cpp

OBJECTS := $(patsubst $(SOURCE_DIR)/%.cpp, $(OBJ_DIR)/%.obj, $(SOURCES))

MAINOBJECT := $(patsubst $(SOURCE_DIR)/%.cpp, $(OBJ_DIR)/%.obj, $(MAINPROGRAM))

TESTOBJECTS := $(patsubst $(SOURCE_DIR)/%.cpp, $(OBJ_DIR)/%.obj, $(TESTSOURCES))

TARGET	=	$(OBJ_DIR)/usemystring.exe
TESTTARGET = $(OBJ_DIR)/unittest.exe

$(OBJECTS) $(MAINOBJECT) $(TESTOBJECTS): | $(OBJ_DIR)
$(OBJ_DIR):
	mkdir $(OBJ_DIR)

default: $(TARGET)
all: $(TARGET) $(TESTTARGET)
test: $(TESTTARGET) 

$(OBJECTS): $(SOURCES)
	$(CXX) -c $(CXXFLAGS) $(INCLUDE) /Fo$@ $^

$(MAINOBJECT): $(MAINPROGRAM)
	$(CXX) -c $(CXXFLAGS) $(INCLUDE) /Fo$@ $^

$(TARGET): $(MAINOBJECT) $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(INCLUDE) /Fo$@ $^

$(TESTOBJECTS): $(TESTSOURCES)
	$(CXX) -c $(CXXFLAGS) $(INCLUDE) /Fo$@ $^

$(TESTTARGET): $(TESTOBJECTS) $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(INCLUDE) /Fo$@ $^

clean:
	$(RM) *.exe
	$(RM) $(OBJ_DIR)
	$(RMDIR) $(OBJ_DIR)
	
	
info:
	@echo [*] Object dir:     ${OBJ_DIR}
	@echo [*] Sources:        ${SOURCE_DIR}
	@echo [*] Objects:        ${OBJECTS}
