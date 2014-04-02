all: help
c_release:
	gcc string_lib.c util.c mystring.c -o string_lib
c_debug:
	gcc string_lib.c util.c mystring.c -o string_lib -g
cpp_release:
	g++ string_lib.cpp util.c mystring.c -o string_lib
cpp_debug:
	g++ string_lib.cpp util.c mystring.c -o string_lib -g
wc_release:
	i586-mingw32msvc-gcc string_lib.c util.c mystring.c -o string_lib.exe
wc_debug:
	i586-mingw32msvc-gcc string_lib.c util.c mystring.c -o string_lib.exe -g
wcpp_release:
	i586-mingw32msvc-g++ string_lib.cpp util.c mystring.c -o string_lib.exe
wcpp_debug:
	i586-mingw32msvc-g++ string_lib.cpp util.c mystring.c -o string_lib.exe -g
debug:
	gdb ./string_lib
run:
	./string_lib
clear:
	rm ./string_lib
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