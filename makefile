name = fractionfinder

$(name):
	gcc -O2 -Wall -Wextra $(name).c -o $(name)

clean:
	rm $(name)
