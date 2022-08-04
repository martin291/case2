
javafile = $(wildcard *.java)
classfile = $(patsubst %.java, %.class, $(javafile))

build: $(classfile)
	@true

%.class: %.java
	javac $<

clean: $(classfile)
	rm -f $(classfile) *.o

.PHONY: clean
