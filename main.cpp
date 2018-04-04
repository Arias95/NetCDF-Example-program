#include <iostream>
#include <getopt.h>
#include <string>
#include "./include/read.h"
#include "./include/write.h"

void print_help()
{
    std::cout << std::endl
              << " Uso: %s [OPCIONES]" << std::endl
              << std::endl;
    std::cout << "  Options:" << std::endl;
    std::cout << "   -h --help                      Muestra este dialogo de ayuda" << std::endl;
    std::cout << "   -f --file filename             Direccion del archivo NetCDF. Debe darlo siempre de primero" << std::endl;
    std::cout << "   -r --read                      Abre el archivo y muestra su contenido." << std::endl;
    std::cout << "   -w --write            			Escribe valores de ejemplo en el archivo." << std::endl;
    std::cout << std::endl;
}

int main(int argc, char *argv[])
{
	static struct option longOptions[] = {
        {"help", no_argument, NULL, 'h'},
        {"file", required_argument, NULL, 'f'},
        {"read", no_argument, NULL, 'r'},
        {"write", no_argument, NULL, 'w'},
        {NULL, 0, NULL, 0}};

    int value;
    std::string fileAddr = "null";
    if (argc == 1)
    {
        print_help();
        return -1;
    }

    while ((value = getopt_long(argc, argv, "h:f:r:w", longOptions, NULL)) != -1)
    {
    	switch(value)
    	{
    		case 'h':
    			print_help();
    			break;
    		case 'f':
    			fileAddr = optarg;
    			break;
    		case 'r':
                if (fileAddr == "null")
                {
                    print_help();
                    return -1;
                }
                return readNC(fileAddr);
            case 'w':
                if (fileAddr == "null")
                {
                    print_help();
                    return -1;
                }
                return writeNC(fileAddr);
            case '?':
                print_help();
                return 0;
    	}
    }

}