# created with boroveen/automake

all: cookie

cookie:
	g++ main.cpp -o cookie
	mkdir ~/.config/cookie
	touch ~/.config/cookie/cookie.txt
	touch ~/.config/cookie/time.txt

install:
	sudo cp cookie /bin

uninstall:
	rm -rf ~/.config/cookie
	sudo rm /bin/cookie
