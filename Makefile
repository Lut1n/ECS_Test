DEBUG=yes
CXX=g++

ifeq ($(DEBUG),yes)
	CXXFLAGS=-Wall -Werror -std=c++11 -g
else
	CXXFLAGS=-Wall -Werror -std=c++11
endif

### mingw64
LDFLAGS= -lbox2d -lsfgui -lsfml-graphics -lsfml-window -lsfml-system

SRCDIR=./src/
INCDIR=sfgui-0.3.2/include/ -Iinclude/
LIBDIR=sfgui-0.3.2/lib/
OBJDIR=obj
OUTPUT=TestGame.exe
SRC=$(shell find $(SRCDIR) -type f -name '*.cpp')
OBJ=$(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRC))
MKDIR=mkdir -p


all: $(OUTPUT)

$(OUTPUT): $(OBJ)
	$(CXX) -g -o $@ $^ $(LDFLAGS) -L $(LIBDIR) -I$(INCDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(OBJDIR)
	$(MKDIR) "$(@D)"
	$(CXX) $(CXXFLAGS) $(MACROS) -I$(INCDIR) -c $< -o $@

$(OBJDIR):
	$(MKDIR) $(OBJDIR)


.PHONY : clean mrproper

clean:
	rm -rf "$(OBJDIR)"