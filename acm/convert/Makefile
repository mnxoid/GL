all: help
c_release:
	gcc convert.c util.c -o convert
c_debug:
	gcc convert.c util.c -o convert -g
cpp_release:
	g++ convert.cpp util.c -o convert
cpp_debug:
	g++ convert.cpp util.c -o convert -g
wc_release:
	i586-mingw32msvc-gcc convert.c util.c -o convert.exe
wc_debug:
	i586-mingw32msvc-gcc convert.c util.c -o convert.exe -g
wcpp_release:
	i586-mingw32msvc-g++ convert.cpp util.c -o convert.exe
wcpp_debug:
	i586-mingw32msvc-g++ convert.cpp util.c -o convert.exe -g
debug:
	gdb ./convert
run:
	./convert
clear:
	rm ./convert
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