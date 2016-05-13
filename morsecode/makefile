CC        = g++
FLAGS     =
SOURCE    = morsecode.cpp
TARGETS  += morsecode


.PHONY: all
all: $(TARGETS)

.PHONY: clean
clean:
	rm $(TARGETS)

%: %.cpp
	$(CC) $< -o $@
