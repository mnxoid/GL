all: help
c_release:
	gcc binop.c -o binop
c_debug:
	gcc binop.c -o binop -g
cpp_release:
	g++ binop.cpp -o binop
cpp_debug:
	g++ binop.cpp -o binop -g
wc_release:
	i586-mingw32msvc-gcc binop.c -o binop.exe
wc_debug:
	i586-mingw32msvc-gcc binop.c -o binop.exe -g
wcpp_release:
	i586-mingw32msvc-g++ binop.cpp -o binop.exe
wcpp_debug:
	i586-mingw32msvc-g++ binop.cpp -o binop.exe -g
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
	@echo "	c_debug"
	@echo "	cpp_debug"
	@echo "	wc_release"
	@echo "	wc_debug"
	@echo "	wcpp_release"
	@echo "	wcpp_debug"
	@echo "	run"
	@echo "	debug"
	@echo "	clear"
	@echo "	commit"
	@echo "	help"