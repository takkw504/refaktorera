CPP_COMPILER=g++

refacto_make: main.cpp interface.cpp formulas.cpp
		$(CPP_COMPILER) main.cpp interface.cpp formulas.cpp -o el_calc

run:
				el_calc.exe
