all: help
c_release:
	gcc onetoten.c -o onetoten
c_debug:
	gcc onetoten.c -o onetoten -g
cpp_release:
	g++ onetoten.cpp -o onetoten
cpp_debug:
	g++ onetoten.cpp -o onetoten -g
debug:
	gdb ./onetoten
run:
	./onetoten
clear:
	rm ./onetoten
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