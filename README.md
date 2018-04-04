# NetCDF Example-Program
Programa que lee y escribe en archivos NetCDF

## Requisitos
* [CMake](https://cmake.org/download/) 3.6 o superior.
* [HDF5](https://support.hdfgroup.org/HDF5/release/obtainsrc518.html)
* [NetCDF para C](https://github.com/Unidata/netcdf-c)
* [NetCDF para C++](https://github.com/Unidata/netcdf-cxx4)

## Compilar
Para compilar, solamente ejecute los siguientes comandos:
```
mkdir build && cd build
cmake ..
make
```

El ejecutable resultante se encontrara en `build`.

Se provee el archivo `simple_xy.nc` como ejemplo.

## Uso
```
Uso: %s [OPCIONES]

  Options:
   -h --help                 Muestra este dialogo de ayuda
   -f --file filename        Direccion del archivo NetCDF. Debe darlo siempre de primero
   -r --read                 Abre el archivo y muestra su contenido.
   -w --write       			   Escribe valores de ejemplo en el archivo.
```

## Errores comunes

### No es posible enlazar alguna biblioteca
Las bibliotecas de NetCDF y NetCDF-CXX son dinamicas, eso quiere decir que son buscadas por el sistema operativo en una direccion dada, dicha direccion se define en la linea `link_directories(/usr/local/lib)` del archivo `CMakeLists.txt`. En caso de haber instalado dichas bibliotecas en una direccion diferente a `/usr/local/lib`, nada mas cambie la linea anteriormente mencionada con la direccion de sus bibliotecas.
