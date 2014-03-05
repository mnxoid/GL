all: help
c_release:
	gcc localtest.c -o localtest
c_debug:
	gcc localtest.c -o localtest -g
cpp_release:
	g++ localtest.cpp -o localtest
cpp_debug:
	g++ localtest.cpp -o localtest -g
wc_release:
	i586-mingw32msvc-gcc localtest.c -o localtest.exe
wc_debug:
	i586-mingw32msvc-gcc localtest.c -o localtest.exe -g
wcpp_release:
	i586-mingw32msvc-g++ localtest.cpp -o localtest.exe
wcpp_debug:
	i586-mingw32msvc-g++ localtest.cpp -o localtest.exe -g
debug:
	gdb ./localtest
run:
	./localtest
clear:
	rm ./localtest
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