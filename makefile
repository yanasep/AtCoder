a.out: ${ARG}
	g++ ${ARG} -g -Wall -Wextra -fsanitize=undefined -std=gnu++17 -O0

.PHONY: test
test: a.out
	./a.out < ${IN}