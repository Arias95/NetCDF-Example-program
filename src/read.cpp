#include <iostream>
#include <netcdf>
#include <string>
// Estamos leyendo datos en 2D, en una matriz de 6 x 12. 
static const int NX = 6;
static const int NY = 12;

// En caso de un problema devuelva este valor.
static const int NC_ERR = 2;

int readNC(std::string file)
{
	try
   	{
    	// Arreglo en el cual leeremos los datos.
		int dataIn[NX][NY]; 

		// Abrir archivo con permisos de lectura.
		netCDF::NcFile dataFile(file, netCDF::NcFile::read);

		// Obtiene la variable "data" dentro del archivo.
		netCDF::NcVar data = dataFile.getVar("data");
		if (data.isNull()) return NC_ERR; // Si esta vacia, indica error.
		// Guarda los datos leido en "data" en el arreglo dataIn.
		data.getVar(dataIn);

   		// Revisamos variables una por una. 
		for (int i = 0; i < NX; i++)
		{
			for (int j = 0; j < NY; j++)
			{
				std::cout << dataIn[i][j] << " ";
			}
			std::cout << std::endl;
		}

		// El archivo netCDF es automaticamente cerrado por el dectructor de NcFile
		return 0;
	}
	catch(netCDF::exceptions::NcException& e)
	{
		std::cout << "Error al leer archivo: " << e.what() << std::endl;
		return NC_ERR;
	}
}
