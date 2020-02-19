#
# 19.02.2020 creation
#
# for Windows-cmd with mingw32
#     using  del, @echo
#
CC=g++
MAKE=mingw32-make
COPT=-Isrc/fitting -Isrc/util -DWITH_FITTING_UTILS  -Wno-write-strings -O3
LDFLAGS = -lm -s
OBJ= fitting_main.o        \
     cfitting_approxfunc.o \
     cfitting_circle.o     \
     cfitting_ellipse.o    \
     cfitting_it.o         \
     cfitting_matrix.o     \
     cfitting_plane.o      \
     cfitting_sphere.o     \
     cfitting_util.o       \
     Getopt.o              \
     iskeyword.o           \
     microtim.o            \
     mystring.o            \
     rho.o                 

fitting.exe :   $(OBJ)
				$(CC) -o bin\fitting.exe $(OBJ) $(LDFLAGS)
				@echo 'bin\fitting.exe' is built.
				
cfitting_approxfunc.o : src\fitting\cfitting_approxfunc.cpp
				$(CC) -c $< $(COPT)

cfitting_circle.o    : src\fitting\cfitting_circle.cpp
				$(CC) -c $< $(COPT)

cfitting_ellipse.o   : src\fitting\cfitting_ellipse.cpp
				$(CC) -c $< $(COPT)

cfitting_it.o        : src\fitting\cfitting_it.cpp
				$(CC) -c $< $(COPT)

cfitting_matrix.o    : src\fitting\cfitting_matrix.cpp
				$(CC) -c $< $(COPT)

cfitting_plane.o     : src\fitting\cfitting_plane.cpp
				$(CC) -c $< $(COPT)

cfitting_sphere.o    : src\fitting\cfitting_sphere.cpp
				$(CC) -c $< $(COPT)

cfitting_util.o      : src\fitting\cfitting_util.cpp
				$(CC) -c $< $(COPT)

fitting_main.o       : src\fitting\fitting_main.cpp
				$(CC) -c $< $(COPT)

Getopt.o             : src\util\Getopt.cpp
				$(CC) -c $< $(COPT)

iskeyword.o          : src\util\iskeyword.cpp
				$(CC) -c $< $(COPT)

microtim.o           : src\util\microtim.cpp
				$(CC) -c $< $(COPT)

mystring.o           : src\util\mystring.cpp
				$(CC) -c $< $(COPT)

rho.o                : src\util\rho.cpp
				$(CC) -c $< $(COPT)

rebuild :
			del $(OBJ)
			del bin\fitting.exe
			$(MAKE)