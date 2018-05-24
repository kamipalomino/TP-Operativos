#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>


 //Compiler version gcc 6.3.0


//unsigned long int htonl (unsigned long int hostlong);
//unsigned short int htons (unsigned long int hostshort);
//unsigned long int ntonl (unsigned long int netlong);
//unsigned long int ntons (unsigned long int netshort);


#define ip "127.0.0.1"
#define puerto 8000
/* --------------------FUNCIOMES------------------------------------  */
	int socket (int dominio, int tipo, int protocolo);
	// intbind( int sockfd, struct sockaddr *my_addr, int addrlen);
//	int bind( sockfd, (struct sockaddr *) &sin, sizeof(sin));

	int listen(int sockfd, int backlog);
//	int read();
	//int write();
	int shutdown(int sockfd, int how);
	int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
	int close(int fd);
	int connect(int sockfd, const struct sockaddr *serv_addr, socklen_t addrlen); 


	size_t send(int s, const void *buf, size_t len, int flags);
	size_t recv(int s, void *buf, size_t len, int flags);
	int gethostname ( char *hostname, size_t size);

	

/*--------------------ESTRUCTURAS--------------------------*/



	struct sockaddr{
		unsigned short sa_family;
		char sa_data[14];
	};

	struct in_addr{
		unsigned long s_addr;
	};
	
	struct sockaddr_in { 

		short int sin_family; // AF_INET 

		unsigned short sin_port; // Numero de puerto. 

		struct in_addr sin_addr; // Dirección IP. 

		unsigned char sin_zero[8]; // Relleno. 

	};

	void error(const char *msg){
		perror(msg);
		exit(0);
	};

/*-----------------------------VARIABLES-------------------------------------*/
	
	extern int errno;
	extern char *sys_errlist[];
	int sockfd;
	


 int main(int argc, char *argv[]) {
	
	int conexion, conexionEsi, puerto;
		
	
	char buffer[256];
	
	if (argc < 2){
		fprintf(stderr, "ERROR, No hay ningun puerto \n");
		exit(1);
	};
	
	struct sockaddr_in planificador, esi;
	struct hostent *server_host;

	
	conexion =socket (AF_INET, SOCK_STREAM, 0);
	
		if(conexion < 0){
			error("ERROR de apertura de socket \n");
		};
		
		puerto = atoi(argv[2]);
		
		
		planificador= gethostbyname(argv[1]);
		
		if(planificador == NULL){
			feprintf(stderr, "ERROR, no hay host \n");
			exit(0);
		};
		bzero((char *) &planificador, sizeof(planificador));

/*-----------------DATOS DEL SERVER---------------------------------------------*/	
	planificador.sin_family = AF_INET;
	planificador.sin_addr.s_addr = inet_addr("127.0.0.2");
	planificador.sin_port = htons(8001);
	
	
		if(bind (conexion, (struct sockaddr*)&planificador, sizeof(planificador)) <0){
			error("ERROR en la conexion");
		};
	
		listen(conexion, 5);
		esi_len = sizeof(esi);
		conexionEsi = accept(conexion, (struct sockaddr*)&esi, esi_len);
		
		if(conexionEsi < 0){
			error("ERROR en aceptar");
		};
	
		bzero (buffer,256); 

		n =read(conexionEsi, buffer, 255); 

		
		if (n <0){
			 error("Error al leer del socket");
			 };
			 
		n = write(conexionEsi,"Tengo el mensaje",18); 

		if (n <0){
			error("Error al escribir en el socket");
			};

 
  return 0;
   }
