all: help
c_release:
	gcc hidingtest.c -o hidingtest
c_debug:
	gcc hidingtest.c -o hidingtest -g
cpp_release:
	g++ hidingtest.cpp -o hidingtest
cpp_debug:
	g++ hidingtest.cpp -o hidingtest -g
debug:
	gdb ./hidingtest
run:
	./hidingtest
clear:
	rm ./hidingtest
commit:
	git commit -a
	git push GL
help:
	@echo "Options:"
	@echo "	c_release"
	@echo "	cpp_release"
	@echo "	c_gebug"
	@echo "	cpp_debug"
	@echo "	run"
	@echo "	debug"
	@echo "	clear"
	@echo "	commit"
	@echo "	help"