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


/* --------------------FUNCIOMES------------------------------------  */
	int socket (int dominio, int tipo, int protocolo);
	int bind( int sockfd, struct sockaddr *my_addr, int addrlen);
//	int bind( sockfd, (struct sockaddr *) &sin, sizeof(sin));

	int listen(int sockfd, int backlog);
	int read();
	int write();
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
	
	int sockfd, newsockfd, portno;
		
	
	char buffer[256];
	
	if (argc < 2){
		fprintf(stderr, "ERROR, No hay ningun puerto \n");
		exit(1);
	};
	
	struct sockaddr_in server, cliente;
	struct hostent *server_host;

	
	sockfd =socket (AF_INET, SOCK_STREAM, 0);
	
		if(sockfd < 0){
			error("ERROR de apertura de socket \n");
		};
		
		portno = atoi(argv[2]);
		
		
		server= gethostbyname(argv[1]);
		
		if(seerver == NULL){
			feprintf(stderr, "ERROR, no hay host \n");
			exit(0);
		};
		bzero((char *) &server, sizeof(server));

/*-----------------DATOS DEL SERVER---------------------------------------------*/	
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons((short) portno);
	
	
		if(bind (sockfd, (struct sockaddr*)&server, sizeof(server)) <0){
			error("ERROR en la conexion");
		};
	
		listen(sockfd, 5);
		cliente_len = sizeof(cliente);
		newsockfd = accept(sockfd, (struct sockaddr*)&cliente, client_len);
		
		if(newsockfd 0){
			error("ERROR en aceptar");
		};
	
		bzero (buffer,256); 
		n =read(newsockfd,buffer,255); 
		
		if (n <0){
			 error("Error al leer del socket");}
			  else {
			  	printf("Aquí está el mensaje:% s ", Buffer);
			  	};
	
		n = write(newsockfd,"Tengo el mensaje",18); 
		if (n <0){
			error("Error al escribir en el socket");
			};
	
	
	
	
	
	/*
	
	bcopy(server_host -> h_addr, 
		&server.sin_addr, 
		server_host -> h_length);
	server.sin_port = htons((short) SERVER_PORT);
		
		
		gethostbyname()
		
	unsigned long int red, host;
	unsigned short int red, host;
	red=htonl (host);
	red=htons (host);
	host=ntohl (red);
	host=ntohs (red);	

	struct sockaddr_in sin;
	sin.sin_family = AF_INET;
	sin.sin_port = htons(1234);
	sin.sin_addr.s_addr = inet_addr("132.241.5.10");
	


 	printf("Hello, Dcoder!");*/
 	return 0;
 }