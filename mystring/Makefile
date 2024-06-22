
CXX	=	cl
CXXFLAGS=	-nologo -W3 -O1 -EHsc -DNO_DEBUG
INCPATH	=	-I
LINK	=	link
REMOVE	=	-del
#LFLAGS	=	/NOLOGO /incremental:no /nodefaultlib:"libcmt" /SUBSYSTEM:windows
#LIBS	=	kernel32.lib user32.lib gdi32.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib imm32.lib winmm.lib wsock32.lib comctl32.lib
RM      =   del
HEADERS = string.h 
SOURCES = string.cpp
MAINPROGRAM = usemystring.cpp
TESTSOURCES = unittest.cpp

OBJECTS = $(SOURCES:%.cpp=%.obj)
MAINOBJECT = $(MAINPROGRAM:%.cpp=%.obj)
TESTOBJECTS = $(TESTSOURCES:%.cpp=%.obj)

TARGET	=	usemystring.exe
TESTTARGET = unittest.exe

default: $(TARGET)
all: $(TARGET) $(TESTTARGET)
test: $(TESTTARGET) 

.SUFFIXES: .cpp .cxx .cc .C .c

$(OBJECTS): $(SOURCES)
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o$@ $^

$(MAINOBJECT): $(MAINPROGRAM)
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -Fo$@ $^

$(TARGET): $(MAINOBJECT) $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(INCPATH) -Fo$@ $^



$(TESTOBJECTS): $(TESTSOURCES)
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -Fo$@ $^

$(TESTTARGET): $(TESTOBJECTS) $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(INCPATH) -Fo$@ $^

clean:
	$(RM) *.obj
	$(RM) *.exe

