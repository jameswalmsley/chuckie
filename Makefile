BASE=$(shell pwd)/
BUILD_BASE=$(BASE)
MODULE_NAME="chuckie-egg"

TARGETS=chuckie
BUILD_DIR=$(shell pwd)/build/
TOOLCHAIN=

include $(BASE).dbuild/dbuild.mk

CFLAGS += -Wall -O3 -I/usr/include/SDL -I.

all: chuckie
	$(Q)$(SIZE) chuckie

LDLIBS += -lSDL -lm

chuckie: $(OBJECTS)
