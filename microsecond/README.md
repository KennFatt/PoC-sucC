# Microsecond
Machine information:
```
os: Linux 5.2.3 (64-bit)
cc: gcc 9.10
glibc: 2.29
d_flags: ~
c_flags: ~
editor: vscode
compiler util: make 4.2.1-3
```

Nothing tricky on compilation and nothing special on the source code.  
You have to take attention on my glibc. It has 2.29 version, you might need to use either `-D_BSD_SOURCE` or `-D_DEFAULT_SOURCE` to make it working in some older glibc version. Thanks.