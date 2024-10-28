.PHONY: clean

CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
BUILD_PATH = ./build/
STACK_FILES = ./src/stack.c
TEST_FILE=./src/test.c

stack_push: stack1.o test1.o | $(BUILD_PATH)
	$(CC) $(CFLAGS) $^ -o $(BUILD_PATH)Quest_1

stack1.o: $(STACK_FILES)
	$(CC) $(CFLAGS) -DPUSH -c $(STACK_FILES) -o $@

test1.o: $(TEST_FILE)
	$(CC) $(CFLAGS) -DPUSH -c $(TEST_FILE) -o $@




stack_pop: stack2.o test2.o | $(BUILD_PATH)
	$(CC) $(CFLAGS) $^ -o $(BUILD_PATH)Quest_2

stack2.o: $(STACK_FILES)
	$(CC) $(CFLAGS) -DPOP -c $(STACK_FILES) -o $@

test2.o: $(TEST_FILE)
	$(CC) $(CFLAGS) -DPOP -c $(TEST_FILE) -o $@




stack_size: stack3.o test3.o | $(BUILD_PATH)
	$(CC) $(CFLAGS) $^ -o $(BUILD_PATH)Quest_3

stack3.o: $(STACK_FILES)
	$(CC) $(CFLAGS) -DSIZE -c $(STACK_FILES) -o $@

test3.o: $(TEST_FILE)
	$(CC) $(CFLAGS) -DSIZE -c $(TEST_FILE) -o $@




stack_clean: stack4.o test4.o | $(BUILD_PATH)
	$(CC) $(CFLAGS) $^ -o $(BUILD_PATH)Quest_4

stack4.o: $(STACK_FILES)
	$(CC) $(CFLAGS) -DCLEAN -c $(STACK_FILES) -o $@

test4.o: $(TEST_FILE)
	$(CC) $(CFLAGS) -DCLEAN -c $(TEST_FILE) -o $@




stack_empty: stack5.o test5.o | $(BUILD_PATH)
	$(CC) $(CFLAGS) $^ -o $(BUILD_PATH)Quest_5

stack5.o: $(STACK_FILES)
	$(CC) $(CFLAGS) -DEMPTY -c $(STACK_FILES) -o $@

test5.o: $(TEST_FILE)
	$(CC) $(CFLAGS) -DEMPTY -c $(TEST_FILE) -o $@


stack_top: $(STACK_FILES) $(TEST_FILE) | $(BUILD_PATH)
	$(CC) $(CFLAGS) -DTOP $^ -o $(BUILD_PATH)Quest_6

$(BUILD_PATH):
	mkdir -p $(BUILD_PATH)

clean:
	rm *.o 

clang-format:
	clang-format -i ./src/*.c
	clang-format -i ./src/*.h
