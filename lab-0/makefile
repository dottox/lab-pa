
all: Empleado.o Empresa.o EmpresaNacional.o EmpresaExtranjera.o RelacionLaboral.o main.o 
	g++ Empleado.o Empresa.o EmpresaNacional.o EmpresaExtranjera.o RelacionLaboral.o main.o -o programa

Empleado.o:
	g++ -c "definiciones/empleado/Empleado.cpp"

Empresa.o:
	g++ -c "definiciones/empresa/Empresa.cpp"

EmpresaNacional.o: Empresa.o
	g++ -c "definiciones/EmpresaNacional/EmpresaNacional.cpp"
	
EmpresaExtranjera.o: Empresa.o
	g++ -c "definiciones/EmpresaExtranjera/EmpresaExtranjera.cpp"

RelacionLaboral.o: Empresa.o Empleado.o 
	g++ -c "definiciones/RelacionLaboral/RelacionLaboral.cpp"	

main.o: 
	g++ -c "main.cpp"

clean:
	rm -f Empleado.o RelacionLaboral.o Empresa.o EmpresaNacional.o EmpresaExtranjera.o main.o programa

run:
	MinGW32-make clean
	MinGW32-make
	clear
	./programa
