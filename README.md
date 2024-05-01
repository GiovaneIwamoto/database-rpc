# DATABASE RPC

### **OVERVIEW**

This program is designed to interact with a remote database by making *remote procedure calls* - *RPCs*. The client program facilitates user interaction and invokes functions on the remote database server. The *RPC* client program allows users to perform basic operations on a remote database. The functionality includes:

 - **Initialization**: Initializes the connection with the remote server

 - **Insertion**: Users can insert a word into the remote database

 - **Search**: Users can search for a word in the remote database

 - **Removal**: Users can remove a word from the remote database


### **INSTALLATION GUIDE**
```
RPC generator:
$ rpcgen rbd.x
```

```
Compile server:

$ gcc -o rbd_server rbd_sif.c rbd_svc.c rbd_srp.c rbd_xdr.c -I/usr/include/tirpc -ltirpc
```


```
Compile client:

$ gcc -o rbd_client rbd_clnt.c rbd_client.c rbd_xdr.c -I/usr/include/tirpc -ltirpc
$ gcc -o rbd_client rbd_cif.c rbd_clnt.c rbd_client.c rbd_xdr.c -I/usr/include/tirpc -ltirpc -fcommon 
```

```
Portmap error init service:
$ service portmap start
  
Install Portmap:
$ sudo apt install portmap

Linux and Debian-based distros use Rpcbind:
$ sudo systemctl start rpcbind
```