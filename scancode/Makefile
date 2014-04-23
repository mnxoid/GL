all: help
c_release:
	gcc scancode.c util.c -o scancode
c_debug:
	gcc scancode.c util.c -o scancode -g
cpp_release:
	g++ scancode.cpp util.c -o scancode
cpp_debug:
	g++ scancode.cpp util.c -o scancode -g
wc_release:
	i586-mingw32msvc-gcc scancode.c util.c -o scancode.exe
wc_debug:
	i586-mingw32msvc-gcc scancode.c util.c -o scancode.exe -g
wcpp_release:
	i586-mingw32msvc-g++ scancode.cpp util.c -o scancode.exe
wcpp_debug:
	i586-mingw32msvc-g++ scancode.cpp util.c -o scancode.exe -g
debug:
	gdb ./scancode
run:
	./scancode
clear:
	rm ./scancode
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