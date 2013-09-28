OBJECTS += $(BUILD_DIR)ch-egg/library.o
OBJECTS += $(BUILD_DIR)ch-egg/execute.o
OBJECTS += $(BUILD_DIR)ch-egg/main.o
OBJECTS += $(BUILD_DIR)bbcb/sound.o
OBJECTS += $(BUILD_DIR)bbcb/mode2font.o
OBJECTS += $(BUILD_DIR)bbcb/r6502main.o


$(OBJECTS): CFLAGS += -I $(BASE)bbcb/

