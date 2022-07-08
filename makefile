OUT:=bin
CPP_COMPILER:=g++ -std=c++17
C_COMPILER:=gcc -std=gnu17
SOURCE:=source/
TEST:=test/

LIBRARY_FLAGS:=-fPIC -shared
DEBUG_FLAGS:=-Wall -g -ggdb -fsanitize=address
DYNAMIC:= -rdynamic
HEADERS_DIR = include/
INC:=-I $(HEADERS_DIR)

all: hidraw-linux-util libs

dir:
	mkdir -p $(OUT)

build_c_debug: $(SOURCE)/$(NAME).c | dir
	$(C_COMPILER) $(DEBUG_FLAGS) $(INC)  $(SOURCE)$(NAME).c $(LIBS) $(EXTRA) -o $(OUT)/$(NAME)

build_test_c_debug: $(TEST)/$(NAME).c | dir
	$(C_COMPILER) $(DEBUG_FLAGS) $(INC) $(TEST)$(NAME).c $(LIBS) $(EXTRA) -o $(OUT)/$(NAME)

build_c_debug_lib: $(SOURCE)/$(NAME).c | dir
	$(C_COMPILER) $(DEBUG_FLAGS) -shared $(DYNAMIC) $(LIBRARY_FLAGS) $(INC) $(SOURCE)$(NAME).c $(LIBS) $(EXTRA) -o $(OUT)/$(LIB_NAME).so


############################
libs: hid-descriptor-lib hidraw-linux-lib

test: test-hid-descriptor-lib test-hidraw-linux-lib

hid-descriptor-lib:
	make NAME=hid-descriptor LIB_NAME="lib.hid.descriptor" build_c_debug_lib

test-hid-descriptor-lib: hid-descriptor-lib
	make NAME=test-hid-descriptor LIBS="$(OUT)/lib.hid.descriptor.so" build_test_c_debug

hidraw-linux-lib:
	make NAME=hidraw-linux LIB_NAME="lib.hid.rawlinux" build_c_debug_lib

test-hidraw-linux-lib: hidraw-linux-lib
	make NAME=test-hidraw-linux LIBS="$(OUT)/lib.hid.rawlinux.so" build_test_c_debug

hidraw-linux-util: hid-descriptor-lib
	make NAME=hidraw-linux-util EXTRA="-rdynamic -ldl" build_c_debug
