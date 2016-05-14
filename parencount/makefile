CC           = gcc
JAVAC        = javac
LINK_FLAGS   = -lstdc++
TARGETS     += parencount
TARGETS     += parenlist
TARGETS     += paren.class

.PHONY: all
all: $(TARGETS)

.PHONY: clean
clean:
	rm -rf $(TARGETS)

%: %.cpp
	$(CC) $< $(LINK_FLAGS) -o $@

%.class: %.java
	$(JAVAC) $<
