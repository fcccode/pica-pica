//коды сообщений протокола и структура сообщения

#ifndef PICA_PROTO_H
#define PICA_PROTO_H


#define PICA_PROTO_VER_HIGH 0
#define PICA_PROTO_VER_LOW 5

#define PICA_C2CPROTO_VER_HIGH 0
#define PICA_C2CPROTO_VER_LOW 1

#define PICA_PROTO_CLIENT_VER_STRING PICA_STRINGIFY2(PICA_C2CPROTO_VER_HIGH, PICA_C2CPROTO_VER_LOW)
#define PICA_PROTO_VER_STRING PICA_STRINGIFY2(PICA_PROTO_VER_HIGH, PICA_PROTO_VER_LOW)
#define PICA_STRINGIFY2(H, L) PICA_STRINGIFY(H, L)
#define PICA_STRINGIFY(H, L) #H#L

#define PICA_PROTO_INITREQ 0xCA
#define PICA_PROTO_INITRESPOK 0x01
#define PICA_PROTO_VERDIFFER 0x02

#define PICA_PROTO_CONNREQOUTG 0x03
#define PICA_PROTO_CONNREQINC 0x04
#define PICA_PROTO_NOTFOUND 0x05
#define PICA_PROTO_CONNALLOW 0x06
#define PICA_PROTO_FOUND 0x07
#define PICA_PROTO_CONNDENY 0x08
#define PICA_PROTO_CLNODELISTREQ 0x09
#define PICA_PROTO_CLNODELIST 0x0A

#define PICA_PROTO_CONNID 0x20

#define PICA_PROTO_C2CCONNREQ 0xCC

#define PICA_PROTO_DIRECTC2C_ADDRLIST 0x0B
#define PICA_PROTO_DIRECTC2C_IPV4 0xA0
#define PICA_PROTO_DIRECTC2C_IPV6 0xA1
#define PICA_PROTO_DIRECTC2C_DNS 0xA2
#define PICA_PROTO_DIRECTC2C_FAILED 0x0C
#define PICA_PROTO_DIRECTC2C_SWITCH 0x0D

#define PICA_PROTO_MSGUTF8 0x30
#define PICA_PROTO_MSGOK 0x40
#define PICA_PROTO_SENDFILEREQUEST 0x50
#define PICA_PROTO_ACCEPTEDFILE 0x51
#define PICA_PROTO_DENIEDFILE 0x52
#define PICA_PROTO_FILEFRAGMENT 0x53
#define PICA_PROTO_FILECONTROL 0x54

#define PICA_PROTO_FILECONTROL_VOID 0
#define PICA_PROTO_FILECONTROL_PAUSE 1
#define PICA_PROTO_FILECONTROL_RESUME 2
#define PICA_PROTO_FILECONTROL_CANCEL 3
#define PICA_PROTO_FILECONTROL_IOERROR 4

#define PICA_PROTO_PINGREQ 0x68
#define PICA_PROTO_PINGREP 0x69

#define PICA_PROTO_NODECONNREQ 0xCB

#define PICA_PROTO_NEWNODE_IPV4 0xA0
#define PICA_PROTO_NEWNODE_IPV6 0xA1
#define PICA_PROTO_NEWNODE_DNS 0xA2

#define PICA_PROTO_NODELIST 0xA4
#define PICA_PROTO_NODELISTREQ 0x90

#define PICA_PROTO_SEARCH 0xA5
#define PICA_PROTO_N2NFOUND 0xA8
#define PICA_PROTO_N2NFOUNDCACHE 0xA9
#define PICA_PROTO_N2NCONNREQOUTG 0xAA
#define PICA_PROTO_N2NALLOW 0xAB
#define PICA_PROTO_N2NNOTFOUND 0xB8
#define PICA_PROTO_N2NMSG 0xD0


//size
#define PICA_PROTO_INITREQ_SIZE 4
#define PICA_PROTO_INITRESPOK_SIZE 4
#define PICA_PROTO_VERDIFFER_SIZE 4

#define PICA_PROTO_CONNREQOUTG_SIZE 30
#define PICA_PROTO_CONNREQINC_SIZE 30
#define PICA_PROTO_NOTFOUND_SIZE 30
#define PICA_PROTO_CONNALLOW_SIZE 30
#define PICA_PROTO_FOUND_SIZE 30
#define PICA_PROTO_CONNDENY_SIZE 30
#define PICA_PROTO_CLNODELISTREQ_SIZE 4

#define PICA_PROTO_CONNID_SIZE 58

#define PICA_PROTO_C2CCONNREQ_SIZE 4
#define PICA_PROTO_DIRECTC2C_ADDRLIST_ITEM_IPV4_SIZE 7
#define PICA_PROTO_DIRECTC2C_ADDRLIST_ITEM_IPV6_SIZE 19
#define PICA_PROTO_DIRECTC2C_FAILED_SIZE 4
#define PICA_PROTO_DIRECTC2C_SWITCH_SIZE 4

#define PICA_PROTO_MSGOK_SIZE 4

#define PICA_PROTO_ACCEPTEDFILE_SIZE 4
#define PICA_PROTO_DENIEDFILE_SIZE 4
#define PICA_PROTO_FILECONTROL_SIZE 4

#define PICA_PROTO_PINGREQ_SIZE 4
#define PICA_PROTO_PINGREP_SIZE 4

#define PICA_PROTO_NODECONNREQ_SIZE 4

#define PICA_PROTO_NEWNODE_IPV4_SIZE 8
#define PICA_PROTO_NEWNODE_IPV6_SIZE 20

#define PICA_PROTO_NODELIST_ITEM_IPV4_SIZE 7
#define PICA_PROTO_NODELIST_ITEM_IPV6_SIZE 19


#define PICA_PROTO_NODELISTREQ_SIZE 4

#define PICA_PROTO_SEARCH_SIZE 30
#define PICA_PROTO_N2NFOUND_SIZE 30
#define PICA_PROTO_N2NCONNREQOUTG_SIZE 58
#define PICA_PROTO_N2NALLOW_SIZE 58
#define PICA_PROTO_N2NNOTFOUND_SIZE 58

#define PICA_PROTO_N2NMSG_MAXDATASIZE 65476
#define PICA_PROTO_C2CMSG_MAXDATASIZE 65532
#define PICA_PROTO_C2CMSG_MAXFILENAMESIZE 255


struct PICA_proto_msg
{
	unsigned char head[2];
	unsigned char tail[0];
};




#endif

