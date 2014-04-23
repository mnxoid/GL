all: help
c_release:
	gcc my_lib.c util.c -o my_lib
c_debug:
	gcc my_lib.c util.c -o my_lib -g
cpp_release:
	g++ my_lib.cpp util.c -o my_lib
cpp_debug:
	g++ my_lib.cpp util.c -o my_lib -g
wc_release:
	i586-mingw32msvc-gcc my_lib.c util.c -o my_lib.exe
wc_debug:
	i586-mingw32msvc-gcc my_lib.c util.c -o my_lib.exe -g
wcpp_release:
	i586-mingw32msvc-g++ my_lib.cpp util.c -o my_lib.exe
wcpp_debug:
	i586-mingw32msvc-g++ my_lib.cpp util.c -o my_lib.exe -g
debug:
	gdb ./my_lib
run:
	./my_lib
clear:
	rm ./my_lib
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