all: help
c_release:
	gcc medic_6.c -o medic_6
c_debug:
	gcc medic_6.c -o medic_6 -g
#cpp_release:
	#g++ medic_6.cpp -o medic_6
#cpp_debug:
	#g++ medic_6.cpp -o medic_6 -g
wc_release:
	i586-mingw32msvc-gcc medic_6.c -o medic_6.exe
wc_debug:
	i586-mingw32msvc-gcc medic_6.c -o medic_6.exe -g
#wcpp_release:
	#i586-mingw32msvc-g++ medic_6.cpp -o medic_6.exe
#wcpp_debug:
	#i586-mingw32msvc-g++ medic_6.cpp -o medic_6.exe -g
debug:
	gdb ./medic_6
run:
	./medic_6
clear:
	rm ./medic_6
commit:
	git commit -a
	git push GL
help:
	@echo "Options:"
	@echo "	c_release"
	#@echo "	cpp_release"
	@echo "	c_debug"
	#@echo "	cpp_debug"
	@echo "	wc_release"
	@echo "	wc_debug"
	#@echo "	wcpp_release"
	#@echo "	wcpp_debug"
	@echo "	run"
	@echo "	debug"
	@echo "	clear"
	@echo "	commit"
	@echo "	help"