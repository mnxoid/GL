all: help
c_release:
	gcc netbase_client.c util.c -o netbase
	gcc netbase_server.c -o netbase_server -lX11 -lm -lXtst
c_debug:
	gcc netbase.c util.c -o netbase -g
cpp_release:
	g++ netbase_server.cpp util.c -o netbase_server
	g++ netbase_client.cpp util.c -o netbase_client
cpp_debug:
	g++ netbase_server.cpp util.c -o netbase_server -g
	g++ netbase_client.cpp util.c -o netbase_client -g
wc_release:
	i586-mingw32msvc-gcc netbase.c util.c -o netbase.exe
wc_debug:
	i586-mingw32msvc-gcc netbase.c util.c -o netbase.exe -g
wcpp_release:
	i586-mingw32msvc-g++ netbase_server.cpp util.c -o netbase_server.exe
	i586-mingw32msvc-g++ netbase_client.cpp util.c -o netbase_client.exe
wcpp_debug:
	i586-mingw32msvc-g++ netbase_server.cpp util.c -o netbase_server.exe -g
	i586-mingw32msvc-g++ netbase_client.cpp util.c -o netbase_client.exe -g
debug:
	gdb ./netbase
run:
	echo TODO))
clear:
	rm ./netbase
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