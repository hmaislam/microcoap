#all:
#	gcc -Wall -o coap endpoints.c main-posix.c coap.c -DDEBUG

#clean:
#	rm -f coap
MODULE:=$(shell basename $(CURDIR))

INCLUDES += -I$(RIOTBASE) -I$(RIOTBASE)/sys/include -I$(RIOTBASE)/core/include -I$(RIOTBASE)/drivers/include -I$(RIOTBASE)/drivers/cc110x_legacy/include -I$(RIOTBASE)/cpu/arm7_common/include -I$(RIOTBASE)/sys/net/transport_layer/include -I$(RIOTBASE)/sys/net/sixlowpan/include/ -I$(RIOTBASE)/sys/net/ieee802154/include -I$(RIOTBASE)/sys/net/net_help -I$(RIOTBASE)/sys/posix/include -I$(RIOTBASE)/sys/posix/pnet/include
CFLAGS += -DWITH_POSIX

include $(RIOTBASE)/Makefile.base
