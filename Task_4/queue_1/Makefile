all: help
c_release:
	gcc queue_1.c -o queue_1
c_debug:
	gcc queue_1.c -o queue_1 -g
cpp_release:
	g++ queue_1.cpp -o queue_1
cpp_debug:
	g++ queue_1.cpp -o queue_1 -g
wc_release:
	i586-mingw32msvc-gcc queue_1.c -o queue_1.exe
wc_debug:
	i586-mingw32msvc-gcc queue_1.c -o queue_1.exe -g
wcpp_release:
	i586-mingw32msvc-g++ queue_1.cpp -o queue_1.exe
wcpp_debug:
	i586-mingw32msvc-g++ queue_1.cpp -o queue_1.exe -g
debug:
	gdb ./queue_1
run:
	./queue_1
clear:
	rm ./queue_1
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