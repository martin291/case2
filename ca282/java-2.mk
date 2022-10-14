
javafile = $(wildcard *.java)
classfile = $(patsubst %.java, %.class, $(javafile))

build: $(classfile)
	@true

%.class: %.java
	javac $<

#Add.class: Add.java
#	javac Add.java

