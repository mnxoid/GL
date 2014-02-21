all: help
c_release:
	gcc constmod.c -o constmod -fpermissive
c_debug:
	gcc constmod.c -o constmod -g -fpermissive
cpp_release:
	g++ constmod.cpp -o constmod -fpermissive
cpp_debug:
	g++ constmod.cpp -o constmod -g -fpermissive
#wc_release:
	#i586-mingw32msvc-gcc constmod.c -o constmod.exe -fpermissive
#wc_debug:
	#i586-mingw32msvc-gcc constmod.c -o constmod.exe -g -fpermissive
#wcpp_release:
	#i586-mingw32msvc-g++ constmod.cpp -o constmod.exe -fpermissive
#wcpp_debug:
	#i586-mingw32msvc-g++ constmod.cpp -o constmod.exe -g -fpermissive
debug:
	gdb ./constmod
run:
	./constmod
clear:
	rm ./constmod
commit:
	git commit -a
	git push GL
help:
	@echo "Options:"
	@echo "	c_release"
	@echo "	cpp_release"
	@echo "	c_debug"
	@echo "	cpp_debug"
	#@echo "	wc_release"
	#@echo "	wc_debug"
	#@echo "	wcpp_release"
	#@echo "	wcpp_debug"
	@echo "	run"
	@echo "	debug"
	@echo "	clear"
	@echo "	commit"
	@echo "	help"