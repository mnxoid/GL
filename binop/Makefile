all: help
c_release:
	gcc binop.c -o binop
c_debug:
	gcc binop.c -o binop -g
cpp_release:
	g++ binop.cpp -o binop
cpp_debug:
	g++ binop.cpp -o binop -g
debug:
	gdb ./binop
run:
	./binop
clear:
	rm ./binop
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