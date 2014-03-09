all: help
c_release:
	gcc hex_2.c -o hex_2
c_debug:
	gcc hex_2.c -o hex_2 -g
#cpp_release:
#	g++ hex_2.cpp -o hex_2
#cpp_debug:
#	g++ hex_2.cpp -o hex_2 -g
wc_release:
	i586-mingw32msvc-gcc hex_2.c -o hex_2.exe
wc_debug:
	i586-mingw32msvc-gcc hex_2.c -o hex_2.exe -g
#wcpp_release:
#	i586-mingw32msvc-g++ hex_2.cpp -o hex_2.exe
#wcpp_debug:
#	i586-mingw32msvc-g++ hex_2.cpp -o hex_2.exe -g
debug:
	gdb ./hex_2
run:
	./hex_2
clear:
	rm ./hex_2
commit:
	git commit -a
	git push GL
help:
	@echo "Options:"
	@echo "	c_release"
#	@echo "	cpp_release"
	@echo "	c_debug"
#	@echo "	cpp_debug"
	@echo "	wc_release"
	@echo "	wc_debug"
#	@echo "	wcpp_release"
#	@echo "	wcpp_debug"
	@echo "	run"
	@echo "	debug"
	@echo "	clear"
	@echo "	commit"
	@echo "	help"