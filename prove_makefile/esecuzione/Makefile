#definisco le variabili
C=gcc

#rule head: ci metto la radice dell'albero: <head>: <dipendenze>
all:    programma.exe

file1.o : ../file1.cpp ../file1.h
	$(C) -c  ../file1.cpp -o  file1.o
file2.o : ../file2.cpp ../file2.h  ../file1.h
	$(C) -c  ../file2.cpp -o file2.o
file3.o : ../file3.cpp ../file3.h
	$(C) -c  ../file3.cpp -o file3.o
#qua ci vanno le file.o
programma.exe : file1.o file2.o file3.o
	$(C) file1.o file2.o file3.o -o programma.exe
clean: 
	rm -f *.o *~ programma.exe