Target = game
cc = gcc

pref_src = ./src/
pref_obj = ./obj/

src = $(wildcard $(pref_src)*.c)
obj = $(patsubst $(pref_src)%.c, $(pref_obj)%.o, $(src))

$(Target) : $(obj)
	$(cc) $(obj) -o $(Target)

$(pref_obj)%.o : $(pref_src)%.c
	$(cc) -c $< -o $@

clean :
	rm $(Target) $(pref_obj)*.o
