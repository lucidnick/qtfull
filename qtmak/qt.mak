#https://gist.github.com/mishurov/8134532
CC=g++
MOC=moc-qt4
CFLAGS=-Wall
SOURCES=hello.cc hello_cls.cc
MOC_HEADERS=hello_cls.h
EXECUTABLE=hello
INCDIRS=-I/usr/include/qt4 -I/usr/include/qt4/QtGui -I/usr/include/qt4/QtCore
LIBS=-lQtCore -lQtGui
# Change postfixes
MOC_SOURCES=$(MOC_HEADERS:.h=.moc.cc)
OBJECTS=$(SOURCES:.cc=.o) $(MOC_SOURCES:.cc=.o)

all: $(EXECUTABLE)
	@echo Done!

$(EXECUTABLE): $(OBJECTS)
	$(CC) $^ $(LIBS) -o $@

# Generate object files, rule to change postfix
%.o: %.cc
	$(CC) $(CFLAGS) $(INCDIRS) -c $< -o $@

# Generate cc from h via Qt's Meta Object Compiler, rule to change postfix
%.moc.cc: %.h
	$(MOC) $(INCDIRS) $< -o $@

.PHONY: tags clean

clean:
	rm *.o

# Generate ctags file for all included files (autocomplete and jump to source)
tags:
	gcc -M $(INCDIRS) $(SOURCES) | \
	sed -e 's/[\\ ]/\n/g' | \
	sed -e '/^$$/d' -e '/\.o:[ \t]*$$/d' | \
	ctags -L - --c++-kinds=+p --fields=+iaS --extra=+q
