all: help
c_release:
	gcc subscriptions_3.c -o subscriptions_3
c_debug:
	gcc subscriptions_3.c -o subscriptions_3 -g
#cpp_release:
	#g++ subscriptions_3.cpp -o subscriptions_3
#cpp_debug:
	#g++ subscriptions_3.cpp -o subscriptions_3 -g
wc_release:
	i586-mingw32msvc-gcc subscriptions_3.c -o subscriptions_3.exe
wc_debug:
	i586-mingw32msvc-gcc subscriptions_3.c -o subscriptions_3.exe -g
#wcpp_release:
	#i586-mingw32msvc-g++ subscriptions_3.cpp -o subscriptions_3.exe
#wcpp_debug:
	#i586-mingw32msvc-g++ subscriptions_3.cpp -o subscriptions_3.exe -g
debug:
	gdb ./subscriptions_3
run:
	./subscriptions_3
clear:
	rm ./subscriptions_3
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