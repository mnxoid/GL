all: help
c_release:
	gcc helper.c util.c -o helper
c_debug:
	gcc helper.c util.c -o helper -g
cpp_release:
	g++ helper.cpp util.c -o helper
cpp_debug:
	g++ helper.cpp util.c -o helper -g
wc_release:
	i586-mingw32msvc-gcc helper.c util.c -o helper.exe
wc_debug:
	i586-mingw32msvc-gcc helper.c util.c -o helper.exe -g
wcpp_release:
	i586-mingw32msvc-g++ helper.cpp util.c -o helper.exe
wcpp_debug:
	i586-mingw32msvc-g++ helper.cpp util.c -o helper.exe -g
debug:
	gdb ./helper
run:
	./helper
clear:
	rm ./helper
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