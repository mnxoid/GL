all: help
c_release:
	gcc lolcode.c util.c -o lolcode
c_debug:
	gcc lolcode.c util.c -o lolcode -g
cpp_release:
	g++ lolcode.cpp util.c -o lolcode
cpp_debug:
	g++ lolcode.cpp util.c -o lolcode -g
wc_release:
	i586-mingw32msvc-gcc lolcode.c util.c -o lolcode.exe
wc_debug:
	i586-mingw32msvc-gcc lolcode.c util.c -o lolcode.exe -g
wcpp_release:
	i586-mingw32msvc-g++ lolcode.cpp util.c -o lolcode.exe
wcpp_debug:
	i586-mingw32msvc-g++ lolcode.cpp util.c -o lolcode.exe -g
debug:
	gdb ./lolcode
run:
	./lolcode
clear:
	rm ./lolcode
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