CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = @rm -f 
BSRCS = bonus/client_bonus.c bonus/server_bonus.c
UTLS = srcs/utils.c
B_clt = client_bonus
B_srv = server_bonus
CLT = mandatory/client.c
SRV = mandatory/server.c
BCLT = bonus/client_bonus.c
BSRV = bonus/server_bonus.c

all : client server
	@echo "client && server created"

client : $(CLT)
		$(CC) $(CFLAGS) $(CLT) $(UTLS) -o $@

server : $(SRV)
		$(CC) $(CFLAGS)  -o $@ $(SRV) $(UTLS)

re : clean all bonus

bonus : $(B_clt) $(B_srv)
		@echo "Bonus created"

 $(B_srv) $(B_clt): $(BSRCS)
		$(CC) $(CFLAGS) -o $(B_clt) $(BCLT) $(UTLS)
		$(CC) $(CFLAGS) -o $(B_srv) $(BSRV) $(UTLS)
clean :
		$(RM) client server client_bonus server_bonus
		@echo "cleaned successfully"