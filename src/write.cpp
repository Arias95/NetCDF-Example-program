#include <iostream>
#include <netcdf>
#include <vector>
#include <string>

// Estamos leyendo datos en 2D, en una matriz de 6 x 12. 
static const int NX = 6;
static const int NY = 12;

// En caso de un problema devuelva este valor.
static const int NC_ERR = 2;

int writeNC(std::string file)
{
	// Matriz que llenaremos con datos.
	int dataOut[NX][NY];
  
	// Generamos unos datos:
	for(int i = 0; i < NX; i++)
	{
		for(int j = 0; j < NY; j++)
		{
			dataOut[i][j] = i * NY + j;
		}	
	}
   
	try
    {  
		// Creamos el archivo, se sobreescribe si ya existe.
		netCDF::NcFile dataFile(file, netCDF::NcFile::replace);
      
		// Creamos las dimensiones deseadas
		netCDF::NcDim xDim = dataFile.addDim("x", NX);
		netCDF::NcDim yDim = dataFile.addDim("y", NY);
      
		// Definimos el tipo de varible. En este caso es un ncInt (32-bit integer).
		std::vector<netCDF::NcDim> dims;
		dims.push_back(xDim);
		dims.push_back(yDim);
		netCDF::NcVar data = dataFile.addVar("data", netCDF::ncInt, dims);
   
		// Escribimos todos los datos en la matriz que creamos anteriormente.
		data.putVar(dataOut);
      
		// El archivo netCDF es automaticamente cerrado por el dectructor de NcFile
		return 0; 
	}
	catch(netCDF::exceptions::NcException& e)
    {
    	std::cout << e.what() << std::endl;
		return NC_ERR;
	}
}
