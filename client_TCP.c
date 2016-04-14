/* Sample TCP client */

//I had edited it in the git
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char**argv){
	int sockfd,n;
	struct sockaddr_in servaddr;
	char banner[] = "Hello TCP server! This is TCP client";
	char buffer[1000];
	char* sendline;

	if (argc != 2){
		printf("usage: ./%s <IP address>\n",argv[0]);
		return -1;
	}

	/* socket to connect */
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	
	/* IP address information of the server to connect to */
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr=inet_addr(argv[1]);
	servaddr.sin_port=htons(32000);
	
	connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
	
	sendto(sockfd,banner,strlen(banner),0, (struct sockaddr*)&servaddr,sizeof(servaddr));
	n=recvfrom(sockfd,buffer,10000,0,NULL,NULL);
	buffer[n]=0;
	printf("Received:%s\n",buffer);
	
	printf("Enter the file you need to get: ");
	scanf("%s" , sendline );
	
	sendto(sockfd,sendline,strlen(sendline),0, (struct sockaddr*)&servaddr,sizeof(servaddr));
	return 0;
}
