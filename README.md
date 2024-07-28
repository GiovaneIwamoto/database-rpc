# DATABASE RPC

### **OVERVIEW**

This program is designed to interact with a remote database by making _remote procedure calls_ - _RPCs_. The client program facilitates user interaction and invokes functions on the remote database server. The _RPC_ client program allows users to perform basic operations on a remote database. The functionality includes:

[![Icons](https://skillicons.dev/icons?i=c,powershell,vscode&theme=dark)](https://skillicons.dev)

> [!IMPORTANT]
> For the proper functioning of the RPC client program, it is crucial for users to correctly install and configure the Portmap service. Portmap, also known as rpcbind, is a server that converts RPC program numbers into DARPA protocol port numbers. When an RPC service is initiated, it registers with the Portmap, which assigns it a port number and makes it accessible to remote clients. Without the Portmap service, RPC calls would fail to locate the appropriate service port, rendering the client-server communication impossible.

- **Initialization**: Initializes the connection with the remote server

- **Insertion**: Users can insert a word into the remote database

- **Search**: Users can search for a word in the remote database

- **Removal**: Users can remove a word from the remote database

### **INSTALLATION GUIDE**

```c
RPC generator:
$ rpcgen rbd.x
```

```java
Compile server:

$ gcc -o rbd_server rbd_sif.c rbd_svc.c rbd_srp.c rbd_xdr.c -I/usr/include/tirpc -ltirpc
```

```shell
Compile client:

$ gcc -o rbd_client rbd_clnt.c rbd_client.c rbd_xdr.c -I/usr/include/tirpc -ltirpc
$ gcc -o rbd_client rbd_cif.c rbd_clnt.c rbd_client.c rbd_xdr.c -I/usr/include/tirpc -ltirpc -fcommon
```

> [!WARNING]
> Users must ensure that the necessary ports are available and not in use by other applications. RPC communication relies on specific port numbers to establish connections between the client and server. If these ports are occupied or blocked by firewalls, the RPC client will be unable to communicate with the remote database server, leading to failed operations.

```ruby
Portmap error init service:
$ service portmap start

Install Portmap:
$ sudo apt install portmap

Linux and Debian-based distros use Rpcbind:
$ sudo systemctl start rpcbind
```
