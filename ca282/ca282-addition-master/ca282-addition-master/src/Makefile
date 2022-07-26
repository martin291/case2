targets  = Add.class
targets += add-c

build: $(targets)
	@true

%.class: %.java
	javac $<

%: %.c
	gcc -o $@ $<
