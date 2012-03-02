/* Name:  M. Andrew Webster
 * Based on stevens networking book
 * Description: function prototypes for socket library
 */

#ifndef _SOCKETLIB_H
#define _SOCKETLIB_H

#ifdef WIN32
#include <winsock2.h>
#include <sys/time.h>
typedef int socklen_t;
typedef struct addrinfo {
  int             ai_flags;
  int             ai_family;
  int             ai_socktype;
  int             ai_protocol;
  size_t          ai_addrlen;
  char            *ai_canonname;
  struct sockaddr  *ai_addr;
  struct addrinfo  *ai_next;
};
#define AI_PASSIVE     1
#define EAFNOSUPPORT   WSAEAFNOSUPPORT
#define SIGPIPE 13
#define INET6_ADDRSTRLEN       46
#define IN6ADDR_ANY_INIT { { { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 } } }
struct in6_addr {
  union {
    u_char Byte[16];
    u_short Word[8];
  } u;
};
const struct in6_addr in6addr_any = IN6ADDR_ANY_INIT;

struct sockaddr_in6 {
  short sin6_family;
  u_short sin6_port;
  u_long sin6_flowinfo;
  struct in6_addr sin6_addr;
  u_long sin6_scope_id;
};
#else
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>
#endif


#define  MAX_SIZE 8192
#define  PORT 5000
#define  RETRY_COUNT 7
#define  SERVLEN 80
#define  RETRY_DELAY 1000

#define ERROR -1
#define DEFAULT_IP "127.0.0.1"
#define DEFAULT_UNIX "/unix"

int setup_client(struct addrinfo *server_info);
int setup_server(struct addrinfo *server_address);
int setupListenServer(struct addrinfo **pAddrInfo, int pPort);
int acceptClient(int pSock, struct addrinfo *server_addr);
void delay(long pMillisecs, struct timeval *pRes);
int getAddr(char *pHostname, char *pService, int pFamily, int pSockType, struct addrinfo **pAddrInfo);

// All calls to decode and encode need to be freed
char *decode_base64(unsigned char *input, int length, int *tActualLength);
// All calls to decode and encode need to be freed
char *encode_base64(unsigned char *input, int length);


#endif
