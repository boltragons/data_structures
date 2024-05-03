FLAGS := -g -O0 -Iinclude

.PHONY: clean

all: build/ bin/ bin/list

bin/list: build/main.o build/list.o
	${CC} $^ -o $@ 

build/main.o: source/main.c include/list.h
	${CC} ${FLAGS} -c $< -o $@ 

build/%.o: source/%.c include/%.h
	${CC} ${FLAGS} -c $< -o $@ 

%/:
	mkdir -p $@

clean:
	rm build/* bin/*

distclean:
	rm -rf build bin
