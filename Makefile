APP_NAME = game
TEST_NAME = test
cc = gcc

pref_src = ./src/
pref_obj = ./obj/
pref_test_obj = ./test2/obj/
pref_test_src = ./test2/src/

TEST_PATH = bin/$(TEST_NAME)
APP_PATH = bin/$(APP_NAME)



src = $(wildcard $(pref_src)*.c)
obj = $(patsubst $(pref_src)%.c, $(pref_obj)%.o, $(src))
test_src = $(wildcard $(pref_test_src)*.c)
test_obj = $(patsubst $(pref_test_src)%.c, $(pref_test_obj)%.o, $(test_src))


$(APP_NAME): $(APP_PATH)
$(APP_PATH) : $(obj)
	$(cc) $(obj) -o $(APP_PATH)

$(pref_obj)%.o : $(pref_src)%.c
	$(cc) -c $< -o $@

.PHONY: $(TEST_NAME)
$(TEST_NAME): $(TEST_PATH)

$(TEST_PATH) : $(test_obj)
	$(cc) $(test_obj) -o $(TEST_PATH)

$(pref_test_obj)%.o : $(pref_test_src)%.c
	$(cc) -c $< -o $@


.PHONY: clean
clean :
	rm -rf $(APP_PATH) $(pref_obj)*.o
	rm -rf $(TEST_PATH) $(pref_test_obj)*.o

run_test:
	-$(TEST_PATH)